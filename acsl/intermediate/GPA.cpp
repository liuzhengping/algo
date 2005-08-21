#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector.h>
char grade[4][5][3], ime[4][20]; 
    int course[4][5], dur[4][5], n_dur[4];
    float n_c[4][5], reza[4], gpa[4];
void init() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 5; j++)
          strcpy(grade[i][j], "");
    }
}
struct studenti {
    float GPA;
    int no;
} student[4], temp;    
void sortiraj() {
    for(int i = 0; i < 3; i++) {
        for(int j = i+1; j < 4; j++) {
            if(student[j].GPA > student[i].GPA) {
                temp = student[i];
                student[i] = student[j];
                student[j] = temp;
            }
        }
    }            
}                           
int main() {
    for(int puta = 1; puta <= 4; puta++) {
        printf("Line #%d: ", puta);
        if(puta == 1)
            scanf("%s %s %d %s %d", ime[puta-1], &grade[puta-1][0], &course[puta-1][0], &grade[puta-1][1], &course[puta-1][1]);
        else if(puta == 2)
            scanf("%s %s %d %s %d %s %d", ime[puta-1], &grade[puta-1][0], &course[puta-1][0], &grade[puta-1][1], &course[puta-1][1],
                  &grade[puta-1][2], &course[puta-1][2]);
        else if(puta == 3)
            scanf("%s %s %d %s %d %s %d %s %d", ime[puta-1], &grade[puta-1][0], &course[puta-1][0], &grade[puta-1][1], &course[puta-1][1],
                  &grade[puta-1][2], &course[puta-1][2], &grade[puta-1][3], &course[puta-1][3]);
        else if(puta == 4)
            scanf("%s %s %d %s %d %s %d %s %d %s %d", ime[puta-1], &grade[puta-1][0], &course[puta-1][0], &grade[puta-1][1], &course[puta-1][1],
                  &grade[puta-1][2], &course[puta-1][2], &grade[puta-1][3], &course[puta-1][3], &grade[puta-1][4], &course[puta-1][4]);
        printf("\n%s", grade[0][0]);
    }
    for(int k = 0; k < 4; k++) {
        for(int l = 0; l < 5 && strlen(grade[k][l]) > 0; l++) {
            if(grade[k][l][1] == '-') n_c[k][l] -= 0.25;
            else if(grade[k][l][1] == '+') n_c[k][l] += 0.25;
            switch(grade[k][l][0]){
              case 'A':
                  n_c[k][l] += 4.5;
                  break;
              case 'B':
                  n_c[k][l] += 3.5;
                  break;
              case 'C':
                  n_c[k][l] += 2.5;
                  break;
              case 'D':
                  n_c[k][l] += 1;
                  break;
              
            }
            //course
            if(course[k][l] == 341) 
                dur[k][l] = 4;
            else if(course[k][l] == 342)
                 dur[k][l] = 4;
            else if(course[k][l] == 343)  
                 dur[k][l] = 2;
            else if(course[k][l] == 344)  
                 dur[k][l] = 2;
            else if(course[k][l] == 345)  
                 dur[k][l] = 1;
            else if(course[k][l] == 346)  
                 dur[k][l] = 1;
            else if(course[k][l] == 347)  
                 dur[k][l] = 4;
            else if(course[k][l] == 348)  
                 dur[k][l] = 4;
           if(course[k][l] == 342 || course[k][l] == 343 || course[k][l] == 345 || course[k][l] == 347) {
                    if( (grade[k][l][0] == 'C' && grade[k][l][1] == '+') || grade[k][l][0] == 'B' || grade[k][l][0] == 'A')
                      n_c[k][l] += 0.5;
            }
            reza[k] = reza[k] + n_c[k][l]*dur[k][l];    
            n_dur[k] += dur[k][l];                            
        }
        //gpa:
        gpa[k] = reza[k]/n_dur[k]; 
        printf("Output #%d: %f\n", k+1, gpa[k]);
    }
    vector<float> v;
    for(int i = 0; i < 4; i++) 
        v.push_back(gpa[i]);
    sort(v.begin(), v.end());
    for(int j = 0; j < 4; j++) {
      student[j].GPA = gpa[j];
      student[j].no = j;
    }
    sortiraj();
    printf("Output #5: %s", ime[ student[0].no ]);     
    getch();
    return 0;
}        
            
             
