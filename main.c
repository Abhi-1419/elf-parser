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

if (fp == NULL)
{
    perror(argv[i]);
continue;

}

printf("Opened %s successfully!\n", argv[i]);
fclose(fp); 

}
    return 0;


}
