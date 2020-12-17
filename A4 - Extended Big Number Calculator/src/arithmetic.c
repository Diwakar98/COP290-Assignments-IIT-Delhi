#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char* addnew();
extern char* absolute();
extern char* subnew();
extern char* mulnew();
extern int compare();
extern char* pownew();
extern char* divnew();
extern char* sqrtnew();
extern char* trim();
int main(int argc, char *argv[]){
	FILE *file = fopen(argv[1],"r");
	if(file==NULL){
		printf("File Not Found...");
		exit(0);
	}
	char line[1000];

	while(fgets(line,1000,file)!=NULL){
		//printf("%s\n",line);
		char *token=strtok(line," ");
		//printf("%s-",token);
		if(strcmp(token,"ADD")==0){
			token =strtok(NULL," ");
			char a[1000],b[1000];
			strcpy(a,token);
			token =strtok(NULL,"\n");
			// printf("|%d|\n",strlen(token));
			strcpy(b,token);
			// int p = compare(a,b);
			// printf("%s\n%s\n%d\n",a,b,p);
			char* result = (char*)malloc(3000000*sizeof(char));
			strcpy(result, addnew(a,b));
			printf("%s\n",result);
		}
		else if(strcmp(token,"ABS")==0){
			token = strtok(NULL,"\n");
			char a[1000];
			strcpy(a,token);
			char* result = (char*)malloc(3000000*sizeof(char));
			strcpy(result,absolute(a));
			printf("%s\n",result);
		}
		else if(strcmp(token,"SUB")==0){
			token =strtok(NULL," ");
			char a[1000],b[1000];
			strcpy(a,token);
			token =strtok(NULL,"\n");
			strcpy(b,token);
			char* result = (char*)malloc(3000000*sizeof(char));
			strcpy(result,subnew(a,b));
			printf("%s\n",result);
		}
		else if(strcmp(token,"MUL")==0){
			token =strtok(NULL," ");
			char a[1000],b[1000];
			strcpy(a,token);
			token =strtok(NULL,"\n");
			strcpy(b,token);
			// int p = compare(a,b);
			// printf("%s\n%s\n%d\n",a,b,p);
			char* result = (char*)malloc(3000000*sizeof(char));
			strcpy(result, mulnew(a,b));
			printf("%s\n",result);
		}
		else if(strcmp(token,"DIV")==0){
			token =strtok(NULL," ");
			char a[1000],b[1000];
			strcpy(a,token);
			token =strtok(NULL,"\n");
			strcpy(b,token);
			// int p = compare(a,b);
			// printf("%s\n%s\n%d\n",a,b,p);
			char* result = (char*)malloc(3000000*sizeof(char));
			strcpy(result, divnew(a,b));
			printf("%s\n",result);
		}
		else if(strcmp(token,"POW")==0){
			token =strtok(NULL," ");
			char a[1000],b[1000];
			strcpy(a,token);
			token =strtok(NULL,"\n");
			strcpy(b,token);
			// int p = compare(a,b);
			// printf("%s\n%s\n%d\n",a,b,p);
			char* result = (char*)malloc(3000000*sizeof(char));
			strcpy(result, pownew(a,b));
			printf("%s\n",result);
		}
		else if(strcmp(token,"SQRT")==0){
			token = strtok(NULL,"\n");
			char a[1000];
			strcpy(a,token);
			char* ans = (char*)malloc(3000000*sizeof(char));
			strcpy(ans,sqrtnew(a));
			printf("%s\n",ans);
		}
		else if(strcmp(token,"CMP")==0){
			token =strtok(NULL," ");
			char a[1000],b[1000];
			strcpy(a,token);
			token =strtok(NULL,"\n");
			strcpy(b,token);
			// int p = compare(a,b);
			// printf("%s\n%s\n%d\n",a,b,p);

			int f=compare(a,b) ;
			printf("%d\n",f);
		}
		else if(strcmp(token,"TRIM")==0){
			token = strtok(NULL,"\n");
			char a[1000];
			strcpy(a,token);
			char* ans = (char*)malloc(3000000*sizeof(char));
			strcpy(ans,trim(a));
			printf("%s\n",ans);
		}
	}
	return 0;
}
