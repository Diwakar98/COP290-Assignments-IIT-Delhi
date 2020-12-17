#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char* addnew();
extern void absolute();
extern char* subnew();
extern char* mulnew();
extern int compare();
extern char* pownew();
extern char* divnew();
int main(int argc, char *argv[]){
	FILE *file = fopen("input1.txt","r");
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
			//printf("add");
			token =strtok(NULL," ");
			char a[1000],b[1000];
			strcpy(a,token);
			token =strtok(NULL,"\n");
			strcpy(b,token);
			char* result = (char*)malloc(3000000*sizeof(char));

			if(((a[0]=='-') && (b[0]=='-'))){
			      //printf("- -\n");

				char newa[strlen(a)-1];
				char newb[strlen(b)-1];
		          int j=0;
		          for(j=0; j<strlen(newa); j++){
		               newa[j]=a[j+1];
		          }
		          newa[j]='\0';
				j=0;
		          for(j=0; j<strlen(newb); j++){
		               newb[j]=b[j+1];
		          }
				newb[j]='\0';
		          // printf("%s %s %s\n",newa,a,b);
				printf("-");
			     strcpy(result, addnew(newa,newb));
			}
			else if(((a[0]=='-') && (b[0]!='-'))){
			     printf("- +\n");
				char newa[strlen(a)-1];
				int j=0;
				for(j=0; j<strlen(newa); j++){
					newa[j]=a[j+1];
				}
				newa[j]='\0';
				// printf("%s %s %s\n",newa,a,b);
			     strcpy(result, subnew(newa,b));
			}
			else if(((a[0]!='-') && (b[0]=='-'))){
			      printf("+ -\n");
				char newb[strlen(b)-1];
				int j=0;
		          for(j=0; j<strlen(newb); j++){
		               newb[j]=b[j+1];
		          }
				newb[j]='\0';
				// printf("%s %s\n",a,newb);
			     strcpy(result, subnew(a,newb));
			}
			else{
			     // printf("+ +\n");
			     strcpy(result, addnew(a,b));
			}

			// strcpy(result, addnew(a,b));
			printf("%s\n",result);
		}
		else if(strcmp(token,"ABS")==0){
			token = strtok(NULL,"\n");
			char a[1000];
			strcpy(a,token);
			absolute(a);
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
	}
	return 0;
}
