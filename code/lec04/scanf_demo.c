#include <stdio.h>

int main(int argc, char**argv) {
  int x = 10;
  int y = 20;
  int result = scanf("%d,%d", &x , &y);
  printf("x is now %d and y is now %d.\n", x, y);
  if( result != 2) {
    // handle the error
  }
  return 0;
}
