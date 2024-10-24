#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
void list_files_recursive(const char *path, int depth)
{
    DIR *dir = opendir(path);
    struct dirent *entry;
    if (!dir)
    {
        perror("Error opening directory");
        return;
    }
    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }
        for (int i = 0; i < depth; i++)
            printf(" "); // Indentation for depth
        printf("%s\n", entry->d_name);
        // If entry is a directory, call recursively
        if (entry->d_type == DT_DIR)
        {
            char new_path[1024];
            snprintf(new_path, sizeof(new_path), "%s/%s", path, entry->d_name);
            list_files_recursive(new_path, depth + 1);
        }
    }
    closedir(dir);
}
int main(int argc, char *argv[])
{
    const char *path = argc > 1 ? argv[1] : ".";
    list_files_recursive(path, 0);
    return 0;
}