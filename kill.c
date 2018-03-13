#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// TODO: 
//		- write parsing of multiple pids and options. 
//

int run_kill(int argc, char **argv)
{
	int result;

	if (argc == 1)
	{
		printf("kill: usage: kill [-s sigspec | -n signum | -sigspec] pid | jobspec ... or kill -l [sigspec]\n");
	}
	else if (argc == 2)
	{
		result = kill(atoi(argv[1]), SIGTERM);
	}
	else
	{
		result = kill(atoi(argv[2]), atoi(argv[1]));
	}

	return result;
}