
#include <stdio.h>
#include <stdbool.h>

#include "argparser.h"

int main(int argc, char *argv[]) {
    Config config = parse_args(argc, argv);
    printf("Depth: %d\n", config.depth);
    printf("Path: %s\n", config.path);
    printf("Recursive: %s\n", config.recursive ? "yes" : "no");
    printf("Human Readable: %s\n", config.human_readable ? "yes" : "no");
    return 0;
}
