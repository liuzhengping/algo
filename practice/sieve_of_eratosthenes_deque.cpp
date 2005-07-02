#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <algorithm>
#include <vector.h>
#include <deque.h>
#include <functional>
#include <numeric>
#define MAX 100000
using namespace std;      
int main() {
    deque<int> v1(MAX); int broj, temp = 0;
    vector<int> v;
    deque<int>::iterator newend; 
    for(int i = 2; i < MAX; i++) v1[i-2] = i; 
    while(!v1.empty()) {
        broj = v1.front();
        newend = remove_if(v1.begin(), v1.end(), not1(bind2nd(modulus<int>(), broj))); 
        v1.erase(newend, v1.end());
        //v.push_back(broj);
        printf("%d\t", broj);
    }
    /*for(vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
      cout << *iter << " ";*/
    cout << endl << "---" << v.size();
    getch();
    return 0;
}    
    
