#include <stdio.h>

#ifndef FSIZE_VERSION
#define FSIZE_VERSION "unknown"
#endif

int main() {
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
           "  -H, --human      print sizes in human-readable form\n"
           "  -v, --version    display version and exit\n",
           FSIZE_VERSION);

    return 0;
}
