#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
char paragraph[1000];
char recenice[20][100];
char *podniz;
int pronadji(int br_toc2) {
    int no_words_t, no_words2 = 0, n;
    
    for(int n = 0; n < br_toc2; n++) {
      no_words_t = 0;
      for(int j = 0; j < strlen(recenice[n]); j++) {
          if(recenice[n][j] == ' ')
            no_words_t++;
      }
      if(n == 0) no_words_t++;
      printf("\n hehe %d", no_words_t);
      getch();
      if(no_words_t > no_words2) 
          no_words2 = no_words_t;
    }        
      return no_words2;    
}
void distinct(int I) {
    char *podniz2; int n = 0, m = 0, l, i;
    char s_temp[200][20];
    printf(">>");
    for(int i = 0; i < I; i++) {  
      if(!isalpha(paragraph[i])) paragraph[i] = '.';
      putchar(paragraph[i]);
    }
    printf("<<");
    podniz2 = strtok(paragraph, ".");
    if(podniz2) {
        do {
            printf("\n->%s", podniz);
            podniz2 = strtok(NULL, ".");
        } while(podniz2);
    }        
    /*i = 0;    
    while(i < I) {
        for(l = i, n = 0; isalpha(paragraph[l]); l++)
            s_temp[m][n++] = paragraph[l];
        s_temp[m++][n] = '\0';
        printf("\n->%s", s_temp[m-1]);
        i = l;
        while(paragraph[i] == ' ' && i < I) i++;
    } */            
}                
int main() {
    char c; int m, i = 0, no_words, br_toc;
    const char *granicnici = ".!?";
    for(int puta = 1; puta <= 2; puta++) {
        no_words = 0; br_toc = 0;
        printf("Paragraph %d:", puta);
        while((c = getchar()) != EOF && c != '\n') { 
          paragraph[i++] = c;
          if(c == '?' || c == '!' || c == '.') br_toc++;
        }    
        paragraph[i] = '\0';  
        for(int j = 0; j < i; j++) {
          if(paragraph[j] == ' ')  
            no_words++;  
        }
        m = 0;
        podniz = strtok(paragraph, granicnici);
        if(podniz) {
            do {
                strcpy(recenice[m++], podniz);
                podniz = strtok(NULL, granicnici);
            } while(podniz);       
          
        }    
        if(no_words >= 1) no_words++;        
        printf("evo %d\n", no_words);
        printf("najduza = %d\n", pronadji(br_toc));
        distinct(i);
    }
    getch();
    return 0;
}                 
