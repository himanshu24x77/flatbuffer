#include "flatbuffers/flatbuffers.h"
#include "client_generated.h"
#include <iostream>
#include <fstream>
#include <vector>

// Define event handler interface
class EventHandler {
public:
    virtual void HandleEvent(const uint8_t* data, size_t size) = 0;
};

// Event handler for Header
class HeaderHandler : public EventHandler {
public:
    void HandleEvent(const uint8_t* data, size_t size) override {
        flatbuffers::Verifier verifier(data, size);
        if (!VerifyHeaderBuffer(verifier)) {
            std::cerr << "Error: Invalid header in the binary data." << std::endl;
            return;
        }

        auto header = GetHeader(data);

        // Print Header values
        std::cout << "--Header--" << std::endl;
        std::cout << "Message Length: " << header->msg_len() << std::endl;
        std::cout << "Message Type: " << EnumNameType(header->msg_type()) << std::endl;
    }
};

// Event handler for Person
class PersonHandler : public EventHandler {
public:
    void HandleEvent(const uint8_t* data, size_t size) override {
        const Person* person = flatbuffers::GetRoot<Person>(data);

        std::cout << "--Person--" << std::endl;
        std::cout << "Person Name: " << person->name()->c_str() << std::endl;
        std::cout << "Person Age: " << person->age() << std::endl;
        std::cout << "Person Weight: " << person->weight() << std::endl;
        std::cout << "Person Gender: " << EnumNameGender(person->gender()) << std::endl;
    }
};

// Event handler for Group
class GroupHandler : public EventHandler {
public:
    void HandleEvent(const uint8_t* data, size_t size) override {
        const Group* group = flatbuffers::GetRoot<Group>(data);

        std::cout << "--Group--" << std::endl;
        std::cout << "Group: " << group->group_name()->c_str() << ", Average Age: " << group->average_age()
            << ", Average Weight: " << group->average_weight() << std::endl;
        std::cout << "Names: ";
        for (size_t j = 0; j < group->names()->size(); ++j) {
            std::cout << group->names()->Get(j)->c_str() << ", ";
        }
        std::cout << std::endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <binary_file>" << std::endl;
        return 1;
    }

    // Read the binary data from the file
    const char* filename = argv[1];
    std::ifstream infile(filename, std::ios::binary);
    if (!infile) {
        std::cerr << "Error: Cannot open file for reading: " << filename << std::endl;
        return 1;
    }

    int32_t header_size = 24;
    std::vector<uint8_t> buffer(header_size);

    // Create event handlers
    HeaderHandler headerHandler;
    PersonHandler personHandler;
    GroupHandler groupHandler;

    while (true) {
        // Read the entire binary data into a buffer
        infile.read(reinterpret_cast<char*>(buffer.data()), header_size);

        if (infile.eof()) {
            std::cerr << "Reached the end of the file." << std::endl;
            break;
        }

        // Dispatch events based on message type
        auto header = GetHeader(buffer.data());
        headerHandler.HandleEvent(buffer.data(), header_size);

        // Read the actual message data
        size_t message_size = header->msg_len();
        std::vector<uint8_t> message_buffer(message_size);
        infile.read(reinterpret_cast<char*>(message_buffer.data()), message_size);

        if (header->msg_type() == Type_Person) {
            personHandler.HandleEvent(message_buffer.data(), message_size);
        } else if (header->msg_type() == Type_Group) {
            groupHandler.HandleEvent(message_buffer.data(), message_size);
        }
    }

    infile.close();

    return 0;
}

