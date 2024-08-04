CC = g++
SRC = main.cpp
TARGET = mylogger

lightchatcli: $(SRC) lib
	$(CC) -o $(TARGET) $(SRC) -L. -lMyLib

lib: logger.o func.o
	ar rc libMyLib.a logger.o func.o

liblogger: logger.cpp logger.h
	$(CC) -o logger.o logger.cpp -c

libfunc: func.cpp func.h
	$(CC) -o func.o func.cpp -c

clear:
	rm *.o *.a
