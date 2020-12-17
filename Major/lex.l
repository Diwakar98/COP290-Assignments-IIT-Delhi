%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <ctype.h>
#include <math.h>
#include <dirent.h>
#include <stdbool.h>

int a30=0;
int b30=0;
int c30=0;
int d30=0;
int len30=0;
int no_of_word_in_sentence30=0;
int punctuation_count30=0;
bool sentence_ended30=false;
static char* word30;
%}

%%

[a-z]|[A-Z]|[0-9]  	{
					word30[len30] = yytext[0];
					len30++;
				}
(".")(" ") {
			punctuation_count30++;
			sentence_ended30=true;
			if(no_of_word_in_sentence30>=10){
				d30 = d30 + punctuation_count30;
			}
			punctuation_count30=0;
			no_of_word_in_sentence30=0;
			int i30=0;
			int match_name30=0;
			bool name30[] = {false,false,false,false,false,false,false,false,false,false,false,false};
					for(i30=0; i30<len30; i30++){
						if(word30[i30]=='D' && name30[0]==false){
							name30[0]=true;
							match_name30++;
						}
						if(word30[i30]=='I' && name30[1]==false){
							name30[1]=true;
							match_name30++;
						}
						if(word30[i30]=='W' && name30[2]==false){
							name30[2]=true;
							match_name30++;
						}
						if(word30[i30]=='A' && name30[3]==false){
							name30[3]=true;
							match_name30++;
						}
						if(word30[i30]=='K' && name30[4]==false){
							name30[4]=true;
							match_name30++;
						}
						if(word30[i30]=='R' && name30[5]==false){
							name30[5]=true;
							match_name30++;
						}
						if(word30[i30]=='d' && name30[6]==false){
							name30[6]=true;
							match_name30++;
						}
						if(word30[i30]=='i' && name30[7]==false){
							name30[7]=true;
							match_name30++;
						}
						if(word30[i30]=='w' && name30[8]==false){
							name30[8]=true;
							match_name30++;
						}
						if(word30[i30]=='a' && name30[9]==false){
							name30[9]=true;
							match_name30++;
						}
						if(word30[i30]=='k' && name30[10]==false){
							name30[10]=true;
							match_name30++;
						}
						if(word30[i30]=='r' && name30[11]==false){
							name30[11]=true;
							match_name30++;
						}
						if(match_name30>=3){
							c30++;
							break;
						}
					}
			if(len30==1) a30++;
			else if(len30==3) b30++;
			word30 = NULL;
			word30 = (char*)malloc(sizeof(char)*20);
			len30=0;
		}
("?")(" ") {
			punctuation_count30++;
			sentence_ended30=true;
			if(no_of_word_in_sentence30>10){
				d30 = d30 + punctuation_count30;
			}
			punctuation_count30=0;
			no_of_word_in_sentence30=0;
			int i30=0;
			int match_name30=0;
			bool name30[] = {false,false,false,false,false,false,false,false,false,false,false,false};
					for(i30=0; i30<len30; i30++){
						if(word30[i30]=='D' && name30[0]==false){
							name30[0]=true;
							match_name30++;
						}
						if(word30[i30]=='I' && name30[1]==false){
							name30[1]=true;
							match_name30++;
						}
						if(word30[i30]=='W' && name30[2]==false){
							name30[2]=true;
							match_name30++;
						}
						if(word30[i30]=='A' && name30[3]==false){
							name30[3]=true;
							match_name30++;
						}
						if(word30[i30]=='K' && name30[4]==false){
							name30[4]=true;
							match_name30++;
						}
						if(word30[i30]=='R' && name30[5]==false){
							name30[5]=true;
							match_name30++;
						}
						if(word30[i30]=='d' && name30[6]==false){
							name30[6]=true;
							match_name30++;
						}
						if(word30[i30]=='i' && name30[7]==false){
							name30[7]=true;
							match_name30++;
						}
						if(word30[i30]=='w' && name30[8]==false){
							name30[8]=true;
							match_name30++;
						}
						if(word30[i30]=='a' && name30[9]==false){
							name30[9]=true;
							match_name30++;
						}
						if(word30[i30]=='k' && name30[10]==false){
							name30[10]=true;
							match_name30++;
						}
						if(word30[i30]=='r' && name30[11]==false){
							name30[11]=true;
							match_name30++;
						}
						if(match_name30>=3){
							c30++;
							break;
						}
					}
			if(len30==1) a30++;
			else if(len30==3) b30++;
			word30 = NULL;
			word30 = (char*)malloc(sizeof(char)*20);
			len30=0;
		}
("."|","|"?"|"!"|";"|":"|"("|")"|"["|"]"|"-"|"\'"|"\"")
				{
					punctuation_count30++;
				}


(" "|"\t"|"\n")	{
					no_of_word_in_sentence30++;
					int i30=0;
					int match_name30=0;
					bool name30[] = {false,false,false,false,false,false,false,false,false,false,false,false};
					for(i30=0; i30<len30; i30++){
						if(word30[i30]=='D' && name30[0]==false){
							name30[0]=true;
							match_name30++;
						}
						if(word30[i30]=='I' && name30[1]==false){
							name30[1]=true;
							match_name30++;
						}
						if(word30[i30]=='W' && name30[2]==false){
							name30[2]=true;
							match_name30++;
						}
						if(word30[i30]=='A' && name30[3]==false){
							name30[3]=true;
							match_name30++;
						}
						if(word30[i30]=='K' && name30[4]==false){
							name30[4]=true;
							match_name30++;
						}
						if(word30[i30]=='R' && name30[5]==false){
							name30[5]=true;
							match_name30++;
						}
						if(word30[i30]=='d' && name30[6]==false){
							name30[6]=true;
							match_name30++;
						}
						if(word30[i30]=='i' && name30[7]==false){
							name30[7]=true;
							match_name30++;
						}
						if(word30[i30]=='w' && name30[8]==false){
							name30[8]=true;
							match_name30++;
						}
						if(word30[i30]=='a' && name30[9]==false){
							name30[9]=true;
							match_name30++;
						}
						if(word30[i30]=='k' && name30[10]==false){
							name30[10]=true;
							match_name30++;
						}
						if(word30[i30]=='r' && name30[11]==false){
							name30[11]=true;
							match_name30++;
						}
						if(match_name30>=3){
							c30++;
							break;
						}
					}

					word30 = NULL;
					word30 = (char*)malloc(sizeof(char)*20);
					if(len30==1) a30++; 
					else if(len30==3) b30++;
					len30=0;
				}

%%

void yyerror(char *s) {
     fprintf(stderr,"%s\n", s);
}
int yywrap(){
    return 1;
}
int main(int argc, char* argv[]){
	word30 =(char*)malloc(sizeof(char)*20);
	char* f1 = argv[1];
	extern FILE *yyin;
	yyin = fopen(f1,"r");
	
	yylex();
	printf("\n\n%d %d %d %d\n",a30,b30,c30,d30);
	int a1=a30; a30=0;
	int b1=b30; b30=0;
	int c1=c30; c30=0;
	int d1=d30; d30=0;

	char* f2 = argv[2];
	yyin = fopen(f2,"r");
	yylex();
	printf("\n\n%d %d %d %d\n",a30,b30,c30,d30);
	int a2=a30;
	int b2=b30;
	int c2=c30;
	int d2=d30;
	printf("\n");

	FILE *data;
	data = fopen("data.txt","w");
	fprintf(data,"parameter %s %s\na %d %d\nb %d %d\nc %d %d\nd %d %d\n",f1,f2,a1,a2,b1,b2,c1,c2,d1,d2);

	FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");

	fprintf(gnuplotPipe,  "set output \"graph.png\" \n");
	fprintf(gnuplotPipe,  "set xtics rotate out \n");
	fprintf(gnuplotPipe,  "set style data histogram \n");
	fprintf(gnuplotPipe,  "set style histogram clustered \n");
	fprintf(gnuplotPipe,  "set style fill solid \n");
	fprintf(gnuplotPipe,  "set xlabel \"parameter--->\" \n");
	fprintf(gnuplotPipe,  "set ylabel \"value--->\" \n");
	fprintf(gnuplotPipe,  "plot for [COL=2:3] \'data.txt\' using COL:xticlabels(1) title columnheader \n");


	return 0;
}