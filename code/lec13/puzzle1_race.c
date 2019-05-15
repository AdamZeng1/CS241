#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int your_starting_value[10];
pthread_t tid[10]; 

void* myfunc(void*ptr) {
  int myvalue = * (int*) ptr;
  printf("My thread id is %p and I'm starting at %d\n", pthread_self(), myvalue);

  return NULL;
}
int main() {
  // Each thread needs a different value of i 
  
  for(int i =0; i < 10; i++) {
     pthread_create( &tid[i], 0, myfunc, &i);
   }
    
    pthread_exit(NULL) ; // this is a one way trip, pthread_exit never returns !!
   return 0;
}

