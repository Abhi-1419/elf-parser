#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
struct ELF_Header
{
    uint8_t  e_ident[16];

    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;

    uint64_t e_entry;
    uint64_t e_phoff;
    uint64_t e_shoff;

    uint32_t e_flags;

    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;

    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
};

int main(int argc, char *argv[])

{
if (argc < 2)
{
    printf("Usage: %s <elf_file> [elf_file...]\n", argv[0]);
    return 1;
}
   for (int i = 1; i < argc; i++){
FILE *fp = fopen(argv[i], "r");
struct ELF_Header elf;
if (fp == NULL)
{
    perror(argv[i]);
continue;

}


size_t bytes_read = fread(&elf, sizeof(elf), 1, fp);

if(bytes_read != 1){
printf("File: %s\n", argv[i]);
printf("Could not read ELF header\n");
fclose(fp);
continue;}

if(elf.e_ident[0] == 0x7F && 

elf.e_ident[1] == 'E' && 

elf.e_ident[2] == 'L' && 

elf.e_ident[3] == 'F' ){ 
printf("File: %s\n", argv[i]);
printf("✓ Valid ELF file\n");}
else{
printf("File: %s\n", argv[i]);
 printf("✗ Not an ELF file\n");
fclose(fp); 
 continue;}

switch (elf.e_ident[4])
{
    case 1:
        printf("Class: ELF32\n");
        break;

    case 2:
        printf("Class: ELF64\n");
        break;

    default:
        printf("Class: Unknown\n");
        break;
}



switch (elf.e_ident[5])
{
    case 1:
        printf("Endian: Little Endian\n");
        break;

    case 2:
        printf("Endian: Big Endian\n");
        break;

    default:
        printf("Endian: Unknown\n");
        break;
}
switch (elf.e_ident[6])
{
    case 0:
        printf("Version: Invalid\n");
        break;

    case 1:
        printf("Version: Current\n");
        break;

    default:
        printf("Version: Unknown (%u)\n", elf.e_ident[6]);
        break;
}

switch (elf.e_ident[7])
{
    case 0:
        printf("OS ABI: System V\n");
        break;

    case 3:
        printf("OS ABI: Linux\n");
        break;

    default:
        printf("OS ABI: Unknown (%u)\n", elf.e_ident[7]);
        break;
}

switch (elf.e_type)
{
    case 1:
        printf("Type: Relocatable object (.o)\n");
        break;

    case 2:
        printf("Type: Executable\n");
        break;

    case 3:
         printf("Type: ET_DYN (Shared object or PIE executable)\n");
        break;

    case 4:
        printf("Type: Core dump\n");
        break;

    default:
        printf("Type: Unknown\n");
        break;
}

switch (elf.e_machine)
{
    case 3:
        printf("Machine: x86\n");
        break;

    case 40:
        printf("Machine: ARM\n");
        break;

    case 62:
        printf("Machine: AMD x86-64\n");
        break;

    case 183:
        printf("Machine: AArch64\n");
        break;

    case 243:
        printf("Machine: RISC-V\n");
        break;

    default:
        printf("Machine: Unknown (%u)\n", elf.e_machine);
        break;
}
printf("Entry point: 0x%lX\n", elf.e_entry);
printf("Program Header Offset: %lu bytes\n", elf.e_phoff);
printf("Section Header Offset: %lu bytes\n", elf.e_shoff);
printf("Program Header Offset: %lu\n", elf.e_phoff);
printf("Section Header Offset: %lu\n", elf.e_shoff);
printf("ELF Header Size: %u\n", elf.e_ehsize);
printf("Program Header Entry Size: %u\n", elf.e_phentsize);
printf("Program Header Count: %u\n", elf.e_phnum);
printf("Section Header Entry Size: %u\n", elf.e_shentsize);
printf("Section Header Count: %u\n", elf.e_shnum);
printf("Section Name String Table Index: %u\n", elf.e_shstrndx);
printf("\n");
fclose(fp);  

}
    return 0;
}
