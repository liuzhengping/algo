#include <iomanip.h>
#include <iostream.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
using namespace std;
int main() {
    string a[5];
    size_t tocka, max = 0, m;
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
    for(int i = 0; i < 5; i++) {
      tocka = a[i].find(".");
      if(tocka > a[i].size()) 
          tocka = a[i].size();
      if(tocka > max)
        max = tocka;
    }
    for(int puta = 1; puta <= 5; puta++) {
      printf("Output #%d:\n", puta);  
      cout << setw(max) << "1" << endl;
      for(int i = 0; i < puta; i++) {
        tocka = a[i].find(".");
        if(tocka > a[i].size()) m = 0;
        else 
            m = a[i].size() - tocka;  
        cout << setw(max + m) << a[i] << endl;
      }
    }        
    getch();
    return 0;
}        
    
