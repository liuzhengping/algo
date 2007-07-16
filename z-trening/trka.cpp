#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct igrac {
       int start, mjesto;
       bool aktivan;
       double brzina, put;
};

int n, kraj, r;
vector <int>v;
igrac t[100];
bool je[100];

int us(int h, int m, int s) {
    return 3600 * h + 60 * m + s;
}

void ucitaj() {
     int h, m, s, i;
     double v;
     scanf("%d%d%d%d", &n, &h, &m, &s);
     kraj = us(h, m, s);
     for (i=0;i<n;++i) {
         scanf("%lf%d%d%d", &v, &h, &m, &s);
         t[i].start = us(h, m, s);
         t[i].brzina = v;
         t[i].mjesto = 0;
         t[i].put = 0.0;
         t[i].aktivan = false;
     }
}

void simuliraj() {
     int i, j, tko;
     double mx;
     bool ista;
     
     for (i=0;i<=kraj;++i) {
         for (j=0;j<n;++j) {
             if (t[j].start == i) t[j].aktivan = true;
             if (t[j].aktivan) t[j].put += t[j].brzina;
         }
         mx = 0;
         ista = false;
         for (j=0;j<n;++j) {
             if (!t[j].aktivan || t[j].put == 0) continue;
             if (t[j].put > mx) {
                mx = t[j].put;
                tko = j;
                ista = true;
             }
         }
         if (ista) je[tko] = true;
     }
}

void ispisi() {
     int i, r = 0;
     
     for (i=0;i<n;++i) {
         if (je[i]) r++;
     }
     
     cout << r << endl;
}

int main() {
    ucitaj();
    simuliraj();
    ispisi();
    return 0;
}
