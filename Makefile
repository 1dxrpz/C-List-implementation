libs=list.c
main=test.c
CC=gcc
CCW=x86_64-w64-mingw-gcc

all:
	$(CC) -o main $(libs) $(main)
	$(CC) -o main $(libs) $(main)

win: 
	$(CCW) -o main.exe $(libs) $(main)
	$(CCW) -o main.exe $(libs) $(main)
