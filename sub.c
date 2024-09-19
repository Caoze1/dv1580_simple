#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int is_number(const char *str) {
  int has_decimal = 0;

  if (*str == '-' || *str == '+') {
      str++; // Allow leading sign
  }

  while (*str) {
      if (*str == '.') {
          if (has_decimal) return 0; // More than one decimal point
          has_decimal = 1;
      } else if (!isdigit(*str)) {
          return 0; // Non-digit character found
      }
      str++;
  }
  return 1; // Valid number
}

int main(int argc, char *argv[]){
  int test = is_number(argv[1]);
  if (test == 0){
    printf("ERROR\n");
    return 0;
  }
  test = is_number(argv[2]);
  if (test == 0){
    printf("ERROR\n");
    return 0;
  }

  int a1 = atoi(argv[1]);
  int a2 = atoi(argv[2]);
  printf("%d\n", a1 - a2);
  return 0;
}
