#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>

#include "users.h"
#include "processes.h"
#include "help.h"

int main(int argc, char *argv[]) {
    int opt;
    int option_index = 0;

    static struct option long_opts[] = {
        {"users", no_argument, 0, 'u'},
        {"processes", no_argument, 0, 'p'},
        {"help", no_argument, 0, 'h'},
        {"log", required_argument, 0, 'l'},
        {"errors", required_argument, 0, 'e'},
        {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, "uph l:e:", long_opts, &option_index)) != -1) {
        switch (opt) {

        case 'l': {
            int fd = open(optarg, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd < 0) {
                perror("log file");
                return 1;
            }
            dup2(fd, STDOUT_FILENO);
            close(fd);
            break;
        }

        case 'e': {
            int fd = open(optarg, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd < 0) {
                perror("error file");
                return 1;
            }
            dup2(fd, STDERR_FILENO);
            close(fd);
            break;
        }

        case 'u':
            show_users();
            return 0;

        case 'p':
            show_processes();
            return 0;

        case 'h':
            show_help(argv[0]);
            return 0;

        default:
            show_help(argv[0]);
            return 1;
        }
    }

    show_help(argv[0]);
    return 0;
}
