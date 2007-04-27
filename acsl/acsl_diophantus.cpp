#include <cstdio>
#include <vector>
#include <iostream>
#include <conio.h>
#include <map>
using namespace std;
struct op{
  int ex;
  int k;
};

bool vece(const op& a, const op& b) {return a.ex > b.ex;}
 
vector<op> so;
vector<string> ops;
string s; bool subs, minu;

bool broj(char c){
  return (c >= '0' && c <= '9') && c != 'M';
}
bool slovo(char c){
  return (c>= 'A' && c <= 'Z');
}

void tok(){
  int exp = 0;
  int a=-1, b=-1; bool na = true;
  for(int i = 0;; i++){
      if(s[i] == 'M'){        
        if(!na){
          //cout << "pusham1." << i << " " << s.substr(a, i-a) << endl; getch();
          ops.push_back(s.substr(a, i-a));
        }
        na = true;  
        //cout << "pusham2."  << i << " "  << s.substr(i, 1) << endl; getch();
        ops.push_back(s.substr(i, 1));
      }  
      else if(slovo(s[i]) && na == true) {
        a = i;
        //cout << "slovo3."  << i << " "  << endl; getch();
        na = false;
      }
      else if(broj(s[i])){
        na = true;
        //cout << "pusham4."  << i << " "  << s.substr(a, i-a+1) << endl; getch();
        ops.push_back(s.substr(a, i-a+1));
      }
      if(i >= s.size()){
        if(!na) ops.push_back(s.substr(a, i-a));
        break;
      }  
  }  
}
op sol2(string a){  
  op ret;
  int k = 0, r=1, eksp;
  if(a == "M"){
    //subs = true;
   // printf("%d%d", ret.k, ret.ex);
    //printf("%s je M\n", a.c_str());
    ret.ex = -1000;
    return ret;
  }
  bool ima = false;
  for(int i = a.size()-1; i >= 0 && broj(a[i]); i--) {
    k = i;
    ima = true;
  }
  string tt; 
  //printf("(%d, %d-%d=%d)", k, a.size(), k, a.size()-k); getch();
  if(ima){
    tt = a.substr(k, a.size()-k);
    r = atoi(tt.c_str());
    tt = a.substr(0, k);
  }
  else {
    tt = a;
    r = 1;
  }  
  if(tt == "X" ) eksp = 1;
  else if(tt == "P" ) eksp = 2;
  else if(tt == "C" ) eksp = 3;
  else if(tt == "PP" ) eksp = 4;
  else if(tt == "PC" ) eksp = 5;
  else if(tt == "CC" ) eksp = 6;
  else if(tt == "U" ) eksp = 0; 
  ret.k = r;
  ret.ex = eksp;
  return ret;
}
void sort(){
  /*for(int i = 0; i < so.size()-1; i++)
    for(int j = i; j < so.size(); j++)
      if(so[i].ex < so[j].ex) swap(so[i], so[j]);*/
  sort(so.begin(), so.end(), vece);
}
void sol(){
  so.resize(ops.size());
  for(int i = 0; i < ops.size(); i++){
    
    op tmp = sol2(ops[i]);    
    so[i].ex = tmp.ex;
    if(tmp.ex < 0) { //ako je M
      so[i].k = -1337; //postavi simboliku
      minu = true;
      continue;
    }  
    if(minu){
      so[i].k = -tmp.k;
    }  
    else
      so[i].k = tmp.k;

  }
  sort();
}
void out(){
  for(int i = 0; i < so.size(); i++){
    if(so[i].k == -1337) continue;
    if(so[i].k > 0 && i) printf("+");
    if(so[i].k != 1) printf("%d", so[i].k);
    else if(so[i].k == -1) printf("-");
    if(so[i].ex == 1) printf("X");
    else if(so[i].ex) printf("X^%d", so[i].ex);
  }
}  
  

int main(){
  cin >> s;
  tok();
  sol();
  out();
  scanf("\n");
  return 0;
}
/*
C3PP2X5MP4U6
PMU4
P3MX2U3
*/
