.PHONY: STRLEN STRCMP STRCPY STRCAT

CC = gcc
CFLAGS = -Wall -Werror -Wextra -c
SOURCES = s21_string_test.c s21_string.c
OBJECTS = $(SOURCES:.c=.o)
OBJ = s21_string_test.c s21_string.c
EXECUTABLE = main
QUESTS = Quest_1 Quest_2 Quest_3 Quest_4 Quest_5 Quest_6

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

rebuild: clean all

strlen_tests: STRLEN
	$(CC) $(OBJECTS) -o ../build/Quest_1

strcmp_tests: STRCMP
	$(CC) $(OBJECTS) -o ../build/Quest_2

strcpy_tests: STRCPY
	$(CC) $(OBJECTS) -o ../build/Quest_3

strcat_tests: STRCAT
	$(CC) $(OBJECTS) -o ../build/Quest_4

strchr_test: STRCHR
	$(CC) $(OBJECTS) -o ../build/Quest_5

strstr_test: STRSTR
	$(CC) $(OBJECTS) -o ../build/Quest_6

STRLEN:
	$(CC) -DSTRLEN $(CFLAGS) -c s21_string_test.c -o s21_string_test.o
	$(CC) -DSTRLEN $(CFLAGS) -c s21_string.c -o s21_string.o

STRCMP:
	$(CC) -DSTRCMP $(CFLAGS) -c s21_string_test.c -o s21_string_test.o
	$(CC) -DSTRCMP $(CFLAGS) -c s21_string.c -o s21_string.o

STRCPY:
	$(CC) -DSTRCPY $(CFLAGS) -c s21_string_test.c -o s21_string_test.o
	$(CC) -DSTRCPY $(CFLAGS) -c s21_string.c -o s21_string.o

STRCAT:
	$(CC) -DSTRCAT $(CFLAGS) -c s21_string_test.c -o s21_string_test.o
	$(CC) -DSTRCAT $(CFLAGS) -c s21_string.c -o s21_string.o

STRCHR:
	$(CC) -DSTRCHR $(CFLAGS) -c s21_string_test.c -o s21_string_test.o
	$(CC) -DSTRCHR $(CFLAGS) -c s21_string.c -o s21_string.o

STRSTR:
	$(CC) -DSTRSTR $(CFLAGS) -c s21_string_test.c -o s21_string_test.o
	$(CC) -DSTRSTR $(CFLAGS) -c s21_string.c -o s21_string.o

.o: .c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm $(OBJECTS)
	-rm $(EXECUTABLE)
	-rm $(QUESTS)
