
#include <stdio.h>
#include <stdbool.h>
#include <dirent.h>

#include "argparser.h"
#include "file.h"

#ifndef RECURSION_DEPTH_MAX
#define RECURSION_DEPTH_MAX 999999
#endif


int main(int argc, char *argv[]) {
    Config config = parse_args(argc, argv);
    printf("Path: %s\n", config.path);

    if (is_file(config.path)) {
        int size = get_file_size(config.path);
        printf("Size: %d\n", size);
        return 0;
    }

    off_t size = 0;
    if (config.recursive == true) {
        size = walk_directory(config.path, RECURSION_DEPTH_MAX);
    } else {
        size = walk_directory(config.path, config.depth);
    }

    printf("Total Size: %ld\n", size);

    return 0;
}
