#include <stdio.h>
#include <conio.h>
#include <deque.h>
#include <string.h>
using namespace std;
int main() {
    deque<string> d;
    int puta = 0;
    char str[100], *podniz, c, rijeci[100][100];
    while(puta <= 5) {
        str[0] = '\0';
        int i = 0;
        while((c = getchar()) != '\n') 
            str[i++] = c; 
        str[i] = '\0';
        int m = 0;
        podniz = strtok(str, " ");
        if(podniz) {
            do {
                strcpy(rijeci[m++], podniz);
                podniz = strtok(NULL, " ");
            } while(podniz);
         
        }    
        if(strcmpi(rijeci[0], "append") == 0) {
            for(int k = 1; k < m; k++)
              d.push_back(rijeci[k]);
        }
        else if(strcmpi(rijeci[0], "cons") == 0) {
            for(int k = m-1; k > 0; k--)
              d.push_front(rijeci[k]);
        }
        else if(strcmpi(rijeci[0], "pop") == 0) 
            d.pop_front();                 
        else if(strcmpi(rijeci[0], "trunc") == 0)
            d.pop_back();
        else if(strcmpi(rijeci[0], "print") == 0) {
            puta++;
            printf("Output #%d: ", puta);
            for(deque<string>::iterator iter = d.begin();
                iter != d.end(); iter++)
                  cout << *iter << " ";
            printf("\n");
        }
    }
    getch();
    return 0;
}            
            
            
