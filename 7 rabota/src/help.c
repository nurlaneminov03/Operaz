#include "help.h"
#include <stdio.h>

void show_help(const char *prog) {
    printf("Usage: %s [OPTIONS]\n", prog);
    printf("Options:\n");
    printf("  -u, --users            Show users and home directories\n");
    printf("  -p, --processes        Show running processes\n");
    printf("  -l, --log PATH         Redirect output to file\n");
    printf("  -e, --errors PATH      Redirect errors to file\n");
    printf("  -h, --help             Show this help\n");
}
