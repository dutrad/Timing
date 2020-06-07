
CC = g++
CFLAGS  = -g -Wall

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
default: Main

Main: Logger.o Timer.h
	$(CC) $(CFLAGS) -o Main Logger.o

#Timer.o:  Timer.h Logger.o
#	$(CC) $(CFLAGS) -c Timer.h

Logger.o:  Logger.cpp Logger.hpp
	$(CC) $(CFLAGS) -c Logger.cpp

clean: 
	$(RM) count *.o *~