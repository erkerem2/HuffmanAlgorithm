# HuffmanAlgorithm
## Overview
This project is an implementation of the Huffman coding algorithm, applied to create a lossless data compression and encryption system. It was developed as a part of the coursework for Data Structures.

## Features
- Custom implementation of the Huffman algorithm.
- No use of STL containers as per assignment requirements.
- Priority queue and tree data structures for Huffman coding.
- Encoding and decoding functionalities for passwords using Huffman tree.

## Getting Started

### Prerequisites
- Linux environment for compilation and execution.
- Docker's Virtual Environment for testing (recommended).

### Compilation and Running
```bash
g++ -Wall -Werror src/main.cpp src/structs.cpp src/huffman.cpp -I include -o main
./main key1.txt
```

Project Structure
/bin - Contains compiled binaries.
/include - Header files for the project.
/src - Source files for the Huffman implementation and main application.
key1.txt, key2.txt - Example keys for encoding/decoding.
