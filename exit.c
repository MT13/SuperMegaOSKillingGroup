#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int run_exit(int argc, char **argv)
{
	if (argc == 1)
		exit(0)
	else 
		exit(argv[1]);
	
	return 0;
}