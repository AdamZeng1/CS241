#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cv = PTHREAD_COND_INITIALIZER;

int  cake = 0;

void decrement() { // Will block if zero
  pthread_mutex_lock(&m);
  while(cake == 0) {
    printf("     Consumer: cake is zero...  calling pthread_cond_wait\n");
      pthread_cond_wait(&cv, &m); // unlock mutex, SLEEP, later... lock mutex
    printf("     Consumer: pthread_cond_wait returned (Is cake>0?)\n");
  }  
    puts(" - ");
  cake --;
  pthread_mutex_unlock(&m);
}

void increment() {
  pthread_mutex_lock(&m);
    puts(" + ");
    cake ++;
    printf("     \e[103mpthread_cond_broadcast\e[49m\n");
    pthread_cond_broadcast(&cv);  // Wake up all hungry sleeping cake eaters
    // pthread_cond_signal(&cv);  // Wake up one hungry sleeping cake eater
  pthread_mutex_unlock(&m);
    
}

void* cake_eater(void*arg) {
  while(1) {
    sleep(1);
    decrement();
    printf("     \e[102mConsumer: Thanks! Now %d pieces left\e[49m\n",cake); 
  }
  return NULL;
}
void* cake_maker(void*arg) {
  while(1) {
    sleep(5);
    printf("     \e[103mProducer: Time for more cake\e[49m\n");
    sleep(1);
    increment();
    increment();
    increment();
  }
  return NULL;
  
}
int main() {
  pthread_t tid1, tid2;
  pthread_create(&tid1, NULL, cake_eater, NULL);
  pthread_create(&tid2, NULL, cake_maker, NULL);
  pthread_exit(NULL);
}