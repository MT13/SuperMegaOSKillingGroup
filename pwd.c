#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int run_pwd(int argc, char **argv)
{
	char *dir = getcwd(0,0);

	printf("%s\n", dir);

	return 0;
}