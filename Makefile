
CC 		= gcc
FLAGS 	= -Wall
RM    	= /bin/rm -rf

all: fsh.c helper cd echo help kill nice pwd type ulimit 
	$(CC) $(FLAGS) -o fsh fsh.c helper.o cd.o echo.o help.o kill.o nice.o pwd.o type.o ulimit.o -lreadline

helper: helper.c
	$(CC) $(FLAGS) -c helper.c

cd: cd.c
	$(CC) $(FLAGS) -c cd.c

echo: echo.c
	$(CC) $(FLAGS) -c echo.c

help: help.c
	$(CC) $(FLAGS) -c help.c

kill: kill.c
	$(CC) $(FLAGS) -c kill.c

nice: nice.c
	$(CC) $(FLAGS) -c nice.c

pwd: pwd.c
	$(CC) $(FLAGS) -c pwd.c

type: type.c
	$(CC) $(FLAGS) -c type.c

ulimit: ulimit.c
	$(CC) $(FLAGS) -c ulimit.c

clean:
	$(RM) fsh *.o

install:
	sudo apt-get install libreadline6-dev