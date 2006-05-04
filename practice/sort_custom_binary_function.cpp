#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct proba {
    string s;
    int br;
} init;    
struct vece : binary_function<string, string, bool> {
    bool operator()(string a, string b) {
        return a.size() < b.size(); 
    }
};
struct vecipar : binary_function<pair<string, int>, pair<string, int>, bool> {
    bool operator()(pair<string, int> prvi, pair<string, int> drugi) {
        return prvi.second < drugi.second;
    }    
} ;
struct ucenici {
    string ime; int raz; char slovo;
};    
vector<ucenici> ucenik(4);
struct visi : binary_function<ucenici, ucenici, bool> {
    bool operator()(ucenici a, ucenici b) {
        return a.raz > b.raz;
    } 
};              
vector<string> v;
vector<pair<string, int> > p;
int main() {
    v.push_back("marko");
    v.push_back("viktor");
    v.push_back("fico");
    v.push_back("leo");
    sort(v.begin(), v.end(), vece());
    for(vector<string>::iterator it = v.begin(); it != v.end(); it++)
      cout << *it << endl;
    for(int i = 0; i < 4; i++) {
        pair<string, int> par;
        cin >> par.first >> par.second;
        p.push_back(par);
    }
    cout << endl;
    sort(p.begin(), p.end(), vecipar());
    for(vector<pair<string, int> >::iterator it = p.begin(); it != p.end(); it++)
      cout << (*it).first << " " << (*it).second << endl;
    cout << endl << "Upisi rijec broj koji si napisao: ";
    int broj; string rijec; cin >> rijec >> broj;    
    cout << binary_search(p.begin(), p.end(), make_pair<string, int>(rijec, broj), vecipar());
    
    ucenik[0].ime = "marin"; ucenik[0].raz = 6; ucenik[0].slovo = 'c';
    ucenik[1].ime = "luka"; ucenik[1].raz = 7; ucenik[1].slovo = 'a';
    ucenik[2].ime = "marko"; ucenik[2].raz = 2; ucenik[2].slovo = 'a';
    ucenik[3].ime = "josip"; ucenik[3].raz = 4; ucenik[3].slovo = 'b';  
    sort(ucenik.begin(), ucenik.end(), visi());  
    for(int i = 0; i < 4; i++)
      cout << ucenik[i].ime << " " << ucenik[i].raz << " " << ucenik[i].slovo;
    scanf("\n");
    return 0;
}    
