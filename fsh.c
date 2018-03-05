#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <readline/readline.h>
#include <readline/history.h>

static const char INPUT_ABOUT[] = "?";
static const char INPUT_CD[] = "cd";
static const char INPUT_PWD[] = "pwd";
static const char INPUT_EXIT[] = "exit";
static const char INPUT_ULIMIT[] = "ulimit";
static const char INPUT_NICE[] = "nice";
static const char INPUT_KILL[] = "kill";
static const char INPUT_TYPE[] = "type";
static const char INPUT_ECHO[] = "echo";
static const char INPUT_EXPORT[] = "export";


static const char STRING_ABOUT[] = "This is free shell!\n";

char* substring(char* input,int len){
	char* buffer=(char*)malloc(sizeof(char*)*(len+1));
	memcpy(buffer,input,len);
	buffer[len]='\0';
	return buffer;
}

int stringToInt(char* input,int start,int len){
	int code=0;
	int positive=1;
	if(input[start]=='-'){positive=-1;start++;}

	while(start!=len&&input[start]!=' '){
		code*=10;
		code+=(input[start]-'0');
		start++;
	}
	return code*positive;
}

void  signalKiller(int s){
	if (s == SIGINT){
    	signal(SIGINT, signalKiller);
	} else if (s == SIGTSTP){
		signal(SIGTSTP, signalKiller);
	}
}

void execute(char* input){
		int n=strlen(input);
		if(strncmp(input+n-3,INPUT_PWD,3)==0){
			char* dir=getcwd(0,0);
			printf("%s\n",dir);
			free(dir);
		}
		if(strncmp(input,INPUT_CD,2)==0){
			int id=chdir(input+3);
			if(id==-1){}// such directory does not exist
		}
		if(strlen(input)>=4&&strncmp(input,INPUT_EXIT,4)==0){
			int exitCode=0;
			if(strlen(input)>4)exitCode=input[5]-'0';
			free(input);
			exit(exitCode);
		}
		if(strncmp(input,INPUT_ABOUT,1)==0){
			printf(STRING_ABOUT);
		}
		if(strlen(input)>=4&&strncmp(input,INPUT_KILL,4)==0){
			n--;
			while(input[n]!=' ')n--; //add multiple spaces at the end case
			int a=stringToInt(input,5,strlen(input)); // add default signal case
			int b=stringToInt(input,n+1,strlen(input));
			kill(b,-a); // no idea why: signalId is negative but it should be positive
		}
		
		if(strncmp(input,INPUT_NICE,4)==0){
			if(strlen(input)==4)printf("%d\n",nice(0));
			else printf("%d\n",nice(stringToInt(input,8,strlen(input))));
		}

		free(input);
}


int main(int argc,char** argv){
	char* input;
	int n,previousPoint;

	signal(SIGINT, signalKiller);
	signal(SIGTSTP, signalKiller);

	while(1){
		previousPoint=0;
		if(argc==3)input=argv[2];
		else input=readline("free shell: ");

		add_history(input);

		n=strlen(input);
		//printf("%s\n",input);
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
