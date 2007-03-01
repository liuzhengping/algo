#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char ime[100], prezime[100], rec[100], niz[10][100]; int n;
int main() {
    /*scanf("%s %s", &niz, &prezime); ucitava ime i prezime kao string
    if(strcmp(ime, prezime) == 0) {  //ako su isti radi nesto }
    strcat(ime, prezime); //na ime se nakelji prezime
    strcpy(ime, prezime); //ime postaje prezime
    */
    gets(rec); //ucitava recenicu/e
    char *podniz;
    int k = 0;
    podniz = strtok(rec, " !?,.:;");
    do {
        //ovdje je ta rijec, u "podnizu"
        strcpy(niz[k], podniz); k++;
        
        podniz = strtok(NULL, " !?,.:;"); 
    } while(podniz);    
    
    for(int i = 0; i < k-1; ++i)
      for(int j = i + 1; j < k; ++j)
        if(string(niz[i]) > string(niz[j])) {
            char t[100]; 
              strcpy(t, niz[i]); strcpy(niz[i], niz[j]); strcpy(niz[j], t);
        }  
    for(int i = 0; i < k; ++i) printf("%s\n", niz[i]);    
    scanf("\n");
    return 0;
}    
