G=gcc -Wall -Werror -Wextra

all: state_sort state_search clear_state
state_sort: 
	$(G) state_sort.c -o ../build/Quest1

state_search:
	$(G) state_search.c -o ../build/Quest2
	
clear_state:
	$(G) clear_state.c -o ../build/Quest3

clean:
	rm -rf ../build/*
