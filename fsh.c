#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <readline/readline.h>
#include <readline/history.h>


int main(){
	char* input;
	while(1){
		input=readline("Free Shell: ");

		if(strncmp(input,"pwd",3)==0){
			char* a=getcwd(0,0);
			printf("%s\n",a);
			free(a);
		}
		if(strncmp(input,"cd",2)==0){
			int id=chdir(input+3);
			if(id==-1){}// such directory does not exist
		}
		if(strncmp(input,"exit",4)==0){
			if(strlen(input)==4)return 0;
			else return input[5]-'0';
		}
		free(input);
	}
	return 0;
}
