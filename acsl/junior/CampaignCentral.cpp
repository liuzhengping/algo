#include <stdio.h>
#include <conio.h>
#include <vector.h>
#include <functional>
#include <algorithm>
#include <string.h>
using namespace std;
struct candidates {
    char ime[10];
    int pod[4];
    int suma;
    void racunaj() {
        for(int i = 0; i < 4; i++) suma+=pod[4];
    }    
} kand[5];
void imenuj() {
    strcpy(kand[0].ime, "ABEL"); strcpy(kand[1].ime, "BOLZANO"); 
    strcpy(kand[2].ime, "CANTOR"); strcpy(kand[3].ime, "DEDEKING"); 
    strcpy(kand[4].ime, "EULER");
}
char* pobijednik() {
    vector<int> v;
    for(int i = 0; i < 5; i++) {
        kand[i].racunaj();
        v.push_back(kand[i].suma);
    }
    sort(v.begin(), v.end(), greater<int>());
    for(int i = 0; i < 5; i++) {
        if(kand[i].suma == v[0]) 
            return kand[i].ime;
    }
}
string p[4] = {"b","p","l","m"};                
int main() {
    
    for(int i = 0; i < 4; i++) {
        scanf("%d %d %d %d %d", &kand[0].pod[i], &kand[1].pod[i], &kand[2].pod[i],
              &kand[3].pod[i], &kand[4].pod[i]);
    }
    printf("Gotovo\n");
    int rez = 0;
    for(int i = 0; i < 5; i++) {
      for(int j = 0; j < 4; j++) 
        rez+=kand[i].pod[j];
    }    
    printf("Output #1: %d\n", rez);
    vector<int> v1(kand[0].pod, kand[0].pod+4);
    sort(v1.begin(), v1.end(), greater<int>());
    for(int i = 0; i < 4; i++) {
        if(kand[0].pod[i] == v1[0]) {
          printf("Output #2: "); cout << p[i] << endl; 
          break;
        }
    }        
    v1.clear();
    getch();
    vector<int> v2(5);
    for(int j = 0; j < 5; j++) v1.push_back(kand[j].pod[2]);
    copy(v1.begin(), v1.end(), v2.begin());
    sort(v1.begin(), v1.end(), greater<int>());
    cout << "[" << v2[4] << "]" << v1[0];
    for(int pos = 0; pos < 5; pos++) {
      if(v2[pos] == v1[0]) {
        printf("Output #3: %s\n", kand[pos].ime);
        break;
      }
    }
    ////4. fali
    printf("Output #5: %s\n", pobijednik());
    getch();
    return 0;
    //25 56 30 40 99
    //88 21 11 10 30
    //70 80 90 33 91
    //53 62 75 60 90
}    
    
            
         
    
