#include <stdio.h>
#include "mydemo.h"
#include <stdlib.h>
#include <string.h>
#include <complex.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
double toDouble(char s[]) {
    	unsigned long long int m = 1;
    	double ret = 0;
    	int i=0;
    	int size=strlen(s);
	int dp=size;
	bool isfloat=false;
    	for (i= size-1; i >= 0; i--) {
	    	if(s[i]=='.'){
			dp=i;
			isfloat=true;
		}
		else if(s[i]=='-'){}
		else{
        		ret += (s[i] - '0') * m;
			m *= 10;
		}
    	}
	double result=ret;
	if(isfloat){
		dp=size-dp-1;
		result=ret/pow(10.0,dp);
	}
	if(s[0]=='-'){
		result = result * (-1);
	}
	return result;
}
bool iszero(char n[]){
	int i=0;
	int size=strlen(n);
	for(i=0; i<size; i++){
		if(n[i]!='0' && n[i]!='.' && n[i]!='-'){
			return false;
		}
	}
	return true;
}
int main(int argc, char *argv[]){
	char* inputarg=argv[1];
	char* outputarg=argv[2];
	char* grapharg=argv[3];
	// printf("inputarg=|%s|\n", inputarg);
	// printf("outputarg=|%s|\n", outputarg);
	// printf("grapharg=|%s|\n", grapharg);
	FILE * outputfile = fopen(outputarg, "w");
	FILE *file = fopen(inputarg,"r");
	if(file==NULL){
		printf("File Not Found...");
		exit(0);
	}
	char line[1000];
	clock_t t1;
	clock_t t2;
	clock_t t3;
	clock_t t4;
	clock_t t5;
	clock_t t6;
	double mytime[5];
	double gcctime[5];
	int counteradd=0; //0
	int countersub=0; //1
	int countermul=0; //2
	int counterdiv=0; //3
	int counterabs=0; //4
	while(fgets(line,1000,file)!=NULL){
		char *token=strtok(line," ");
		// printf("===%d\n", CLOCKS_PER_SEC);
		if(strcmp(token,"ADD")==0){
               // printf("ADD\n");
               char a1[1000],b1[1000],a2[1000],b2[1000];
			char A1[1000],B1[1000],A2[1000],B2[1000];
               token =strtok(NULL,"\n");
               // printf("1=|%s|\n", token);
               int i=1;
               int c=0;
               while(token[i]!=','){
                    a1[c]=token[i];
				A1[c++]=token[i++];
               }
               a1[c]='\0';
			A1[c]='\0';
               // printf("a1=|%s|\n", a1);
               i++;
               c=0;
               while(token[i]!=')'){
                    b1[c]=token[i];
				B1[c++]=token[i++];
               }
               b1[c]='\0';
			B1[c]='\0';
               // printf("b1=|%s|\n", b1);
               i=i+3;
               c=0;
               while(token[i]!=','){
                    a2[c]=token[i];
				A2[c++]=token[i++];
               }
               a2[c]='\0';
			A2[c]='\0';
               // printf("a2=|%s|\n", a2);
               i++;
               c=0;
               while(token[i]!=')'){
                    b2[c]=token[i];
				B2[c++]=token[i++];
               }
               b2[c]='\0';
			B2[c]='\0';
			int len1=strlen(a1)+strlen(b1);
			int len2=strlen(a2)+strlen(b2);
               // printf("b2=|%s|\n", b2);
               char* f1=(char*)malloc((len1+len2)*sizeof(char));
               char* f2=(char*)malloc((len1+len2)*sizeof(char));
			t1=clock();
               strcpy(f1,addnew(a1,a2));
               strcpy(f2,addnew(b1,b2));
			t1=clock()-t1;
			mytime[0]=mytime[0]+((double)t1)/CLOCKS_PER_SEC;
               // printf("(%s,%s)\n", f1, f2);
			fprintf(outputfile, "(%s,%s)\n", f1,f2);
               free(f1);
               free(f2);
			// printf("(%s,%s) (%s,%s)\n", a1,b1,a2,b2);
			// printf("(%s,%s) (%s,%s)\n", A1,B1,A2,B2);
			double d1=toDouble(A1);
			double d2=toDouble(B1);
			double d3=toDouble(A2);
			double d4=toDouble(B2);
			t2=clock();
			double real = d1+d3;
			double cmplx = d2+d4;
			t2=clock()-t2;
			gcctime[0]=gcctime[0]+((double)t2)/CLOCKS_PER_SEC;
			// printf("\t%f\t%f\n", mytime[counter],gcctime[counter]);
			counteradd++;

		}
		else if(strcmp(token,"SUB")==0){
               // printf("SUB\n");
			char a1[1000],b1[1000],a2[1000],b2[1000];
			char A1[1000],B1[1000],A2[1000],B2[1000];
               token =strtok(NULL,"\n");
               // printf("1=|%s|\n", token);
               int i=1;
               int c=0;
               while(token[i]!=','){
                    a1[c]=token[i];
				A1[c++]=token[i++];
               }
               a1[c]='\0';
			A1[c]='\0';
               // printf("a1=|%s|\n", a1);
               i++;
               c=0;
               while(token[i]!=')'){
                    b1[c]=token[i];
				B1[c++]=token[i++];
               }
               b1[c]='\0';
			B1[c]='\0';
               // printf("b1=|%s|\n", b1);
               i=i+3;
               c=0;
               while(token[i]!=','){
                    a2[c]=token[i];
				A2[c++]=token[i++];
               }
               a2[c]='\0';
			A2[c]='\0';
               // printf("a2=|%s|\n", a2);
               i++;
               c=0;
               while(token[i]!=')'){
                    b2[c]=token[i];
				B2[c++]=token[i++];
               }
               b2[c]='\0';
			B2[c]='\0';
			int len1=strlen(a1)+strlen(b1);
			int len2=strlen(a2)+strlen(b2);
               // printf("b2=|%s|\n", b2);
               char* f1=(char*)malloc((len1+len2)*sizeof(char));
               char* f2=(char*)malloc((len1+len2)*sizeof(char));
			t1=clock();
               strcpy(f1,subnew(a1,a2));
               strcpy(f2,subnew(b1,b2));
			t1=clock()-t1;
			mytime[1]=mytime[1]+((double)t1)/CLOCKS_PER_SEC;
               // printf("(%s,%s)\n", f1, f2);
			fprintf(outputfile, "(%s,%s)\n", f1,f2);
               free(f1);
               free(f2);
			double d1=toDouble(A1);
			double d2=toDouble(B1);
			double d3=toDouble(A2);
			double d4=toDouble(B2);
			t2=clock();
			double real = d1-d3;
			double cmplx = d2-d4;
			t2=clock()-t2;
			gcctime[1]=gcctime[1]+((double)t2)/CLOCKS_PER_SEC;
			// printf("\t%f\t%f\n", mytime[counter],gcctime[counter]);
			countersub++;
		}
		else if(strcmp(token,"PROD")==0){
               // printf("PROD\n");
			char a11[1000],b11[1000],a21[1000],b21[1000];
			char a12[1000],b12[1000],a22[1000],b22[1000];
			char A1[1000],B1[1000],A2[1000],B2[1000];
               token =strtok(NULL,"\n");
               // printf("1=|%s|\n", token);
               int i=1;
               int c=0;
               while(token[i]!=','){
                    a11[c]=token[i];
				a12[c]=token[i];
				A1[c++]=token[i++];
               }
               a11[c]='\0';
			a12[c]='\0';
			A1[c]='\0';
               // printf("a1=|%s|\n", a1);
               i++;
               c=0;
               while(token[i]!=')'){
                    b11[c]=token[i];
				b12[c]=token[i];
				B1[c++]=token[i++];
               }
               b11[c]='\0';
			b12[c]='\0';
			B1[c]='\0';
               // printf("b1=|%s|\n", b1);
               i=i+3;
               c=0;
               while(token[i]!=','){
                    a21[c]=token[i];
				a22[c]=token[i];
				A2[c++]=token[i++];
               }
               a21[c]='\0';
			a22[c]='\0';
			A2[c]='\0';
               // printf("a2=|%s|\n", a2);
               i++;
               c=0;
               while(token[i]!=')'){
                    b21[c]=token[i];
				b22[c]=token[i];
				B2[c++]=token[i++];
               }
               b21[c]='\0';
			b22[c]='\0';
			B2[c]='\0';
			int len1=strlen(a11)+strlen(b11);
			int len2=strlen(a21)+strlen(b21);
               // printf("b2=|%s|\n", b2);
               char* f1=(char*)malloc(2*(len1+len2)*sizeof(char));
			char* f2=(char*)malloc(2*(len1+len2)*sizeof(char));
			char* f3=(char*)malloc(2*(len1+len2)*sizeof(char));
			char* f4=(char*)malloc(2*(len1+len2)*sizeof(char));
			t1=clock();
			// printf("a1=%s\n", a11);
			// printf("b1=%s\n", b11);
			// printf("a2=%s\n", a21);
			// printf("b2=%s\n", b21);
               strcpy(f1,mulnew(a11,a21));
			strcpy(f3,mulnew(a12,b21));
               strcpy(f2,mulnew(b11,b22));
			strcpy(f4,mulnew(b12,a22));
			// printf("f1=%s\n", f1);
			// printf("f2=%s\n", f2);
			// printf("f3=%s\n", f3);
			// printf("f4=%s\n", f4);
			t1=clock()-t1;
               // printf("f1=|%s|\n", f1);
               // printf("f2=|%s|\n", f2);
               // printf("f3=|%s|\n", f3);
               // printf("f4=|%s|\n", f4);
               char temp1[strlen(f1)];
               char temp2[strlen(f2)];
               char temp3[strlen(f3)];
               char temp4[strlen(f4)];
               i=0;
               for(i=0; i<strlen(f1); i++){
                    temp1[i]=f1[i];
               }
               temp1[i]='\0';
               i=0;
               for(i=0; i<strlen(f2); i++){
                    temp2[i]=f2[i];
               }
               temp2[i]='\0';
               i=0;
               for(i=0; i<strlen(f3); i++){
                    temp3[i]=f3[i];
               }
               temp3[i]='\0';
               i=0;
               for(i=0; i<strlen(f4); i++){
                    temp4[i]=f4[i];
               }
               temp4[i]='\0';
               free(f1);
               free(f2);
               free(f3);
               free(f4);
               // printf("temp1=|%s|\n", temp1);
               // printf("temp2=|%s|\n", temp2);
               // printf("temp3=|%s|\n", temp3);
               // printf("temp4=|%s|\n", temp4);
               char* f5=(char*)malloc((len1+len2)*sizeof(char));
               char* f6=(char*)malloc((len1+len2)*sizeof(char));
			t3=clock();
               strcpy(f5,subnew(temp1,temp2));
               strcpy(f6,addnew(temp3,temp4));
			t3=clock()-t3;
			mytime[2]=mytime[2]+((double)(t1+t3))/CLOCKS_PER_SEC;
               // printf("(%s,%s)\n", f5,f6);
			fprintf(outputfile, "(%s,%s)\n", f5,f6);
               free(f5);
               free(f6);
			double d1=toDouble(A1);
			double d2=toDouble(B1);
			double d3=toDouble(A2);
			double d4=toDouble(B2);
			t2=clock();
			double real = d1*d3 - d2*d4;
			double cmplx = d1*d4 + d2*d3;
			t2=clock()-t2;
			gcctime[2]=gcctime[2]+((double)t2)/CLOCKS_PER_SEC;
			// printf("\t%f\t%f\n", mytime[counter],gcctime[counter]);
			countermul++;
			// printf("d=%f\n", d1);
		}
		else if(strcmp(token,"ABS")==0){
               // printf("ABS\n");
               char a1[1000],b1[1000];
			char a2[1000],b2[1000];
			char A[1000],B[1000];
               token =strtok(NULL,"\n");
               // printf("1=|%s|\n", token);
               int i=1;
               int c=0;
               while(token[i]!=','){
                    a1[c]=token[i];
				a2[c]=token[i];
				A[c++]=token[i++];
               }
               a1[c]='\0';
			a2[c]='\0';
			A[c]='\0';
               // printf("a1=|%s|\n", a1);
               i++;
               c=0;
               while(token[i]!=')'){
                    b1[c]=token[i];
				b2[c]=token[i];
				B[c++]=token[i++];
               }
               b1[c]='\0';
			b2[c]='\0';
			B[c]='\0';
			int len1=strlen(a1)+strlen(b1);
               char* asqr=(char*)malloc(2*(len1+1)*sizeof(char));
               char* bsqr=(char*)malloc(2*(len1+1)*sizeof(char));
			t1=clock();
			// printf("a=|%s|\n", a1);
			// printf("b=|%s|\n", b1);
               strcpy(asqr,mulnew(a1,a2));
               strcpy(bsqr,mulnew(b1,b2));
			// printf("asqr=%s\n", asqr);
			// printf("bsqr=%s\n", bsqr);
			t1=clock()-t1;
               int sizeasqr=strlen(asqr);
               int sizebsqr=strlen(bsqr);
               char aa[sizeasqr];
               char bb[sizebsqr];
               i=0;
               for(i=0; i<sizeasqr; i++){
                    aa[i]=asqr[i];
               }
               aa[i]='\0';
               i=0;
               for(i=0; i<sizebsqr; i++){
                    bb[i]=bsqr[i];
               }
               bb[i]='\0';
			int lenasqr=strlen(asqr);
			int lenbsqr=strlen(bsqr);
               free(asqr);
               free(bsqr);
               char* modsqr=(char*)malloc((lenasqr+lenbsqr)*sizeof(char));
			t2=clock();
               strcpy(modsqr,addnew(aa,bb));
			t2=clock()-t2;
               int sizemodsqr=strlen(modsqr);
               char modsqrarr[sizemodsqr];
               i=0;
               for(i=0; i<sizemodsqr; i++){
                    modsqrarr[i]=modsqr[i];
               }
               modsqrarr[i]='\0';
               free(modsqr);
               char* mod=(char*)malloc((lenasqr+lenbsqr)*sizeof(char));
			t3=clock();
               strcpy(mod,sqrtnew(modsqrarr));
			t3=clock()-t3;
               // printf("(%s,0)\n", mod);
			fprintf(outputfile, "(%s,0)\n", mod);
               free(mod);

			mytime[4]=mytime[4]+((double)(t1+t2+t3))/CLOCKS_PER_SEC;
			double d1=toDouble(A);
			double d2=toDouble(B);
			t4=clock();
			double temp5 = sqrt((d1*d2)+(d2*d2));
			t4=clock()-t4;
			gcctime[4]=gcctime[4]+((double)t4)/CLOCKS_PER_SEC;
			// printf("\t%f\t%f\n", mytime[counter],gcctime[counter]);
			counterabs++;
		}
          else if(strcmp(token,"QUOT")==0){
               // printf("QUOT\n");
			char a11[1000],b11[1000],a21[1000],b21[1000];
			char a12[1000],b12[1000],a22[1000],b22[1000];
			char a13[1000],b13[1000],a23[1000],b23[1000];
			char a14[1000],b14[1000],a24[1000],b24[1000];
			char A1[1000],B1[1000],A2[1000],B2[1000];
               token =strtok(NULL,"\n");
               // printf("1=|%s|\n", token);
               int i=1;
               int c=0;
               while(token[i]!=','){
                    a11[c]=token[i];
				a12[c]=token[i];
				a13[c]=token[i];
				a14[c]=token[i];
				A1[c++]=token[i++];
               }
               a11[c]='\0';
			a12[c]='\0';
			a13[c]='\0';
			a14[c]='\0';
			A1[c]='\0';
               // printf("a1=|%s|\n", a1);
               i++;
               c=0;
               while(token[i]!=')'){
                    b11[c]=token[i];
				b12[c]=token[i];
				b13[c]=token[i];
				b14[c]=token[i];
				B1[c++]=token[i++];
               }
               b11[c]='\0';
			b12[c]='\0';
			b13[c]='\0';
			b14[c]='\0';
			B1[c]='\0';
               // printf("b1=|%s|\n", b1);
               i=i+3;
               c=0;
               while(token[i]!=','){
                    a21[c]=token[i];
				a22[c]=token[i];
				a23[c]=token[i];
				a24[c]=token[i];
				A2[c++]=token[i++];
               }
               a21[c]='\0';
			a22[c]='\0';
			a23[c]='\0';
			a24[c]='\0';
			A2[c]='\0';
               // printf("a2=|%s|\n", a2);
               i++;
               c=0;
               while(token[i]!=')'){
                    b21[c]=token[i];
				b22[c]=token[i];
				b23[c]=token[i];
				b24[c]=token[i];
				B2[c++]=token[i++];
               }
               b21[c]='\0';
			b22[c]='\0';
			b23[c]='\0';
			b24[c]='\0';
			B2[c]='\0';
			bool isAzero=iszero(a21);
			bool isBzero=iszero(b21);
			if(isAzero && isBzero){
				// printf("CANNOT BE DIVIDED BY ZERO\n");
				fprintf(outputfile, "CANNOT BE DIVIDED BY ZERO\n");
			}
			else{
				int len1=strlen(a11)+strlen(b11);
				int len2=strlen(a21)+strlen(b21);
	               // printf("b2=|%s|\n", b2);
	               char* f1=(char*)malloc((len1+len2)*sizeof(char));
	               char* f2=(char*)malloc((len1+len2)*sizeof(char));
	               char* f3=(char*)malloc((len1+len2)*sizeof(char));
	               char* f4=(char*)malloc((len1+len2)*sizeof(char));
				t1=clock();
	               strcpy(f1,mulnew(a11,a21));
	               strcpy(f2,mulnew(b11,b21));
	               strcpy(f3,mulnew(a12,b22));
	               strcpy(f4,mulnew(b12,a22));
				t1=clock()-t1;
	               // printf("f1=|%s|\n", f1);
	               // printf("f2=|%s|\n", f2);
	               // printf("f3=|%s|\n", f3);
	               // printf("f4=|%s|\n", f4);
	               char temp1[strlen(f1)];
	               char temp2[strlen(f2)];
	               char temp3[strlen(f3)];
	               char temp4[strlen(f4)];
	               i=0;
	               for(i=0; i<strlen(f1); i++){
	                    temp1[i]=f1[i];
	               }
	               temp1[i]='\0';
	               i=0;
	               for(i=0; i<strlen(f2); i++){
	                    temp2[i]=f2[i];
	               }
	               temp2[i]='\0';
	               i=0;
	               for(i=0; i<strlen(f3); i++){
	                    temp3[i]=f3[i];
	               }
	               temp3[i]='\0';
	               i=0;
	               for(i=0; i<strlen(f4); i++){
	                    temp4[i]=f4[i];
	               }
	               temp4[i]='\0';
	               free(f1);
	               free(f2);
	               free(f3);
	               free(f4);
	               // printf("temp1=|%s|\n", temp1);
	               // printf("temp2=|%s|\n", temp2);
	               // printf("temp3=|%s|\n", temp3);
	               // printf("temp4=|%s|\n", temp4);
	               char* f5=(char*)malloc((len1+len2)*sizeof(char));
	               char* f6=(char*)malloc((len1+len2)*sizeof(char));
				t2=clock();
				// printf("temp4=%s temp3=%s\n", temp4, temp3);
	               strcpy(f5,addnew(temp1,temp2));
	               strcpy(f6,subnew(temp4,temp3));
				// printf("f5=%s\n", f5);
				// printf("f6=%s\n", f6);
				t2=clock()-t2;
	               // printf("(%s,%s)\n", f5,f6);
	               int sizef5=strlen(f5);
	               int sizef6=strlen(f6);
	               char f5arr[sizef5];
	               char f6arr[sizef6];
	               i=0;
	               for(i=0; i<sizef5; i++){
	                    f5arr[i]=f5[i];
	               }
	               f5arr[i]='\0';
	               i=0;
	               for(i=0; i<sizef6; i++){
	                    f6arr[i]=f6[i];
	               }
	               f6arr[i]='\0';
	               free(f5);
	               free(f6);
	               char* asqr=(char*)malloc((len1+len2)*sizeof(char));
	               char* bsqr=(char*)malloc((len1+len2)*sizeof(char));
				t3=clock();
	               strcpy(asqr,mulnew(a23,a24));
	               strcpy(bsqr,mulnew(b23,b24));
				// printf("asqr=%s\n", asqr);
				// printf("bsqr=%s\n", bsqr);
				t3=clock()-t3;
	               int sizeasqr=strlen(asqr);
	               int sizebsqr=strlen(bsqr);
	               char aa[sizeasqr];
	               char bb[sizebsqr];
	               i=0;
	               for(i=0; i<sizeasqr; i++){
	                    aa[i]=asqr[i];
	               }
	               aa[i]='\0';
	               i=0;
	               for(i=0; i<sizebsqr; i++){
	                    bb[i]=bsqr[i];
	               }
	               bb[i]='\0';
	               free(asqr);
	               free(bsqr);
	               char* modsqr=(char*)malloc((len1+len2)*sizeof(char));
				t4=clock();
	               strcpy(modsqr,addnew(aa,bb));
				// printf("modsqr=%s\n", modsqr);
				t4=clock()-t4;
	               int sizemodsqr=strlen(modsqr);
	               char modsqrarr1[sizemodsqr];
				char modsqrarr2[sizemodsqr];
	               i=0;
	               for(i=0; i<sizemodsqr; i++){
	                    modsqrarr1[i]=modsqr[i];
					modsqrarr2[i]=modsqr[i];
	               }
	               modsqrarr1[i]='\0';
				modsqrarr2[i]='\0';
	               free(modsqr);
	               char* aresult=(char*)malloc((len1+len2)*sizeof(char));
	               char* bresult=(char*)malloc((len1+len2)*sizeof(char));
				t5=clock();
				// printf("f5arr=%s\n", f5arr);
				// printf("m1=%s\n", modsqrarr1);
	               strcpy(aresult,divnew(f5arr,modsqrarr1));
				// printf("f6arr=%s\n", f6arr);
				// printf("m2=%s\n", modsqrarr2);
	               strcpy(bresult,divnew(f6arr,modsqrarr2));
				// printf("aresult=%s\n", aresult);
				// printf("bresult=%s\n", bresult);
				t5=clock()-t5;
	               // printf("(%s,%s)\n", aresult,bresult);
				fprintf(outputfile, "(%s,%s)\n", aresult,bresult);
	               free(aresult);
	               free(bresult);
				mytime[3]=mytime[3]+((double)(t1+t2+t3+t4+t5))/CLOCKS_PER_SEC;
				double d1=toDouble(A1);
				double d2=toDouble(B1);
				double d3=toDouble(A2);
				double d4=toDouble(B2);
				t6=clock();
				double modsqr1=sqrt(d3*d3+d4*d4);
				double real = (d1*d3 + d2*d4)/modsqr1;
				double cmplx = (d2*d3 - d1*d4)/modsqr1;
				t6=clock()-t6;
				gcctime[3]=gcctime[3]+((double)t6)/CLOCKS_PER_SEC;
				// printf("\t%f\t%f\n", mytime[counter],gcctime[counter]);
				counterdiv++;
			}
		}
	}
	if(counteradd>0){
		mytime[0]=mytime[0]/counteradd;
		gcctime[0]=gcctime[0]/counteradd;
	}
	if(countersub>0){
		mytime[1]=mytime[1]/countersub;
		gcctime[1]=gcctime[1]/countersub;
	}
	if(countermul>0){
		mytime[2]=mytime[2]/countermul;
		gcctime[2]=gcctime[2]/countermul;
	}
	if(counterdiv>0){
		mytime[3]=mytime[3]/counterdiv;
		gcctime[3]=gcctime[3]/counterdiv;
	}
	if(counterabs>0){
		mytime[4]=mytime[4]/counterabs;
		gcctime[4]=gcctime[4]/counterabs;
	}
	char* commandsForGnuplot[]={"set boxwidth 1","set xlabel \"(Instruction Type) ---->\"","set ylabel \"(Average time in us) ---->\"","set title \"Time Comparison Arbitrary Precision vs GCC Compiler\"","set style fill solid border -1","set style data histograms","plot \"data.txt\" using 2:xtic(1) title \"Arbitrary Precision\" lt rgb \"#40AF00\",\"\" using 3 title \"GCC\" lt rgb \"#403090\"","set term pngcairo","set output \"graph.png\"","set terminal png","replot","set output"};
	int noofcommands=12;
	FILE * temp = fopen("data.txt", "w");
	FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
	int i=0;
	fprintf(temp, "%s %lf %lf\n","ADD", mytime[0],gcctime[0]);
	fprintf(temp, "%s %lf %lf\n","SUB", mytime[1],gcctime[1]);
	fprintf(temp, "%s %lf %lf\n","PROD", mytime[2],gcctime[2]);
	fprintf(temp, "%s %lf %lf\n","QUOT", mytime[3],gcctime[3]);
	fprintf(temp, "%s %lf %lf\n","ABS", mytime[4],gcctime[4]);
	for(i=0; i<noofcommands; i++){
		if(i==8){
			fprintf(gnuplotPipe, "set output \"%s\"\n", grapharg);
		}
		else{
	     	fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]);
		}
	}
	return 0;
}
