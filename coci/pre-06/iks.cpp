#include <stdio.h>
#include <vector.h>
#include <conio.h>
using namespace std;
vector<int> supr(vector<int>a) {
    vector<int> b;
    for(int i = 0; i < a.size(); i++) 
        b.push_back(1-a[i]);
    return b;
}        
int main() {
    vector<int> x;
    x.push_back(0);
    while(x.size() <= 200) {
        vector<int> y = supr(x);
        x.insert(x.end(), y.begin(), y.end());
    }    
    int m, n;
    scanf("%d %d", &m, &n);
    for(int i = m; i <= n; i++) 
      printf("%d", x.at(i));
    printf("\n"); 
    
    getch();
    return 0;
    
}            
