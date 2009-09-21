#include <cstdio>
#include <string>
#include <map>
#include <iostream>
#define PRIME 26777
using namespace std;

struct word {
  string s;
  int hashcode;
  
  word(char *buff) {
    s = buff;
    hashcode = compute_hash();
  }

  int compute_hash() {
    int ret = 0;
    for( int i = s.length()-1; i >= 0; --i ) {
      ret = 26*ret + s[i]-'a';
      if( ret >= PRIME ) ret %= PRIME;
    }
    return ret;
  }

};

map<string, word> table[PRIME];


int main() {
  int n, sol = 0;
  char buff[105];
  scanf("%d", &n);
  for( int i = 0; i < n; ++i ) {
    scanf("%s", buff);
    word w(buff);
    table[w.hashcode].insert( make_pair(w.s, w) );
  }

  for( int i = 0; i < n; ++i ) {
    scanf("%s", buff);
    word w(buff);
    if( table[w.hashcode].count(w.s) ) 
      ++sol;
  }

  printf("%d\n", sol);

  return 0;
}
