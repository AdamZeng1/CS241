#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    FILE* f = fopen("data.csv","w");
    
    fprintf(f,"My password is 1234\n");
    fflush(f); // call write 
    
    fseek(f,0,SEEK_END);
    long size = ftell(f);
    
    printf("%d bytes\n",(int) size);

    
    if(fork()) {
        fseek(f,0,SEEK_SET); // go to beginning of file
        
        fclose(f);
    } else {
        sleep(1); // should be waitpid but I'm feeling bad and evil.
        fprintf(f,"5678 %d!\n",getpid());
        fclose(f);
    }
    return 0;
}
