#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <vector.h>
#include <queue.h>
#include <deque.h>

#define N_L 5
#define IZNOS 10

long int MAX;
vector<long int> v;
long int niz[N_L];
struct ljudi {
    int poslao;
    long int svota;
    deque<long int> lista;
} stan[100000];
long int rnd(long int raspon)
{
  long int r;
  
  ponovi: 
  r = rand()%raspon;
  vector<long int>::iterator f = find(v.begin(), v.end(), r);
  if(f != v.end()) {
      if(v.size() >= MAX)
        return -5;
      goto ponovi;
  }
  else  
    v.push_back(r);
  return r;
}
void srnd(void)
{   
  srand((unsigned) time(NULL));
}

    
void petljudi() {
     bool da = true;
    long int r;
    
    //while(da) {
    for(int k = 0; k < N_L; k++) {      
     r = rnd(MAX);
     //if(r == -5)
     //  da = 0;
     //else
       niz[k] = r;
    }
    v.clear();
}
 
int main() {
    queue<long int> q;
    long int x, y;
    srnd();
    
    cout << "Broj ljudi ( <=32768 )? ";
    cin >> MAX;
    petljudi();
         
    for(int i = 0; i < N_L; i++) 
      stan[0].lista.push_back(niz[i]);
    q.push(0);
    for(int i = 0; i < MAX; i++)
      stan[i].lista.resize(5);
    for(deque<long int>::iterator iter = stan[0].lista.begin(); iter !=stan[0].lista.end(); iter++)
      cout << *iter << " ";
    while(!q.empty()) {
       x = q.front();
       if(!stan[x].poslao) {
         y = stan[x].lista.front();
         stan[y].svota+= IZNOS;
         stan[x].lista.pop_front();
         stan[x].lista.push_back(x);
           //cout << endl << x << ": ";
           //for(deque<int>::iterator iter = stan[x].lista.begin(); iter !=stan[x].lista.end(); iter++)
              //cout << *iter << " ";
            //cout << endl;
         petljudi();
         for(int i = 0; i < N_L; i++) {
           stan[ niz[i] ].lista.resize(N_L); 
           copy(stan[x].lista.begin(), stan[x].lista.end(), stan[ niz[i] ].lista.begin());
               //cout << niz[i] << ": ";
              //for(deque<int>::iterator iter = stan[niz[i]].lista.begin(); iter !=stan[niz[i]].lista.end(); iter++)
              // cout << *iter << " ";
              //cout << endl;
           q.push(niz[i]);
         }    
         stan[x].poslao = 1;
       }
       q.pop();
    }
    vector<long int> v;
    long int suma = 0;
    for(int i = 0; i < MAX; i++) { 
        //cout << endl << i << ". " << stan[i].svota << ": ";
          //for(deque<int>::iterator iter = stan[i].lista.begin(); iter !=stan[i].lista.end(); iter++)
          //  cout << *iter << " ";
        suma+=stan[i].svota;
        v.push_back(stan[i].svota);
    }
    cout << endl << "___________________________" << endl << suma << endl <<  "___________________________" << endl;
    sort(v.begin(), v.end(), greater<long int>());
    for(int i = 0; i < 10; i++) cout << v[i] << endl;            
    
    
    getch();
    return 0;
    
}


