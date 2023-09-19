# flatbuffer
flat buffer streaming encoder (cpp) &amp; decoder (cpp &amp; python)

***Solution Description:***

1. *fb_encoder:* Always precedes a Person or Group message with a header message. The header contains two fields: `msg_length` and `Type` to identify the type and length of the next message.
2. *fb_decoder:* Reads the fixed-length header first and then, using the `msg_length` and `Type` information from the header, reads the actual Person or Group message and prints its content.

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

**Schema file:** client.fbs

enum Gender: ubyte {
  Male = 0,
  Female = 1,
}

enum Type: ushort {
  Invalid = 0,
  Person = 1,
  Group = 2,
}

table Header {
  msg_len: int32;
  msg_type: Type;
}

table Group {
  group_name: string;
  average_age: ushort;
  average_weight: float32;
  names: [string];
}

table Person {
  name: string;
  age: ushort;
  weight: float32;
  gender: Gender;
}

root_type Header;

**List of auto generated c++ (header) source code using flatc compiler:**

client_generated.h

**List of auto generated python source code using flatc compiler:**

Gender.py
Group.py
Header.py
Person.py
Type.py

***Future Scope & Improvements:***

1. The current version prioritizes functionality over low latency and has room for further optimization.
2. The code doesn't handle edge cases, such as incomplete header or message reception in streaming TCP protocols. It should buffer a portion of the header or message and process it once the complete message is received.
3. Similar streaming solutions can be adapted for TCP or UDP.
4. There is potential for further design improvements.

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
Group: WWE, 
Average Age: 36, 
Average Weight: 71 
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
Group: WWE, 
Average Age: 38, 
Average Weight: 73 
Names: Rock Khali 
--Header-- 
Message Length: 44 
Message Type: Person 
--Person-- 
Person Name: John 
Person Age: 34 
Person Weight: 74.5 
Person Gender: Male 
