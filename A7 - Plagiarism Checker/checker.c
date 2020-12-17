#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <ctype.h>
#include <math.h>
#include <dirent.h>

#define WASTE_WORD_COUNT 61

//word and its corresponding frequency in a file.
struct Word 
{
	char *word;
	int freq;
};

//checking a waste word.
bool iswasteword(char *token, char* waste_words[]){ 
	int i=0;
	for(i=0; i<WASTE_WORD_COUNT; i++){
		if(strcmp(waste_words[i],token)==0){ 
			return true;
		}
	}

	return false;
}

// used in vectorising the file
int alreadypresent(struct Word* vector,int i,char *token){ 
	int index=-1;
	int j=0;
	for(j=0; j<i; j++){
		if(strcmp(vector[j].word,token)==0){
			index=j;
			break;
		}
	}
	return index;
}

//to display the vector of file
void displayvector(struct Word* vector_file,int vector_size){ 
	printf("\n");
	int j=0;
	for(j=0; j<vector_size; j++){
		printf("%d := %s = %d\n", j, vector_file[j].word , vector_file[j].freq);
	}
}

//to vectorise a file given on a path, waste words.
struct Word* vectorize(char *path, char* waste_words[],int *vector_size_of_file){
	FILE * fp = fopen(path,"r");
	char *file_as_str= (char*)malloc(sizeof(char)*25000);
	if (fp == NULL)
   	{
		printf("Error while opening the file: %s\n",path);
		return NULL;
	}
	char ch='$';
	int i=0;
	bool last_was_special_character=false;
	//removing extra special characters
	while((ch = fgetc(fp)) != EOF){
		if(ch==',' || ch == '.' || ch=='?' || ch =='\'' || ch=='\"' || ch=='-' || ch=='[' || ch==']' || ch=='(' || ch==')' || ch=='\n' || ch == '\t' || ch==' ' || ch==':' || ch=='?' || ch==';' || ch=='!'){
			last_was_special_character=true;
		}
		else
		{	
			if(last_was_special_character==true){
				file_as_str[i++]=' ';
			}
			file_as_str[i++]=tolower(ch);
			last_was_special_character=false;
		}

	}
	file_as_str[i]='\0';

	struct Word* vector = (struct Word*)malloc(sizeof(struct Word)*4000);
	i=0;
	char* token;
	token = strtok(file_as_str, " ");
	// tokenizing the file
	while(token!=NULL){
		if(!iswasteword(token,waste_words)){
			int index = alreadypresent(vector,i,token);
			 if(index==-1){
			 	vector[i].freq=1;
			 	vector[i].word=token;
			 	i++;
			 }
			 else{
			 	vector[index].freq++;
			 }
		}
		token = strtok(NULL," ");
	}
	*vector_size_of_file = i;
	fclose(fp);
	return vector;
}

//handling plurals & past/present/future verb form
bool compare(char* s1,char * s2){
	if(s1[0]==s2[0] && s1[1]==s2[1] && s1[2]==s2[2] && s1[3]==s2[3]) return true;
	else return false;
}

//return frequency of a word in a vector.
int freqofwordinvector(struct Word* vector, int size, char *word){
	int i=0;
	for(i=0; i<size; i++){
		if(strlen(vector[i].word)>=5 && strlen(word)>=5 && compare(vector[i].word,word)) return vector[i].freq; 
		else if(strcmp(vector[i].word,word)==0) return vector[i].freq;
	}
	return 0;
}

//find cosine of two vectors.
double find_cosine(struct Word* vector1, struct Word* vector2, int size1, int size2){

	double cosine = 0.0;
	long d1=0,d2=0,d12=0;
	int i=0, j=0;

	for(i=0; i<size1; i++){
		int countinvecttor2 = freqofwordinvector(vector2,size2,vector1[i].word);
		d12 += vector1[i].freq * countinvecttor2;
	}

	for(i=0; i<size1; i++){
		d1 += vector1[i].freq * vector1[i].freq;
	}

	for(i=0; i<size2; i++){
		d2 += vector2[i].freq * vector2[i].freq;
	}

	if(d1==0 || d2==0) cosine=0.0;
	else cosine = d12 / (sqrt(d1) * sqrt(d2));

	return cosine;
}

int main(int argc, char* argv[]){

	//bag of waste words.
	char* waste_words[WASTE_WORD_COUNT] = {
	    "the", "of", "and", "a", "to", "in", "is", "you",
	    "that", "it", "he", "was", "for", "are", "as", "my"
	    "with", "his", "they", "i", "at", "be", "this", "have",
	    "from", "or", "one", "had", "by", "but", "were", "all",
	    "we", "your", "when", "can", "there", "an", "which", "she",
	    "do", "their", "if", "will", "up", "then", "these", "so",
	    "her", "his", "would", "him", "into", "has", "could", "may",
	    "get", "did", "its", "been", "than", "s"
	};

	// char *files[] = {
	// 	"./corpus_files/abf0704.txt",
	// 	"./corpus_files/abf70402.txt",
	// 	"./corpus_files/bef1121.txt",
	// 	"./corpus_files/bgt221.txt",
	// 	"./corpus_files/bmu5.txt",
	// 	"./corpus_files/bwa248.txt",
	// 	"./corpus_files/ckh80.txt",
	// 	"./corpus_files/ecu201.txt",
	// 	"./corpus_files/edo14.txt",
	// 	"./corpus_files/edo20.txt",
	// 	"./corpus_files/edo26.txt",
	// 	"./corpus_files/ehc229.txt",
	// 	"./corpus_files/erk185.txt",
	// 	"./corpus_files/esv254.txt",
	// 	"./corpus_files/hal10.txt",
	// 	"./corpus_files/hte42.txt",
	// 	"./corpus_files/jrf1109.txt",
	// 	"./corpus_files/prz100.txt",
	// 	"./corpus_files/sra31.txt",
	// 	"./corpus_files/sra42.txt",
	// 	"./corpus_files/sra107.txt",
	// 	"./corpus_files/sra119.txt",
	// 	"./corpus_files/sra126.txt",
	// 	"./corpus_files/tyc12.txt",
	// };

	char* files[30];
	char* filenames[30];
	int corpus_size = 0;

	char* corpus_dir = argv[2]; //Corpus directory name
	DIR *directory = opendir(corpus_dir);

	if(directory==NULL){
		printf("ERROR: Directory not found" ); 
        return 0; 
	}

	//Scanning Corpus directory to get corpus files(only .txt files)
	struct dirent* file_directory;
	while((file_directory = readdir(directory))!=NULL){
		char* filepath = (char*)malloc(sizeof(char)*50);
		int i=0;
		int j=0;
		for(i=0; i<strlen(corpus_dir); i++){
			filepath[j++]=corpus_dir[i];
		}
		filepath[j++]='/';

		for(i=0;i<strlen(file_directory->d_name);i++){
			filepath[j++] = file_directory->d_name[i];
		}
		//check type of file
		if(filepath[j-3]=='t' && filepath[j-2]=='x' && filepath[j-1]=='t'){
			files[corpus_size]=filepath;
			filenames[corpus_size++]=file_directory->d_name;
		}
	}

	int i_file=0; //file_counter
	
	//Corpus_vectors
	struct Word** vector_corpus_file = (struct Word**)malloc(sizeof(struct Word*)*corpus_size);
	int vector_size_of_corpus_files[corpus_size];

	//vectorizing the corpus_file and storing into array.
	for(i_file=0; i_file<corpus_size; i_file++){
		vector_corpus_file[i_file] = vectorize(files[i_file], waste_words, &vector_size_of_corpus_files[i_file]);
	}

	// Display the word vector of a particular file.
	// displayvector(vector_file[0],vector_size_of_corpus_files[0]);

	char *test_file=argv[1];

	struct Word* vector_test_file = (struct Word*)malloc(sizeof(struct Word)*4000);
	int vector_size_test_file;
	vector_test_file = vectorize(test_file,waste_words, &vector_size_test_file);

	// displayvector(vector_test_file,vector_size_test_file);
	// printf("%s\n", test_file_filtered);

	i_file=0;
	for(i_file=0; i_file<corpus_size; i_file++){
		double prob = find_cosine(vector_corpus_file[i_file],vector_test_file,vector_size_of_corpus_files[i_file],vector_size_test_file);
		printf("%s %0.2f\n", filenames[i_file] ,prob*100);
	}
		
	return 0;
}