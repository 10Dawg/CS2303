CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = convert
OBJS = convert.o conversion.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

convert.o: convert.c conversion.h
	$(CC) $(CFLAGS) -c convert.c

conversion.o: conversion.c conversion.h
	$(CC) $(CFLAGS) -c conversion.c

clean:
	rm -f $(TARGET) $(OBJS)

run: $(TARGET)
	./$(TARGET) unit_conversions.txt same_names.txt
