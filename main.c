
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

for (int j = 0; j < 16; j++){
printf("%02X ", header[j]); 

}
printf("\n");
fclose(fp);  

}
    return 0;
}
