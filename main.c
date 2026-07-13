
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
fread(header, 1, 16, fp);
printf("File: %s\n", argv[i]);
for (int j = 0; j < 16; j++){
printf("%02X ", header[j]); 

}
printf("\n");
fclose(fp);  

}
    return 0;
}
