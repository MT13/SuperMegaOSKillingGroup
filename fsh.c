#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <readline/readline.h>
#include <readline/history.h>

char* substring(char* input,int len){
	char* buffer=(char*)malloc(sizeof(char*)*(len+1));
	memcpy(buffer,input,len);
	buffer[len]='\0';
	return buffer;
}

void execute(char* input){
		if(strncmp(input,"pwd",3)==0){
			char* a=getcwd(0,0);
			printf("%s\n",a);
			free(a);
		}
		if(strncmp(input,"cd",2)==0){
			int id=chdir(input+3);
			if(id==-1){}// such directory does not exist
		}
		if(strlen(input)>=4&&strncmp(input,"exit",4)==0){
			int exitCode=0;
			if(strlen(input)>4)exitCode=input[5]-'0';
			free(input);
			exit(exitCode);
		}
		free(input);
}


int main(int argc,char** argv){
	char* input;
	int n,previousPoint;

	while(1){
		previousPoint=0;
		if(argc==3)input=argv[2];
		else input=readline("free shell: ");

		n=strlen(input);

		for(int i=0;i<n;i++){
			if(input[i]==';'||i==n-1){
				if(i==n-1)i++;
				execute(substring(input+previousPoint,i-previousPoint));
				previousPoint=i+1;
			}
		}
		

		if(argc!=3)free(input);
		else break;
	}
	return 0;
}
