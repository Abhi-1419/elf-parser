# ELF Parser

A command-line ELF parser written in C to understand how Linux executables are structured. The project focuses on learning binary formats, low-level file parsing, and systems programming without relying on high-level parsing libraries.

## Features

* Parse one or more files from the command line
* Open and validate input files
* Read the first 16 bytes of an ELF file (`e_ident`)
* Display raw ELF header bytes in hexadecimal
* Graceful error handling with `perror()`
* Clean resource management using `fopen()` and `fclose()`

## Concepts Practiced

* Command-line arguments (`argc` / `argv`)
* File I/O (`fopen`, `fread`, `fclose`)
* Arrays and pointers
* Binary file parsing
* Hexadecimal representation
* Error handling
* Looping through multiple input files

## Build

```bash
gcc -Wall -Wextra main.c -o elf-parser
```

## Usage

```bash
./elf-parser /bin/ls
```

Parse multiple files:

```bash
./elf-parser /bin/ls /bin/bash
```

## Example Output

```text
File: /bin/ls
7F 45 4C 46 02 01 01 00 00 00 00 00 00 00 00 00

File: /bin/bash
7F 45 4C 46 02 01 01 00 00 00 00 00 00 00 00 00
```

## Roadmap

* [x] Command-line argument parsing
* [x] Open multiple files
* [x] Read ELF identification bytes (`e_ident`)
* [x] Print ELF header bytes in hexadecimal
* [ ] Validate the ELF magic number
* [ ] Decode ELF class (32-bit / 64-bit)
* [ ] Decode endianness
* [ ] Parse the complete ELF header
* [ ] Parse Program Headers
* [ ] Parse Section Headers
* [ ] Display the entry point address
* [ ] List ELF sections
* [ ] List imported shared libraries
* [ ] Refactor into multiple source files

## Learning Goal

This project is part of my journey into systems programming, reverse engineering, binary exploitation, and Linux internals. Rather than relying on existing tools, the goal is to understand the ELF format by parsing it manually, one field at a time.
