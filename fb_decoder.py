import sys
import struct
import flatbuffers
import Header, Person, Group, Gender, Type

# event handler interface
class EventHandler:
    def handle_event(self, data, size):
        pass

# Event handler for Header
class HeaderHandler(EventHandler):
    def handle_event(self, data, size):
        header = Header.Header.GetRootAsHeader(data, 0)

        print("--Header--")
        print("Message Length:", header.MsgLen())
        print("Message Type:", header.MsgType())

# Event handler for Person
class PersonHandler(EventHandler):
    def handle_event(self, data, size):
        person = Person.Person.GetRootAsPerson(data, 0)

        print("--Person--")
        print("Person Name:", person.Name().decode('utf-8'))
        print("Person Age:", person.Age())
        print("Person Weight:", person.Weight())
        print("Person Gender:", person.Gender())

# Event handler for Group
class GroupHandler(EventHandler):
    def handle_event(self, data, size):
        group = Group.Group.GetRootAsGroup(data, 0)

        print("--Group--")
        print("Group:", group.GroupName().decode('utf-8'), "Average Age:", group.AverageAge(), "Average Weight:", group.AverageWeight())
        print("Names:", end=' ')
        for i in range(group.NamesLength()):
            print(group.Names(i).decode('utf-8'), ", " , end=' ')
        print()

def main():
    if len(sys.argv) != 2:
        print("Usage:", sys.argv[0], "<binary_file>")
        return 1

    # Read the binary data from the file
    filename = sys.argv[1]
    try:
        with open(filename, 'rb') as infile:
            header_size = 24
            buffer = infile.read(header_size)
            headerHandler = HeaderHandler()
            personHandler = PersonHandler()
            groupHandler = GroupHandler()

            while buffer:

                header = Header.Header.GetRootAsHeader(buffer, 0)
                headerHandler.handle_event(buffer, header_size)

                message_size = header.MsgLen()
                message_buffer = infile.read(message_size)

                if header.MsgType() == Type.Type.Person:
                    personHandler.handle_event(message_buffer, message_size)
                elif header.MsgType() == Type.Type.Group:
                    groupHandler.handle_event(message_buffer, message_size)

                buffer = infile.read(header_size)

    except FileNotFoundError:
        print("Error: Cannot open file for reading:", filename)
        return 1

if __name__ == "__main__":
    sys.exit(main())

