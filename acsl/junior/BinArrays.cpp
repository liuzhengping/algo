#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream.h>
using namespace std;
char polje[1000];
int main() {
    for(int puta = 0; puta < 1000; puta++) polje[puta] = '-';
    string buffer; string buff;
    char str[50], *podniz, c, dio[50][3];
    int i = 0, j = 0, max, root;
    while((c = getchar()) != '\n') {
      if(c != ' ') {  
        str[i++] = c;
        if((i+2)%3 == 0) buff.insert(buff.end(), c);
        else {
          size_t nadjeno = buffer.find(c);
          if(nadjeno > buffer.size()) buffer.insert(buffer.end(), c);
        }    
      }    
    }
    str[i] = '\0';
    cout << buffer;
    j = 0;
    for(int j = 0; j < buff.size(); j++) {
        size_t nadji = buffer.find(buff[j]);
        if(nadji > buffer.size()) {root = j; break;}
    }
    j = 0;
    while(j < strlen(str)) {
        max=j/3;
        for(int g = 0; g < 3; g++)
          dio[max][g] = str[j+g];
        j+=3;
    }
    polje[0] = str[root*3];
    polje[1] = str[root*3+1];
    polje[2] = str[root*3+2]; 
    int f = 1, count = 0;
    while(count <= strlen(str)) {
      if(polje[f] != '-') {
        if(polje[f] == 'a') printf("reza = %d", f);
        count++;
        size_t pos = buff.find(polje[f]);  
        if(pos <= buff.size()) {
            polje[2*f+1] = str[pos*3+1];
            polje[2*f+2] = str[pos*3+2];
        }    
      }
      f++;
    }
    printf("\n");
    for(int h = 0; h < 20; h++) printf("%c", polje[h]);                           
    getch();
    return 0;
}    
    
             
