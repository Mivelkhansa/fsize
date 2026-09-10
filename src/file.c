#include <sys/stat.h>
#include <stdbool.h>
#include <dirent.h>
#include <stdio.h>
#include <linux/limits.h>
#include <string.h>

bool is_directory(const char *path) {
    struct stat st;
    if (lstat(path, &st) == 0) {
        return S_ISDIR(st.st_mode);
    }
    return false;
}

bool is_file(const char *path) {
    struct stat st;
    if (lstat(path, &st) == 0) {
        return S_ISREG(st.st_mode);
    }
    return false;
}

int get_file_size(const char *path) {
    struct stat st;
    if (lstat(path, &st) == 0) {
        return st.st_size;
    }
    return -1;
}


off_t walk_directory(const char *path, int depth) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return 0;
    }
    off_t dir_size = 0;

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {

        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char full_path[PATH_MAX];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (is_directory(full_path) && depth > 0) {
            dir_size += walk_directory(full_path, depth - 1);
        } else if (is_file(full_path)) {
            int size = get_file_size(full_path);
            if (size >= 0) {
                printf("%s: %d bytes\n", full_path, size);
                dir_size += size;
            }
        }
    }

    closedir(dir);
    return dir_size;
}
