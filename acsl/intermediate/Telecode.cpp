#include <stdio.h>
#include <conio.h>
#include <string.h>
using namespace std;
int main() {
    char str[100];
    for(int puta = 1; puta <= 5; puta++) {
        int num[10] = {4, 2, 3, 2, 3, 2, 3, 4, 1, 2}, suma = 1;
        printf("Line %d: ", puta);
        scanf("%s", str);
        for(int i = 0; i < strlen(str); i++) 
            suma*=num[ str[i] - '0']--;
        printf("Output #%d: %d\n", puta, suma);
    }      
    getch();
    return 0;
}      
