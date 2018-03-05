#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int run_nice(int argc, char **argv)
{
	int result;

	// TODO: This input part should be removed.

	char *input = "";

	for (int i = 0; i < argc; i++)
	{
		strcat(input, argv[i]);
		strcat(input, " ");
	}

	if (argc == 1)
	{
		result = nice(0);
		printf("%d\n", result);
	}
	else
	{
		result = nice(atoi(input));
		printf("%d\n", result);
	}

	return result;
}