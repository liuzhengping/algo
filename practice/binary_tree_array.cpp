#include <stdio.h>
#include <conio.h>
#define max 32768
using namespace std;
int polje[max];
void print(int node) {
    if(polje[node*2+1] != -1)
      print(node*2+1);
    printf("%d", polje[node]);
    if(polje[node*2+2] != -1)
      print(node*2+2);
}      
int main() {
    int n; int node, a;
    for(int i = 0; i < max; i++)
      polje[i] = -1;
    scanf("%d", &n);
    scanf("%d", &polje[0]);
    for(int i = 1; i < n; i++) {
        scanf("%d", &a);
        node = 0;
        while(polje[node] != -1) {
            if(a <= polje[node])
              node=node*2+1;
            else
              node=node*2+2;
        }    
        polje[node] = a; 
    }
    /*int broj;
    node = 0;
    printf("\nNadji broj: ");
    scanf("%d", &broj);
    while(polje[node] != -1) {
        if(polje[node] == broj) printf("hehe");
        if(broj <= polje[node]) node=node*2+1;
        else  node=node*2+2;
    } */
    print(0);
    getch();
    return 0;
}    
              
    
        
