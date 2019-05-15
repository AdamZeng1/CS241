#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
   char* lineptr;
   size_t size;
   printf("What is thou command o master\n >");
   size = getline( & lineptr, &size, stdin);
   if(size >0 && lineptr[size-1] == '\n'){
     lineptr[size-1] = '\0';
   }
   printf("I shall run for thee '%s' ...\n",lineptr);
   execlp(lineptr,  lineptr, (char*) NULL);
   return 0;
}
