#include <stdio.h>
#include <stdlib.h>
void copy_byte_by_byte(const char *src, const char *dest)
{
    FILE *src_file = fopen(src, "rb");
    FILE *dest_file = fopen(dest, "wb");
    if (!src_file || !dest_file)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    char buffer;
    while (fread(&buffer, 1, 1, src_file))
    {  
        printf("buffer: %c\n", buffer);
       fwrite(&buffer, 1, 1, dest_file);
    }
    fclose(src_file);
    fclose(dest_file);
    printf("File copied successfully (byte-by-byte).\n");
}
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }
    copy_byte_by_byte(argv[1], argv[2]);
    return 0;
}