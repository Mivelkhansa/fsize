
#include "argparser.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>


#ifndef FSIZE_VERSION
#define FSIZE_VERSION "unknown"
#endif


Config parse_args(int argc, char *argv[]) {
    Config config = {0};
    config.depth= 0;
    config.recursive = false;
    config.human_readable = false;


    struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"depth", required_argument, 0, 'd'},
        {"recursive", no_argument, 0, 'r'},
        {"human-readable", no_argument, 0, 'H'},
        {0, 0, 0, 0}
    };

    int opt;
    while ((opt = getopt_long(argc, argv, "hd:rH", long_options, NULL)) != -1) {
        switch (opt) {
            case 'h':
                printf("    ______     _          \n"
                       "   / ____/____(_)___  ___ \n"
                       "  / /_  / ___/ /_  / / _ \\\n"
                       " / __/ (__  ) / / /_/  __/\n"
                       "/_/   /____/_/ /___/\\___/ \n");
                printf("___________________________\n");

                printf("\n"
                       "fsize %s - display file sizes\n"
                       "\n"
                       "Usage: fsize [OPTION]... [FILE]...\n"
                       "\n"
                       "Options:\n"
                       "  -h, --help       display this help and exit\n"
                       "  -r, --recursive  recursively process directories\n"
                       "  -d, --depth      set recursion depth\n"
                       "  -H, --human      print sizes in human-readable form\n"
                       "  -v, --version    display version and exit\n",
                       FSIZE_VERSION);
                exit(0);

                break;
            case 'd':
                config.depth = atoi(optarg);
                break;
            case 'r':
                config.recursive = true;
                break;
            case 'H':
                config.human_readable = true;
                break;
            default:
                break;
        }
    }
    config.path = argv[optind];

    return config;
}
