#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <iostream.h>
using namespace std;
struct momcadi {
    char ime[20];
    int g;
};
momcadi team[20], temp;
char* pogledaj(int n, int x) {
    for(int i = 0; i < n; i++) {
        if(team[i].g <= x)
          return team[i].ime;
    }          
    return "none";
}
int first(int n, char str[]) {
    for(int i = n-1; i >= 0; i--) {
        if(strcmpi(str, team[i].ime) == 0)
          return team[i].g;
    }
    return 0;
}            
void poredaj(int n) {
        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                if(team[j].g > team[i].g) {
                    temp = team[i];
                    team[i] = team[j];
                    team[j] = temp;
                }
            }
        }
}
void uredi(int n, int n2) {
    team[0].dur = n2-team[0].g;
    for(int i = 1; i < n; i++) 
        team[i].dur = team[i-1].g-team[i].g;
}                               
int main() {
    int m, n, N; char s[20]; int a, b;
    printf("Line #1: "); scanf("%d %d %d", &m, &n, &N);
    printf("\nLine #2: ");
    for(int puta = 0; puta < N; puta++) 
        scanf("%s %d", &team[puta].ime, &team[puta].g);
    printf("\nLine #3: "); scanf("%d %d %s", &a, &b, &s);    
    poredaj(N);    
    printf("\nOutput #1: %s", team[N-1].ime);
    printf("\nOutput #2: %s", pogledaj(N, a));
    printf("\nOutput #3: %s", pogledaj(N, b));
    printf("\nOutput #4: %d", first(N, s));
    uredi(N, n);                
    getch();
    return 0;
}    
