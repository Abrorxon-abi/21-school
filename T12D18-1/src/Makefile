CC=gcc
CFLAGS=-Wall -Werror -Wextra

all: clang cppcheck documentation_module.o main_module_entry_point.o1 print_module.o print_module main_module_entry_point.o2 documentation_module bst.o bst_create_test.o bst_create_test bst_traverse_test.o bst_create_test bst_insert_test  bst_traverse_test
 
clang: 
	cp ../materials/linters/.clang-format ./
	clang-format -i *.c *.h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem ./



documentation_module.o:
	$(CC) -c $(CFLAGS) documentation_module.c -o documentation_module.o

main_module_entry_point.o1:
	$(CC) -c $(CFLAGS) main_module_entry_point.c -o main_module_entry_point.o -DQuest_1

print_module.o:
	$(CC) -c $(CFLAGS) print_module.c -o print_module.o

print_module: documentation_module.o main_module_entry_point.o1 print_module.o
	$(CC) $(CFLAGS) documentation_module.o main_module_entry_point.o print_module.o -o ../build/Quest_1


main_module_entry_point.o2:
	$(CC) -c $(CFLAGS) main_module_entry_point.c -o main_module_entry_point.o -DQuest_2

documentation_module: documentation_module.o main_module_entry_point.o2 print_module.o
	$(CC) $(CFLAGS) documentation_module.o main_module_entry_point.o print_module.o -o ../build/Quest_2



bst.o:
	$(CC) -c $(CFLAGS) bst.c -o bst.o
bst_create_test.o:
	$(CC) -c $(CFLAGS) bst_create_test.c -o bst_create_test.o
bst_create_test: bst.o bst_create_test.o
	$(CC) $(CFLAGS) bst.o bst_create_test.o -o ../build/Quest_3




bst_insert_test.o:
	$(CC) -c $(CFLAGS) bst_insert_test.c -o bst_insert_test.o
bst_insert_test: bst.o bst_insert_test.o
	$(CC) $(CFLAGS) bst.o bst_insert_test.o -o ../build/Quest_4




bst_traverse_test.o: 
	$(CC) -c $(CFLAGS) bst_traverse_test.c -o bst_traverse_test.o 

bst_traverse_test: bst.o bst_traverse_test.o
	$(CC) $(CFLAGS) bst.o bst_traverse_test.o -o ../build/Quest_5



clean: all
	rm -rf *.o ../build/* .clang-format

rebuild: clean clang all 