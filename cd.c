#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DEBUG

int run_cd(int argc, char **argv)
{
	int result;

	if (argc == 1)
	{
		#ifdef DEBUG
		printf("%s\n", "in cd: arc == 1");
		#endif

		result = chdir("~");
	}
	else
	{
		#ifdef DEBUG
		printf("%s\n", "in cd: argc > 1");
		#endif
		
		result = chdir(argv[1]);
	}

	return result;
}