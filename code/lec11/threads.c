#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int counter;

void* friday( void* p) {
  printf("My pointer %p points to %s\n", p, p);

  pthread_exit((void* ) 0xdeadc0de);// NEVER RETURNS !!
  
  puts("Secret of life is ....."); // will never be executed
  
  return (void*) 0xdeadbeef;
}

int main() {
  pthread_t tid, tid2;
  pthread_create( &tid , NULL, &   friday, "Cheeseburger");
  puts("Amazing threads");
  pthread_create( &tid2 , NULL, &   friday, "Demo");
  
  char* threadexitvalue;
  pthread_join( tid, (void**) & threadexitvalue);
  printf("return ptr is %p \n", threadexitvalue);
  puts(threadexitvalue); // will seg fault because 0xdeadc0de is not valid memory on my machine
  
  return 0; // time to go away 
}
