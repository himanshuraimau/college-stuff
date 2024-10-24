#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
void list_files_with_types(const char *path)
{
    DIR *dir = opendir(path);
    struct dirent *entry;
    struct stat st;
    char full_path[1024];
    if (!dir)
    {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }
    while ((entry = readdir(dir)) != NULL)
    {
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        stat(full_path, &st);
        if (S_ISDIR(st.st_mode))
        {
            printf("[DIR] %s\n", entry->d_name);
        }
        else if (S_ISREG(st.st_mode))
        {
            printf("[FILE] %s\n", entry->d_name);
        }
        else if (S_ISLNK(st.st_mode))
        {
            printf("[LINK] %s\n", entry->d_name);
        }
    }
    closedir(dir);
}
int main(int argc, char *argv[])
{
    const char *path = argc > 1 ? argv[1] : ".";
    list_files_with_types(path);
    return 0;
}