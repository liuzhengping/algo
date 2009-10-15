#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int main() {
  char email[128];
  while( scanf("%s", &email) == 1 ) {
    string s;
    int ok = 0, len = strlen(email);
    for( int i = 0; i < len; ++i )
      if( email[i] == '<' ) ok = 1;
      else if( email[i] == '>' ) ok = 0;
      else if( ok ) s.push_back(email[i]);
    if( !s.empty() ) 
      printf("%s,\n", s.c_str());
  }
  return 0;
}
