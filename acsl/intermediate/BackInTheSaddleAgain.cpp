#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <algorithm>
#include <vector.h>
int main() {
    int matrix[6][6];
    int n_row, n_col; int k, l;
    bool ne1, ne2;
    vector<int> v1;
    for(int puta = 1; puta <= 5; puta++) {
      printf("Line #%d: ", puta);
      scanf("%d %d", &n_row, &n_col);
      for(k = 0; k < n_col; k++)
        for(l = 0; l < n_row; l++) 
          scanf("%d", &matrix[l][k]);
      for(k = 0; k < n_col; k++) {
        for(l = 0; l < n_row; l++) {
             ne1 = 0; ne2 = 0;
             for(int i = 0; i < n_col; i++) {
                 if(i != k) {
                     if(matrix[l][k] <= matrix[l][i]) {
                         ne1 = 1;
                         break;
                     }
                 }
             }
             for(int j = 0; j < n_row; j++) {
                 if(j != l) {
                     if(matrix[l][k] <= matrix[j][k]) {
                         ne2 = 1;
                         break;
                     }
                 }
             }
             if(!ne1 && !ne2) 
                 v1.push_back(matrix[l][k]);
         }
      }
      printf("Output #%d: ", puta);
      if(v1.size() > 0) {
        sort(v1.begin(), v1.end());
        vector<int>::iterator dupl; int vel;
        dupl = unique(v1.begin(), v1.end());
        v1.erase(dupl, v1.end());
        vel = v1.size();
        int br = 0;
        for(vector<int>::iterator iter = v1.begin(); iter != v1.end(); iter++, br++) {    
          if(br == vel - 1 && vel > 1) cout << " and ";
          else if(br < vel && br != 0) cout << ", ";
          cout << *iter;
        }
      }
      else
        printf("none");
      printf("\n");
    }                                                     
    getch();
    return 0;
}        
    
