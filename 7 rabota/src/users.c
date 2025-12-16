#include "users.h"
#include <stdio.h>
#include <stdlib.h>

void show_users(void) {
    FILE *fp = popen("cut -d: -f1,6 /etc/passwd | sort", "r");
    if (!fp) {
        perror("popen users");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }

    pclose(fp);
}
