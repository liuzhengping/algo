#include <cstdio>
#include <iostream>
#include <cstring>
#include <ctype.h>
#include <cstdlib>
#define P 30
#define D 31
using namespace std;
int n = 0;
struct varijable {
    long int br;
    long int naz;
    char znak;
    void init() {
        br = 1; naz = 1; znak = '0';
    }
    void skrati() {
        if(naz == 1 || br == 1) return;
        if(naz == br) {br = 1; naz = 1; return;}
        if(!br) {naz = 1; return;}
        int a = br, b = naz;
        if(a < b) {int t = a; a = b; b = t;}
        do {
            int t = b;
            b = a%b;
            a = t;
        } while(b);
        br/=a; naz/=a;    
    }
    void print() {
        printf("%ld/%ld\n", br, naz);
    }        
} var[32]; 
int nadji(char ch) {
    for(int i = 0; i < 30; i++)
      if(var[i].znak == ch) return i;
    return 0;
}
void op(string s) {
    int a = nadji(s[2]), b = nadji(s[4]), c = nadji(s[0]);
    long int naz, br;
    if(s[3] == '+') {
        br=var[a].br*var[b].naz+var[b].br*var[a].naz;
        naz=var[a].naz*var[b].naz;    
    }
    else if(s[3] == '-') {
        br=var[a].br*var[b].naz-var[b].br*var[a].naz;
        naz=var[a].naz*var[b].naz;    
    }
    else if(s[3] == '*') {
        br=var[a].br*var[b].br;
        naz=var[a].naz*var[b].naz;
    }
    else if(s[3] == '/') {
        br=var[a].br*var[b].naz;
        naz=var[a].naz*var[b].br;
    }
    n++;
    var[c].br = br;
    var[c].naz = naz;
    var[c].skrati();                
}               
int main() {
    string naredba;
    for(int i = 0; i < 30; i++) var[i].init();
    for(;;) {
        cin >> naredba;
        if(naredba ==    "print") {
           var[nadji(naredba[6])].print();
        }
        else if(naredba == "end") break;
        else {
            bool da1 = false, da2 = false;
            char prvi[10], drugi[10];
            size_t poc, kraj, ind;
            poc = naredba.find('='); kraj = naredba.find('/');
            int k = 0;
            for(ind = poc+1; ind < kraj; ind++) prvi[k++] = naredba[ind];
            prvi[k] = '\0';
            if(isdigit(prvi[0])) da1 = true;  
            
            poc = naredba.find('/'); kraj = naredba.size();
            k = 0;
            for(ind = poc+1; ind < kraj; ind++) drugi[k++] = naredba[ind];
            drugi[k] = '\0';
            if(isdigit(drugi[0])) da2 = true;
            if(da1 && da2) {
                var[nadji(naredba[0])].br = atoi(prvi);
                var[nadji(naredba[0])].naz = atoi(drugi);
            }
            else if(!da1 && !da2) op(naredba);  
            else {
                
            }         
        }        
    }      
    scanf("\n");
    return 0;
}    
