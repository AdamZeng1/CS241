int count(int* start) {
  int * ptr = start;
  while( *ptr <=100) { ptr ++ ; }

  return ( ptr - start) ;
}
