#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// TODO: 
//		- Organize code normally.
//		- Finish implementation of all echo usages.
//

void inputEcho(char * input){
	char* inputCopy=(char*)malloc(sizeof(char*)*(strlen(input) - 4));
	memcpy(inputCopy,input + 4,strlen(input) - 4);
	inputCopy[strlen(input) - 4]='\0';

	int found = -1;

	if (strlen(input) > 4){
		while (*inputCopy++){
			if (strncmp(&inputCopy[0],"$",1)==0){
				found = 1;
			} else if (strncmp(&inputCopy[0]," ",1) !=0){
				break;
			}
		}
	}

	if (found == 1){
		strtok (inputCopy," ");

		if (inputCopy != NULL){
			if (strncmp(inputCopy,"?", 1) == 0){
				// bolo shvilobilis status code unda ak
			} else {
				char * result = getenv(inputCopy);
				if (result != NULL){
					printf("%s\n", result);
				} else {
					printf("\n");
				}
			}
		} else {
			printf("%s\n", input+4);
		}
	} else {
		printf("%s\n", inputCopy);
	}
}

int run_echo(int argc, char **argv)
{
	char *input = "";

	for (int i = 0; i < argc; i++)
	{
		strcat(input, argv[i]);
		strcat(input, " ");
	}

	inputEcho(input);

	return 0;
}
