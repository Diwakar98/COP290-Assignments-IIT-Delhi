#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <stdio.h>
#include <readline/readline.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define MAX_LIMIT_ARG 1000
#define SIZE 1000
#define BLUE "\e[38;7m"
#define HEADER "\e[33;1m"
#define WHITE "\x1b[0m"

char cwd[SIZE];
int count_args,count_args1;
bool exit_flag=false;

void intro(){
     printf("\n%s        #######        #######   #     #   ######  #         #      ",HEADER);
       printf("\n        #              #         #     #   #       #         #      ");
       printf("\n        #        ####  #######   #######   ######  #         #      ");
       printf("\n        #                    #   #     #   #       #         #      ");
       printf("\n        #######        #######   #     #   ######  #######   #######\n\n%s",WHITE);
}
void directory(){
     char cwd[SIZE];
     char* cwdpath=getcwd(cwd,SIZE);
     printf("%s\n",cwdpath);
}
void function_pwd(char* cwd)
{
    char temp[SIZE];
    char* path=getcwd(temp, sizeof(temp));
    if(path != NULL)
    {
        strcpy(cwd,temp);
        printf("%s\n",cwd);
    }
    else{
         printf("ERROR: No such directory exists.\n");
    }
}
void function_change_dir(char* final_wd){
     int success = chdir(final_wd);
     if(success==0){
          char temp[SIZE];
          char* path=getcwd(temp, sizeof(temp));
          strcpy(cwd,temp);
          printf("%s\n",cwd);
     }
     else{
          printf("ERROR: No such directory exists.\n");
     }
}
void function_rmdir(char* d){
     int success = rmdir(d);
     if(success==0){
          printf("%s: directory removed\n",d);
     }
     else{
          printf("ERROR: No such directory exists.\n");
     }
}
void function_mkdir(char* d){
     int stat = mkdir(d,0777);
     if(stat==0){
          printf("Directory created\n");
     }
     else{
          printf("ERROR: directory %s already exists.\n",d);
     }
}
void clearscreen(){
     system("clear");
}
void function_exit(){
     printf("<---------------ENDING C-SHELL--------------->\n");
     exit_flag=true;
}
void function_input(char command_input[], char splitted_arg[][SIZE]){
     printf("\n%sshell>%s  ",BLUE,WHITE);


     scanf("%[^\n]%*c", command_input);
     // printf("====%s====%d====\n",command_input,strlen(command_input));
     // printf("%d ",strlen(command_input));
     int j=0;
     count_args=0;
     for(int i=0; i<strlen(command_input); i++){
          // printf("%c-",command_input[i]);
          if(command_input[i]==' ' || command_input[i]=='\0' || command_input[i]=='\n' || command_input[i]=='\t'){
               splitted_arg[count_args][j]='\0';
               count_args++;
               j=0;
          }
          else{
               splitted_arg[count_args][j]=command_input[i];
               j++;
               if(i==(strlen(command_input)-1)){
                    splitted_arg[count_args][j]='\0';
                    count_args++;
                    j=0;
               }
          }
     }
}

void exeExecutable(char splitted_arg[SIZE][SIZE])
{
     char *executable_file=splitted_arg[0];
     char *char1=splitted_arg[1];
     char *file1=splitted_arg[2];
     char *char2=splitted_arg[3];
     char *file2=splitted_arg[4];
     // char *execute;
     // execute = malloc(strlen(executable_file)+strlen(char1)+ strlen(char2)+strlen(file1)+strlen(file2)+1);
     // memset( execute, '\0', sizeof(char)*strlen(execute) );
     // strcpy(execute,executable_file);
     // strcat(execute,char1);
     // strcat(execute,file1);
     // strcat(execute,char2);
     // strcat(execute,file2);
     // printf("\nExecuting: %s\n",execute);

     char *read[]={splitted_arg[0],NULL};
     pid_t pid = fork();
     if (pid == -1) {
         printf("\nFailed forking child..");
         return;
     }
     else if(pid == 0){
          int fd,fd1;
          FILE * fPtr;
          if(strcmp(char1,"<")==0 && strcmp(char2,">")==0){
                   fd = open(file1, O_RDONLY);
                   dup2(fd, 0) ;
                    fPtr = fopen(file2, "w");
                    int fd1 = open(file2, O_WRONLY);
                    dup2(fd1, 1) ;
                    char* c = malloc(1000);
                    execvp(read[0],read);
                    close(fd1);
                    close(fd);
          }
          else if(strcmp(char1,">")==0 && strcmp(char2,"<")==0){
                   fd = open(file2, O_RDONLY);
                   dup2(fd, 0) ;
                    fPtr = fopen(file1, "w");
                    int fd1 = open(file1, O_WRONLY);
                    dup2(fd1, 1) ;
                    char* c = malloc(1000);
                    execvp(read[0],read);
                    close(fd1);
                    close(fd);
          }
          else if(strcmp(char1,"<")==0 && strcmp(char2,"")==0){
               fd = open(file1, O_RDONLY);
               dup2(fd, 0) ;
                // fPtr = fopen(file2, "w");
                // int fd1 = open(file2, O_WRONLY);
                // dup2(fd1, 1) ;
                char* c = malloc(1000);
                execvp(read[0],read);
                // close(fd1);
                close(fd);
          }
          else if(strcmp(char1,">")==0 && strcmp(char2,"")==0){
                // fd = open(file1, O_RDONLY);
                // dup2(fd, 0) ;
                char *c1="AAA";
                printf("%s",c1);
                 fPtr = fopen(file1, "w");
                 int fd1 = open(file1, O_WRONLY);
                 dup2(fd1, 1) ;
                char* c = malloc(1000);
                execvp(read[0],read);
                 close(fd1);
                // close(fd);
          }
          else{
               char* c = malloc(1000);
               execvp(read[0],read);
          }
         exit(0);
     } else {
        // waiting for child to terminate
        wait(NULL);
        return;
    }
}
void exePipe(char splitted_arg[SIZE][SIZE], char command_input[SIZE])
{
      char *readfrom[] = {splitted_arg[0],NULL};
      char *writeto[] =  {splitted_arg[2],NULL};
      int pipefd[2];
      pid_t p1, p2;
      if (pipe(pipefd) < 0) {
          printf("\nPipe could not be initialized");
          return;
      }
      p1 = fork();
      if (p1 < 0) {
          printf("\nCould not fork");
          return;
      }
      if(p1==0){
           close(pipefd[0]);
           dup2(pipefd[1], STDOUT_FILENO);
           close(pipefd[1]);
           execvp(readfrom[0], readfrom);
           exit(0);
      }
      else{
           p2=fork();
           if(p2==0){
                close(pipefd[1]);
                dup2(pipefd[0], STDIN_FILENO);
                close(pipefd[0]);
                execvp(writeto[0], writeto);
                exit(0);
           }
           else{
                wait(NULL);
                wait(NULL);
           }
      }
}
int main(int argc, char* argv[]){
     //clearscreen();
     intro();
     //directory();
     function_pwd(cwd);
     do{
          char command_input[MAX_LIMIT_ARG];
          char splitted_arg[SIZE][SIZE];
          memset(splitted_arg, 0, sizeof(splitted_arg));
          memset(command_input, 0, sizeof(command_input));
          function_input(command_input,splitted_arg);

          // for(int i=0; i<count_args; i++){
          //      printf("##%s##\n",splitted_arg[i]);
          // }
          //printf("==%s==",splitted_arg[0]);
          if(strcmp(splitted_arg[0],"")==0){
               break;
          }
          if(strcmp(splitted_arg[0],"exit")==0){
               function_exit();
          }
          else if(strcmp(splitted_arg[0],"cd")==0){
               function_change_dir(splitted_arg[1]);
          }
          else if(strcmp(splitted_arg[0],"pwd")==0){
               printf("%s\n",cwd);
          }
          else if(strcmp(splitted_arg[0],"mkdir")==0){
               function_mkdir(splitted_arg[1]);
          }
          else if(strcmp(splitted_arg[0],"rmdir")==0){
               // printf("--%s",splitted_arg[1]);
               function_rmdir(splitted_arg[1]);
          }
          else if(strcmp(splitted_arg[0],"fork")==0){
               printf("\nFORKING");
               fork();
          }

          else{
               // printf("A\n");
               bool tobepiped=false;
               for(int i=0; i<strlen(command_input); i++){
                    if(command_input[i]=='|'){
                         // printf("%d = %s\n",i,splitted_arg[i]);
                         tobepiped = true;
                         break;
                    }
               }

               if(tobepiped==false){
                    // printf("A\n");
                    exeExecutable(splitted_arg);
               }
               else{

                     exePipe(splitted_arg,command_input);
               }

               memset(splitted_arg, 0, sizeof(splitted_arg));
               memset(command_input, 0, sizeof(command_input));
               // printf("\nEXECUTED");
          }

     }while(exit_flag==false);
     return 0;
}
