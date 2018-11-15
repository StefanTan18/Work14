#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char ** parse_args( char * line ) {
  char ** a = malloc(5 * sizeof(char *));
  int i = 0;
  while(i < 5) {
    a[i] = strsep(&line, " ");
    i++;
  }
  return a;
}

int main() {
  
  char line[100] = "ls -a -l";
  char ** args = parse_args( line );
  execvp(args[0], args);

  return 0;
}

