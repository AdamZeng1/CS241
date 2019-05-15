
char* mystrdup(const char* src) {
  char* result = malloc( strlen(src) + 1);
  if(result == NULL) {
     return NULL;
  }
  strcpy(result, src);
  return result;
}
