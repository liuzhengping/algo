#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream.h>
using namespace std;
int main(void) {
   string str;
   size_t begin; 
   const char gr[] = "nista_ja_ne_znam";
   const char zam[] = "sve_ja_znam";
   int  m = 0;
   
   cin >> str;
   while((begin = str.find("nista_ja_ne_znam")) < 80)
     str.replace(begin, 16, zam); 
   cout << str;
       
   getch();
   return 0;
}           
           
