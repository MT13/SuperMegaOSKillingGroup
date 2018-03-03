all: 
	sudo apt-get install libreadline-dev 
	gcc fsh.c -o fsh -lreadline
