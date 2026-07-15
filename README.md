# ELF Parser

A simple ELF64 parser written in C to understand how Linux executables are structured.

This project was built as a learning exercise in systems programming and reverse engineering. Instead of relying on `<elf.h>`, the parser manually defines the ELF header structure and extracts information directly from the binary file.

## Features

* Validate ELF files using the ELF magic number
* Parse the ELF identification (`e_ident`) fields:

  * Class (ELF32 / ELF64)
  * Endianness
  * ELF Version
  * OS ABI
* Parse ELF header fields:

  * File Type
  * Machine Architecture
  * Entry Point
  * Program Header Offset
  * Section Header Offset
  * ELF Header Size
  * Program Header Entry Size
  * Program Header Count
  * Section Header Entry Size
  * Section Header Count
  * Section Name String Table Index
* Support parsing multiple files from the command line
* Handle invalid files and I/O errors gracefully

## Example

```bash
$ ./elf-parser /bin/ls

File: /bin/ls
✓ Valid ELF file
Class: ELF64
Endian: Little Endian
Version: Current
OS ABI: System V
Type: ET_DYN (Shared object or PIE executable)
Machine: AMD x86-64
Entry point: 0x6760
Program Header Offset: 64 bytes
Section Header Offset: 156712 bytes
ELF Header Size: 64
Program Header Entry Size: 56
Program Header Count: 14
Section Header Entry Size: 64
Section Header Count: 30
Section Name String Table Index: 29
```

## Building

```bash
gcc -Wall -Wextra main.c -o elf-parser
```

## Usage

```bash
./elf-parser <elf_file> [elf_file...]
```

Example:

```bash
./elf-parser /bin/ls /bin/bash
```

## Why I Built This

The goal of this project was to learn how ELF binaries are laid out on disk and strengthen my understanding of:

* Binary file parsing
* C structures (`struct`)
* Fixed-width integer types (`stdint.h`)
* File I/O (`fopen`, `fread`)
* Linux executable internals

Rather than using existing parsing libraries, I implemented the parsing logic manually to better understand the ELF format.

## Future Improvements

* Parse the Program Header Table
* Parse the Section Header Table
* Display section names
* Parse symbol tables
* Parse dynamic linking information
