#include <cstdio>
#include <cstring>
#include <cctype>

#define MAXLEN 82

int main() {
  char buf[MAXLEN];
  while (fgets(buf, MAXLEN, stdin)) {
    int len = strlen(buf);
    while (len-- > 0)
      buf[len] = tolower(buf[len]);
    if (strstr(buf, "problem"))
      printf("yes\n");
    else
      printf("no\n");
  }
  return 0;
}
