#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream.h>
using namespace std;
int polje[9][9] = {4,0,1,0,4,0,1,0,4,
                   0,3,0,2,0,2,0,3,0,
                   1,0,3,0,1,0,3,0,1,
                   0,2,0,3,0,3,0,2,0,
                   4,0,1,0,3,0,1,0,4,
                   0,2,0,3,0,3,0,2,0,
                   1,0,3,0,1,0,3,0,1,
                   0,3,0,2,0,2,0,3,0,
                   4,0,1,0,4,0,1,0,4};

int main() {
    char s[100], dir;
    int x, y;
    cin >> s >> y >> x >> dir;
    //scanf("%s%d%d%c", &s, &y, &x, &dir);
    int umn = 1;
    int rez = 0;
    if(dir == 'h') {
        for(int i = x; i < strlen(s)+x; i++) {
            printf("[%d]", polje[y][i]);
            if (polje[y][i] == 0) rez++;
            else if(polje[y][i] == 1) rez+=2;
            else if(polje[y][i] == 2) rez+=3;
            else if(polje[y][i] == 3) {umn*=2; rez++;}
            else if(polje[y][i] == 4) {umn*=3; rez++;}o
        }
     }    
     else if(dir == 'v') {
         for(int i = y; i >= y-strlen(s)+1; i--) {
              if (polje[i][x] == 0) rez++;
            else if(polje[i][x] == 1) rez+=2;
            else if(polje[i][x] == 2) rez+=3;
            else if(polje[i][x] == 3) umn*=2;
            else if(polje[i][x] == 4) umn*=3;   
         }
     }
     printf("%d", umn*rez);
     getch();
     return 0;
}            
    
    
