#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int niz[20] = { 1, 2, 4, 4, 7, 7, 7, 8, 8,10,11,11,11,11,11,16,16,18,19,20};
int nista[20]={ 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20};
int bs(int left, int right, int v) {
    int mid;
    while(left <= right) {
        mid = (left+right)/2;
        if(niz[mid] == v) return mid+1;
        else if(niz[mid] < v)
          left = mid+1;
        else
           right = mid-1;
    }
    return 0;    
}    
int ub(int left, int right, int v) {
    int mid; bool da = false;
    while(left < right) {
        mid = (left+right+1)/2;
        if(niz[mid] <= v) 
          left = mid;  
        else
           right = mid-1;
    }
    return (left+1)+1;    
}
int lb(int left, int right, int v) {
    int mid; bool da = false;
    while(left < right) {
        mid = (left+right-1)/2;
        if(niz[mid] < v) 
          left = mid+1;
        else 
          right = mid;   
    }
    return (right+1);    
}        
int main() {
    int x;
    vector<int> v(niz, niz+20);
    do {
        scanf("%d", &x);
        printf("Bs: %d\tUb: %d(%d)\tLb: %d(%d)\n", bs(0,19,x), ub(0,19,x), 
        upper_bound(v.begin(), v.end(), x)-v.begin()+1, lb(0,19,x), 
        lower_bound(v.begin(), v.end(), x)-v.begin()+1);
    } while(x);
    scanf("\n");
    return 0;
}    
