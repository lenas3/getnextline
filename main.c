#include <fcntl.h>    // open
#include <stdio.h>    // printf, perror
#include <stdlib.h>   // free
#include <unistd.h>   // close

#include "get_next_line.h"

// get_next_line prototipi (kendi implementasyonun)
char *get_next_line(int fd);

int main(int argc, char **argv)
{
    int fd = open("exmple.txt", O_RDONLY);
    printf("%s", get_next_line(fd));
    
}
