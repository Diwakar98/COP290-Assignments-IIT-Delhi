extern double myFactorial(int);
double nCr(int n,int r){
     double nFact=myFactorial(n);
     double rFact=myFactorial(r);
     double nrFact=myFactorial(n-r);
     double ncr=nFact/(rFact*nrFact);
     return ncr;
}
