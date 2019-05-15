#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Check to see if lower 4 bits of each byte are random

int main() {
    srandom(0xd3a005c);
    uint32_t data[2] = { random(), random() };
    int d=0;
    for(; d<6; d++) {
      putchar('A' + (((uint8_t*)data)[d] & 0x0f ) );
    }    
    putchar('\n');
  return 0;
}
