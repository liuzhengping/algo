#include <queue.h>
#include <conio.h>
#include <iostream.h>
queue<int> Q[2];
int polje[7][7];
int main() {
    int s_x, s_y, k_x, k_y, x, y; bool a = true;
    int br = 1, pom_br = 0;
    int susj1[4] = {0,-1,0,1};
    int susj2[4] = {-1,0,1,0};
    
    polje[1][0]=-1;polje[2][0]=-1;polje[0][2]=-1;polje[0][3]=-3;polje[1][3]=-1;
    polje[3][2]=-1;polje[3][3]=-1;polje[3][4]=-1;polje[4][1]=-1;polje[5][3]=-1;
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 7; j++) {
            if(polje[i][j] == -1) cout << "0"; else cout << "*";
        }
        cout << endl;
    }
    ponovi:
    cout << endl << "Napisite pocetne koordinate: ";
    cin >> s_x >> s_y;
    if(polje[s_y][s_x] == -1) goto ponovi;
    ponovi2:
    cout << endl << "Napisite zavrsne koordinate: ";
    cin >> k_x >> k_y;
    if(polje[k_y][k_x] == -1) goto ponovi2;
    Q[0].push(s_y);
    Q[1].push(s_x);
         
    while(a) {
      y = Q[0].front();
      x = Q[1].front();
      Q[0].pop();
      Q[1].pop();
      if(x == k_x && y == k_y) break;
      for(int puta=0; puta < 4; puta++) {
          if(y+susj1[puta] >= 0 && x+susj2[puta] >= 0 && 
             polje[y+susj1[puta]][x+susj2[puta]] == 0) {  
               polje[y+susj1[puta]][x+susj2[puta]] = polje[y][x]+1; 
               Q[0].push(y+susj1[puta]);
               Q[1].push(x+susj2[puta]);
                 
          }
      }           
    }
    cout << polje[y][x];   
    cout << endl << "gotovo!";
    getch();
    return 0;
}    
