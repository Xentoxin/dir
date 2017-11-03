#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main() {
    DIR * d = opendir(".");
    struct dirent * dir;
    dir = readdir(d);

    printf("Directories:\n");
    while (dir != NULL) {
        if (dir -> d_type == DT_DIR) {
            printf("\t%s\n", dir -> d_name);
        }
        dir = readdir(d);
    }

    int total = 0;
    struct stat sb;

    printf("Files:\n");
    d = opendir(".");
    dir = readdir(d);
    while (dir != NULL) {
        if (dir -> d_type == DT_REG) {
            stat(dir -> d_name, &sb);
            total += sb.st_size;
            printf("\t%s\n", dir -> d_name);
        }
        dir = readdir(d);
    }
    printf("Total size of regular files is: %d\n", total);
    return 0;
}
