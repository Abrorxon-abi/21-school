.PHONY: door_struct list_test stack_test
CC =gcc
CFLAGS = -Wall -Werror -Wextra -c
Q1_SOURCES = dmanager_module.c
Q1_OBJECTS = $(Q1_SOURCES:.c=.o)

Q2_SOURCES = list.c list_test.c
Q2_OBJECTS = $(Q2_SOURCES:.c=.o)

Q3_SOURCES = stack.c stack_test.c
Q3_OBJECTS = $(Q3_SOURCES:.c=.o)

EXECUTABLE = main
QUEST = ../Build/Quest_
QUESTS = $(QUEST)1 $(QUEST)2 $(QUEST)3
all: door_struct list_test stack_test

door_struct: $(Q1_OBJECTS)
	$(CC) $(Q1_OBJECTS) -o $(QUEST)1

list_test: $(Q2_OBJECTS)
	$(CC) $(Q2_OBJECTS) -o $(QUEST)2

stack_test: $(Q3_OBJECTS)
	$(CC) $(Q3_OBJECTS) -o $(QUEST)3

rebuild: clean door_struct list_test stack_test

.o: .c
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm $(EXECUTABLE)
	-rm *.o
