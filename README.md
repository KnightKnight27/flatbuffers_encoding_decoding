# flatbuffers_encoding_decoding
# FlatBuffers Usage Guide

![FlatBuffers Logo](https://github.com/google/flatbuffers/raw/master/docs/Images/FlatBuffers.png)

This guide provides step-by-step instructions on how to use FlatBuffers for C++ and Python. FlatBuffers is an efficient cross-platform serialization library that can be used to serialize data in a binary format.

## Prerequisites

Before you begin, make sure you have the following prerequisites installed on your system:

- Git
- CMake
- g++
- Python (Python 3 recommended)

## Getting Started
1. **Clone the FlatBuffers Repository:**
   ```bash
   git clone https://github.com/google/flatbuffers.git
2. **Use CMAKE:**
   ```bash
   cd flatbuffers && cmake -G "Unix Makefiles"
3. 
   ```bash
   cd flatbuffers && make
4. 
   ```bash
   cd flatbuffers && sudo ln -s /content/flatbuffers/flatc /usr/local/bin/flatc
5. 
   ```bash
   cd flatbuffers && chmod +x /content/flatbuffers/flatc
6. Make the c++ headers for corresponding schema file.
   ```bash
   flatc -c client.fbs
7. g++ command to compile encrypt.cpp file and execute it 
   ```bash
   g++ -I flatbuffers/include -o e encrypt.cpp && ./e 
8. Make Python generated files for it's client.fbs
   ```bash
   flatc --python client.fbs 
9. Decoder to read/deserialize the bytes.
   ```bash
   python decoder.py 
