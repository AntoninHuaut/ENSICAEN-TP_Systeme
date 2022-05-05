#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>

void clean_buffer() {
  char buffer;
  while ((buffer = getchar()) != '\n' && buffer != EOF) {
  }
}