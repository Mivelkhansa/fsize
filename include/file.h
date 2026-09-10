#ifndef FILE_H
#define FILE_H

#include <stdbool.h>
#include <sys/types.h>


bool is_directory(const char *path);
bool is_file(const char *path);
int get_file_size(const char *path);
off_t walk_directory(const char *path, int depth);

#endif
