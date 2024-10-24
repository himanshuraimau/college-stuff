#include <stdio.h>
#include <stdlib.h>
void copy_file(const char *src, const char *dest)
{
    FILE *src_file, *dest_file;
    char ch;
    // Open source file in read mode
    src_file = fopen(src, "r");
    if (src_file == NULL)
    {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }
    // Open destination file in write mode
    dest_file = fopen(dest, "w");
    if (dest_file == NULL)
    {
        perror("Error opening destination file");
        fclose(src_file);
        exit(EXIT_FAILURE);
    }
    // Read from source and write to destination
    while ((ch = fgetc(src_file)) != EOF)
    {
        fputc(ch, dest_file);
    }
    printf("File copied successfully.\n");
    // Close both files
    fclose(src_file);
    fclose(dest_file);
}
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    copy_file(argv[1], argv[2]);
    return 0;
}