#include "flatbuffers/flatbuffers.h"
#include "client_generated.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

// Base class for message handlers
class MessageHandler {
public:
    virtual void HandleMessage(int i, flatbuffers::FlatBufferBuilder& header_builder, flatbuffers::FlatBufferBuilder& message_builder, std::ofstream& outfile) = 0;
};

// Class for Type_Person message handling
class PersonMessageHandler : public MessageHandler {
public:
    void HandleMessage(int i, flatbuffers::FlatBufferBuilder& header_builder, flatbuffers::FlatBufferBuilder& person_builder, std::ofstream& outfile) override {
        // Clear the message builders before use
        header_builder.Clear();
        person_builder.Clear();

        // Sample Person data with different values at each iteration
	std::string name = "John";
        uint16_t age = 30 + i;
        float weight = 70.5f + i;
        Gender gender = static_cast<Gender>(i % 2);

        // Create a Person object for the message
        auto name_offset = person_builder.CreateString(name);
        auto person_offset = CreatePerson(
            person_builder,
            name_offset,
            age,
            weight,
            gender);

        person_builder.Finish(person_offset);

        // Create Header with different values at each iteration
        auto header_offset = CreateHeader(header_builder, person_builder.GetSize(), Type_Person);
        header_builder.Finish(header_offset);
        
	outfile.write(reinterpret_cast<const char*>(header_builder.GetBufferPointer()), header_builder.GetSize());
        outfile.write(reinterpret_cast<const char*>(person_builder.GetBufferPointer()), person_builder.GetSize());
        std::cout << "Person size " << person_builder.GetSize() << std::endl;
    }
};

// Class for Type_Group message handling
class GroupMessageHandler : public MessageHandler {
public:
    void HandleMessage(int i, flatbuffers::FlatBufferBuilder& header_builder, flatbuffers::FlatBufferBuilder& group_builder, std::ofstream& outfile) override {
        // Clear the message builders before use
        header_builder.Clear();
        group_builder.Clear();


        auto group_name = group_builder.CreateString("WWE");
        std::vector<flatbuffers::Offset<flatbuffers::String>> group_names;
        group_names.push_back(group_builder.CreateString("Rock"));
        group_names.push_back(group_builder.CreateString("Khali"));
        auto group = CreateGroup(group_builder, group_name, 35 + i, 70.0f + i, group_builder.CreateVector(group_names));
        group_builder.Finish(group);
        
	// Create Header with different values at each iteration
        auto header_offset = CreateHeader(header_builder, group_builder.GetSize(), Type_Group);
        header_builder.Finish(header_offset);
        
	outfile.write(reinterpret_cast<const char*>(header_builder.GetBufferPointer()), header_builder.GetSize());
        outfile.write(reinterpret_cast<const char*>(group_builder.GetBufferPointer()), group_builder.GetSize());

        std::cout << "Group size " << group_builder.GetSize() << std::endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <output_file_name>" << std::endl;
        return 1;
    }

    std::string outputFileName = argv[1];

    // Create FlatBuffer builders for header and messages
    flatbuffers::FlatBufferBuilder header_builder;
    flatbuffers::FlatBufferBuilder message_builder;

    // Open the binary file in append mode
    std::ofstream outfile(outputFileName, std::ios::binary | std::ios::app);
    if (!outfile) {
        std::cerr << "Error: Cannot open file for writing." << std::endl;
        return 1;
    }

    for (int i = 0; i < 10; ++i) {
        // Toggle between Type_Person and Type_Group in each iteration
        Type header_type = (i % 2 == 0) ? Type_Person : Type_Group;

        // Create instances of message handlers
        std::unique_ptr<MessageHandler> messageHandler;
        if (header_type == Type_Person) {
            messageHandler = std::make_unique<PersonMessageHandler>();
        } else if (header_type == Type_Group) {
            messageHandler = std::make_unique<GroupMessageHandler>();
        }

        // Call the appropriate message handler
        messageHandler->HandleMessage(i, header_builder, message_builder, outfile);
    }

    outfile.close();

    std::cout << "Encoded header and person messages to " << outputFileName << std::endl;

    return 0;
}

