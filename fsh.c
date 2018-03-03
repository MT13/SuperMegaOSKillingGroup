#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main(){
	char input[2048];

	while(1){
		scanf("%s",input);

		if(strcmp(input,"pwd")==0){
			char* a=getcwd(0,0);
			printf("%s\n",a);
			free(a);
		}
		if(strcmp(input,"cd")==0){
			scanf("%s",input);
			int id=chdir(input);
			if(id==-1){}// such directory does not exist
		}
		if(strcmp(input,"exit")==0){
			return 0;
		}
	}
	return 0;
}
