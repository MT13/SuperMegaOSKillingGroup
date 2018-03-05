#pragma once
#include <stdio.h>

typedef int (*command)(int, char **);

typedef struct builtin_cmd
{
	char *name;
	command function;
}fsh_builtin_cmd;

