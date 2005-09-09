#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream.h>
#include <vector.h>
#include <algorithm>
int main() {
    long long int n, x, suma;
    int m, voz[1000];
    //scanf("%lld %d", &n, &m);
    cin >> n >> m;
    for(int i = 0; i < m; i++) scanf("%d", &voz[i]);
    //for(int i = 0; i < m; i++) printf("%d",voz[i]);
    //printf("ha(%lld,%d)", n, m);
    if( n <= m) {
          suma = n;
          printf("evo ga na%d", n);
          getch();
          exit(0);
        }    
    int l = 1; int r = 2000;
    int da = 0;
    long long int temp;
    while(r >= l) {
        suma = 0;
        x = (l+r)/2;
        
        
          for(int j = 0; j < m; j++)
            suma = suma + x/voz[j];
          printf("\nmin = %lld, suma = ", x); cout << suma; 
        if(suma == n-1) {da = 1; break;}
        temp = x;    
        if(suma > n) r = x-1;
        else l = x+1;
        
    }
    if(!da) x--;
    vector<int> v;
    cout << "/" << x << "/";
    for(int j = x; j < x+31; j++) {
    for(int i = 0; i < m; i++) {
            if(j%voz[i] == 0) 
              printf("(%d)", i+1);
                //v.push_back(j%voz[i]);
        }
    }    
   //sort(v.begin(), v.end());
    //printf("----%d---", v.front()); 
    /*for(long long int k = x; k < x+15; k++) {
        for(int i = 0; i < m; i++) {
            if(k%voz[i] == 0) {printf("\n%d", i);}
        }
    } */        
    getch();
    return 0;
}    
