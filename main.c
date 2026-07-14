
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
if (argc < 2)
{
    printf("Usage: %s <elf_file> [elf_file...]\n", argv[0]);
    return 1;
}
   for (int i = 1; i < argc; i++){
FILE *fp = fopen(argv[i], "r");
unsigned char header[16];

if (fp == NULL)
{
    perror(argv[i]);
continue;

}


size_t bytes_read=fread(header, 1, 16, fp);

if(bytes_read != 16){
printf("File: %s\n", argv[i]);
printf("Could not read ELF header\n");
fclose(fp);
continue;}

if(header[0] == 0x7F && 

header[1] == 'E' && 

header[2] == 'L' && 

header[3] == 'F' ){ 
printf("File: %s\n", argv[i]);
printf("✓ Valid ELF file\n");}
else{
printf("File: %s\n", argv[i]);
 printf("✗ Not an ELF file\n");
fclose(fp); 
 continue;}

switch (header[4])
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



switch (header[5])
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
switch (header[6])
{
    case 0:
        printf("Version: Invalid\n");
        break;

    case 1:
        printf("Version: Current\n");
        break;

    default:
        printf("Version: Unknown (%u)\n", header[6]);
        break;
}

switch (header[7])
{
    case 0:
        printf("OS ABI: System V\n");
        break;

    case 3:
        printf("OS ABI: Linux\n");
        break;

    default:
        printf("OS ABI: Unknown (%u)\n", header[7]);
        break;
}

for (int j = 0; j < 16; j++){
printf("%02X ", header[j]); 

}
printf("\n");
fclose(fp);  

}
    return 0;
}
