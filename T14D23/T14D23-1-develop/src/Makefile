CC=gcc
CFLAGS=-Wall -Werror -Wextra

all: clean clang cppcheck state_sort
 
clang: 
	cp ../materials/linters/.clang-format ./
	clang-format -i *.c *.h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

state_sort.o: 
	$(CC) -c $(CFLAGS) state_sort.c -o state_sort.o

state_sort: state_sort.o 
	$(CC) $(CFLAGS) state_sort.o -o ../build/state_sort  


clean:
	rm -rf *.o ../build/*