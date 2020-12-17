#include <time.h>
double mulMat(int n){
     double mat1[n][n];
     double mat2[n][n];
     double res[n][n];
     int i, j, k;
     clock_t t;
     for(i=0; i<n; i++){
          for(j=0; j<n; j++){
               mat1[n][n]=2.0;
               mat1[n][n]=2.0;
          }
     }
     t=clock();
     for (i = 0; i < n; i++)
     {
          for (j = 0; j < n; j++)
          {
               res[i][j] = 0;
               for (k = 0; k < n; k++)
                    res[i][j] += mat1[i][k]*mat2[k][j];
          }
     }
     t=clock()-t;
     double t1=((double)t)/CLOCKS_PER_SEC;
     return t1;
}
