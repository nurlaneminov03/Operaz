#include "processes.h"
#include <stdio.h>
#include <stdlib.h>

void show_processes(void) {
    FILE *fp = popen("ps -eo pid,comm --sort=pid", "r");
    if (!fp) {
        perror("popen processes");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }

    pclose(fp);
}
