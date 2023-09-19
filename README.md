# flatbuffer
flat buffer streaming encoder (cpp) &amp; decoder (cpp &amp; python)

**Solution Description:**

1. fb_encoder: It always writes a header message as a seperator before writing a Person or Group message. Header message contains two fields i.e msg_length & Type to identify type & msg_length of next message to be read.
2. fb_decoder: It reads fixed length header first and then using msg_length & type info from header it reads actual Person or Group message & print the content.

**Instructions:**

**_A. How to compile & run flat buffer encoder:_**

1. To compile fb_encoder.cpp ->     g++ -g -o fb_encoder fb_encoder.cpp -I .
2. To run ->                        ./fb_encoder data.bin

**_B. How to compile & run flat buffer decoder (cpp):_**

1. To compile fb_decoder.cpp ->     g++ -g -o fb_decoder fb_decoder.cpp -I .
2. To run ->                        ./fb_decoder data.bin

**_C. How to run flat buffer decoder (python):_**
 .
1. To run ->                        python3.9 fb_decoder.py data.bin

**Schema file:**
client.fbs

**List of auto generated c++ (header) source code using flatc compiler:**

client_generated.h

**List of auto generated python source code using flatc compiler:**

Gender.py
Group.py
Header.py
Person.py
Type.py


**Future Scope & Improvements:**

1. Current version is not optimized for low latency and focused more on functionality, it has a lot of scope can be optimized further.
2. Code doesn't not handle edge cases, for example in streaming TCP protocol we might not receive complete header or actual message (Person/Group) but receive only a fraction, this case needs to be handled by buffering a part of Header or actual message (Person/Group) and processes it once we receive complete message.
3. Similar streaming solutions can be ported to TCP or UDP.
4. Further design improvements.


**Output (Decoder) | Once you run fb_decoder (c++ or python), you should be able to see below decoder logs :**

--Header--
Message Length: 44
Message Type: Person
--Person--
Person Name: John
Person Age: 30
Person Weight: 70.5
Person Gender: Male
--Header--
Message Length: 80
Message Type: Group
--Group--
Group: WWE, Average Age: 36, Average Weight: 71
Names: Rock Khali 
--Header--
Message Length: 44
Message Type: Person
--Person--
Person Name: John
Person Age: 32
Person Weight: 72.5
Person Gender: Male
--Header--
Message Length: 80
Message Type: Group
--Group--
Group: WWE, Average Age: 38, Average Weight: 73
Names: Rock Khali 
--Header--
Message Length: 44
Message Type: Person
--Person--
Person Name: John
Person Age: 34
Person Weight: 74.5
Person Gender: Male
--Header--
Message Length: 80
Message Type: Group
--Group--
Group: WWE, Average Age: 40, Average Weight: 75
Names: Rock Khali 
--Header--
Message Length: 44
Message Type: Person
--Person--
Person Name: John
Person Age: 36
Person Weight: 76.5
Person Gender: Male
--Header--
Message Length: 80
Message Type: Group
--Group--
Group: WWE, Average Age: 42, Average Weight: 77
Names: Rock Khali 
--Header--
Message Length: 44
Message Type: Person
--Person--
Person Name: John
Person Age: 38
Person Weight: 78.5
Person Gender: Male
--Header--
Message Length: 80
Message Type: Group
--Group--
Group: WWE, Average Age: 44, Average Weight: 79
Names: Rock Khali 
Reached the end of the file.
