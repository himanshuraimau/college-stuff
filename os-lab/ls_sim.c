#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
void list_files(const char *path)
{
    struct dirent *entry;
    DIR *dir = opendir(path);
    if (dir == NULL)
    {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }
    printf("Files in directory %s:\n", path);
    // Read entries from the directory
    while ((entry = readdir(dir)) != NULL)
    {
        // Ignore hidden files (starting with '.')
        if (entry->d_name[0] != '.')
        {
            printf("%s\n", entry->d_name);
        }
    }
    closedir(dir);
}
int main(int argc, char *argv[])
{
    const char *path = "."; // Default to current directory
    if (argc > 2)
    {
        printf("Usage: %s [directory_path]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (argc == 2)
    {
        path = argv[1]; // Use provided directory path
    }
    list_files(path);
    return 0;
}