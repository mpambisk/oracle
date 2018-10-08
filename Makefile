OBJS	= main.o list.o tree.o bloom.o
SOURCE	= main.c list.c tree.c bloom.c
HEADER	= list.h tree.h bloom.h hash.h oracle.h
OUT		= invoke-oracle
CC		= gcc
FLAGS	= -L . -loracle_v2 -lhash 

all : $(OBJS)
	gcc -o $(OUT) $(SOURCE) $(FLAGS) -g3


clean :
	rm -f $(OBJS) 	$(OUT)	
