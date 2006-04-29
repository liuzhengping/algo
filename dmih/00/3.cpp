#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int top = 0, left = 1, front = 2, right = 3, bottom = 4, rear = 5;
struct kocka {
    int niz[6];
    void init() {
        for(int i = 0; i < 6; i++) niz[i] = 0;
    }    
    void xrotate() {
        int temp = niz[top];
        niz[top] = niz[front];
        niz[front] = niz[bottom];
        niz[bottom] = niz[rear];
        niz[rear] = temp;
    }
    void yrotate() {
        int temp = niz[right];
        niz[right] = niz[front];
        niz[front] = niz[left];
        niz[left] = niz[rear];
        niz[rear] = temp;    
    }        
} die[3];   
bool usporedi(int x) {
    for(int i = 0; i < 6; i++) {
      if(die[x].niz[i] != die[0].niz[i] && die[x].niz[i] && die[0].niz[i]) 
        return false;
      for(int j = 0; j < 6; j++) 
        if(i != j && !die[0].niz[i] && die[x].niz[i]) 
          if(die[x].niz[i] == die[0].niz[j]) return false;
    }    
    return true;
}
void dodaj(int x) {
    for(int i = 0; i < 6; i++)
      if(!die[0].niz[i]) die[0].niz[i] = die[x].niz[i];
}
void printaj() {
     for(int i = 0; i < 6; i++) printf("%d ", die[0].niz[i]);  
     printf("\n");
} 
void dopuni() {
    int brojevi[7] = {0,1,2,3,4,5,6};
    vector<int> v(die[0].niz, die[0].niz+6);
    vector<int> v2(brojevi, brojevi+6);
    vector<int> miss;
    sort(v.begin(), v.end());
    for(int i = 1; i <= 6; i++) 
      if(!binary_search(v.begin(), v.end(), i)) 
        for(int j = 0; j < 6; j++) 
          if(!die[0].niz[j]) {
              die[0].niz[j] = i;
              v.push_back(i);
              sort(v.begin(), v.end());
              break; 
          }    
}                       
int main() {
    die[0].init(); die[1].init(); die[2].init();
    for(int i = 0; i < 3; i++)
        scanf("%d %d %d", &die[i].niz[front], &die[i].niz[right], &die[i].niz[top]);
    for(int i = 1; i < 3; i++) {
        for(int yy = 0; yy < 4; yy++) {
          die[i].yrotate();
          for(int xx = 0; xx < 4; xx++) {
              die[i].xrotate();
              /*for(int g = 0; g < 6; g++) printf("%d ", die[0].niz[g]);
              printf("\n");
              for(int g = 0; g < 6; g++) printf("%d ", die[i].niz[g]);
              printf("\n--%d--\n", yy*4+xx);*/
              if(usporedi(i)) dodaj(i);
          }
        }
    }
       
    dopuni();
    printaj();         
    scanf("\n");
    return 0;
}    
