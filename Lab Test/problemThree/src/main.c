#include <stdio.h>
extern double mulMat(int);
int main(int arg, char* argv[]){
     double time[20];
     int n[20];
     int i=0;
     for(i=0; i<20; i++){
          int ntemp;
          printf("N: ");
          scanf("%d",&ntemp);
          n[i]=ntemp;
          time[i]=mulMat(ntemp);
     }
     char* commandsForGnuplot[]={
            "set boxwidth 1",
            "set xlabel \"(x) ---->\"",
            "set ylabel \"(function(x)) ---->\"",
            "set title \"Comparing sin/cos with mySin/myCos over [-pi,pi]\"",
            "set style fill solid border -1","set style data histograms",
            " plot \"data.txt\" using 2:xtic(1) with histograms t \'Time\'",
            "\" using 3 title \"GCC\" lt rgb \"#403090\"",
            "set term pngcairo","set output \"./output/graph.png\"",
            "set terminal png","replot","set output",

    };
    FILE * temp = fopen("data.txt", "w");
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    for(i=0; i<20; i++){
         fprintf(temp, "%d %lf\n", n[i], time[i]);
    }
    for(i=0; i<10; i++){
         fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]);
    }
    return 0;
}
