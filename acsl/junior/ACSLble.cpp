#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <algorithm>
#include <vector.h>
using namespace std;
bool kons(char &c) {
    char k[5] = {'a','e','i','o','u'};
    for(int i = 0; i < 5; i++) { 
      if(c == k[i]) {c = '0'; return 0;}   
    }
    c = '1';
}        
int main() {
    string str; int counter = 0;
    vector<char>::iterator iter, dupl; 
    for(int puta = 1; puta <= 5; puta++) {
      cout << "Line #" << puta << ": ";   
      cin >> str;
      if(str[str.size()-1] == 'e') str[str.size()-1] = str[str.size()-2];
      for(int i = 0; i < str.size(); i++)   
        kons(str[i]);        
      vector<char> niz(str.begin(), str.end());
      dupl = unique(niz.begin(), niz.end());
      for(iter = niz.begin(); iter != dupl; iter++)
        counter++;
      cout << "Output #" << puta << ": " << counter++ << endl;
      niz.clear(); counter = 0;
    }             
    getch();
    return 0;
}            
