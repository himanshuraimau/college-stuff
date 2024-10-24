#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024
void copy_block_by_block(const char *src, const char *dest)
{
    FILE *src_file = fopen(src, "rb");
    FILE *dest_file = fopen(dest, "wb");
    char buffer[BUFFER_SIZE];
    if (!src_file || !dest_file)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, src_file)) > 0)
    {   printf("buffer value: %s\n", buffer);
        fwrite(buffer, 1, bytes_read, dest_file);
    }
    fclose(src_file);
    fclose(dest_file);
    printf("File copied successfully (block-by-block).\n");
}
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }
    copy_block_by_block(argv[1], argv[2]);
    return 0;
}