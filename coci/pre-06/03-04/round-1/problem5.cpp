#include <cstdio>
#include <iostream.h>
#include <cstring>
#define MAX 100
using namespace std;
char rez[MAX*10], sol[MAX][MAX*10];
string str_sol;
void rev(string s) {
    str_sol = s;
    reverse(str_sol.begin(), str_sol.end()); 
}    
inline void pomnozi(string a, char b, int puta = 0) {
    int carry = 0;
    int k, x;
    string temp;
    k = 0;
    temp.append("0");
    a.insert(a.begin(), temp.begin(), temp.end());
    //cout << "->" << a << "-" << b << "<-" << endl;
    for(int i = a.size()-1; i >= 0; i--, k++) {
        x = (b-'0')*(a[i]-'0')+carry;
        if( x > 9) {
            carry = x/10;
            sol[puta][k] = (x%10) +'0';
        }
        else {
            carry = 0;
            sol[puta][k] = x+'0';
            if(i == 1) i = -1;
        }  
    }        
         
}  
inline void zbroji(string a, string b) {
    int carry = 0; 
    int max, min, k, x;
    string temp;
    temp.append("0");
    a.insert(a.begin(), temp.begin(), temp.end());
    b.insert(b.begin(), temp.begin(), temp.end());
    
    if(a.size() > b.size()) {max = a.size(); min = b.size();}
    else {
        max = b.size(); min = a.size();
        swap(a, b);
    }
    
    temp.clear();
    for(int i = 0; i < max-min; i++)
      temp.append("0");
    b.insert(b.begin(), temp.begin(), temp.end());
    //cout << "->" << a << "-" << b << "<-" << max-min << endl;
    for(int i = max-1, k = 0; i >= 0; i--, k++) {
          x = (b[i]-'0')+(a[i]-'0')+carry;
          if(x > 9) {
              carry = 1;
              rez[k] = x-10 + '0';
          }
          else {
              carry = 0;
              rez[k] = x+'0';
              if(i == 1) i = -1;
          }        
            
    }
}     
void solve(string a, string b) {
    int k;
    for(int i = b.size()-1, k = 0; i >= 0; i--, k++) { 
        pomnozi(a, b[i], k);
    }    
}
void zbroj(int n) {
    for(int i = 0; i < n; i++) {
          rev(sol[i]);
          for(int j = 0; j < i; j++)
            str_sol.append("0");
  
          string str_sol2 = str_sol;
          rev(rez);
          zbroji(str_sol, str_sol2);
    }
    rev(rez);
    cout << "rjesenje: " << str_sol << endl;
}        
                     
int main() {
    
    char a[MAX], b[MAX];
    scanf("%s %s", &a, &b);
    double start = clock();

    rez[0] = '0'; rez[1] = '\0';

    cout << endl << endl;
    solve(a, b);
    zbroj(strlen(b));
    printf("\n\n\n%lf", (clock()-start)/1000);
    scanf("%s", &a);
   
 
    return 0;
}    
