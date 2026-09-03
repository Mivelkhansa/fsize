#ifndef ARGPARSER_H
#define ARGPARSER_H
#include <stdbool.h>

typedef struct {
    char *path;
    int depth;
    bool recursive;
    bool human_readable;

} Config;

Config parse_args(int argc, char *argv[]);

#endif
