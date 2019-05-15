#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// ulimit -a to list limits
// then -p or -u depending on system

int main() {
    puts("Use ulimit!");
    exit(1);

    while(1) {
        printf("Hello world. I'm process %d!\n",(int) getpid());

        if( fork() == -1) perror("Failed to fork!");

        sleep(1);
    }
    return 0;
}
