#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <fstream.h>
long long int polje[1000][1000];
int main() {
    int i, j;
    ofstream van ("pascalov_tr.txt", ios::out);
    polje[0][0] = 1; polje[0][1] = 2; polje[0][2] = 1;
    for(i = 1; i < 25; i++) {
        for(j = 0; j < 25; j++) 
            polje[i][j] = polje[i-1][j-1] + polje[i-1][j];
    }
    for(i = 0; i < 150; i++) {
        for(j = 0; j < 250; j++) {
          if(polje[i][j] != 0)  
            van << polje[i][j] << " ";
        }    
        van << "\n";  
    }
    getch();
    return 0;
}            
