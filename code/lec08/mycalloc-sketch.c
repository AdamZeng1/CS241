void* mycalloc(size_t count, size_t size) {
  size_t total = count * size;
  
  void *result = malloc(total);
  if(!result) { return NULL; } //early feature
  
  memset(result, 0, total);
  return result;
}

void * realloc(void *oldptr, size_t size);


void readall() {
  size_t capacity = 16;
  size_t numitems = 0;
  double *data = NULL;
  while(1) {
    double val = getAnotherValue();
    if(val == 0 ) break;
    
    if( numitems  == capacity){
      capacity *= 2;
      data = realloc(data , capacity * sizeof(double) );
    }
    data[numitems ++] = val;
  }
  
  
  
  
  
}