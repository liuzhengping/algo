#include <iostream.h>
#include <algorithm>
#include <vector.h>
#include <conio.h>
#include <string.h>
using namespace std;
int main(void) {
    vector<int> a;
    int m, n, res = 0;
    a.push_back(1); a.push_back(3); a.push_back(4); a.push_back(8); a.push_back(7);
    cin >> m >> n;
    //for(int i = 0; i < a.size(); i++) {
        res = upper_bound(a.begin(), a.end(), n) - 
              lower_bound(a.begin(), a.end(), m);
    //}
    cout << res;
    getch();
    return 0;
}                  
