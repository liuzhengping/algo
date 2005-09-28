#include <stdio.h>
#include <conio.h>
#include <fstream.h>
using namespace std;
int main() {
    int polje[100000], n, best = -32767;
    ifstream in("maximum sum.txt", ios::in);
    in >> n;
    //for(int i = 0; i < n; i++) in >> polje[i];
    for(int k = 0; k < n; k++) {
        int temp = 0;
        for(int i = k; i < n; i++) {
            temp += polje[i];
            if(temp > best)
              best = temp;
            if(temp < 0)
              break;
        }
    }
    printf("%d", best);
    getch();
    return 0;
}        
    
    
    
