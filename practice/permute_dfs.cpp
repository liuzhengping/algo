#include <stdio.h>
#include <conio.h>
int val[100], V = 4, id = -1;
void write() {
    for(int i = 0; i < V; i++) printf("%d ", val[i+1]);
    printf("\n");
}       
void visit(int k) {
    int t;
    val[k] = ++id;
    if(id == V) write();
    for(t = 1; t <= V; t++) 
        if (val[t] == 0) 
          visit(t);
    id--; val[k] = 0;
    
}
int main() {
    printf("\nUpisite broj znamenki: ");
    scanf("%d", &V);
    visit(0);
    getch();
    return 0;
}
