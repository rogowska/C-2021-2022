# Oliwia Rogowska
# Makefile
CC = gcc
CFLAGS = -Wall -ansi
LDFLAGS = -lm

TARGET = life



help:
	@echo "usage:"
	@echo "\tmake life: compiling the project with life as executable file"
	@echo "\tmake clean: removing all object and executable files"

life: life_main.o validate_user_input.o print_matrix.o generate_next_state.o count_neighbours.o
	$(CC) $(CFLAGS) -o $(TARGET) life_main.o validate_user_input.o print_matrix.o generate_next_state.o count_neighbours.o

life_main.o: life_main.c
	$(CC) $(CFLAGS) -c life_main.c

validate_user_input.o: validate_user_input.c
	$(CC) $(CFLAGS) -c validate_user_input.c

print_matrix.o: print_matrix.c
	$(CC) $(CFLAGS) -c print_matrix.c

generate_next_state.o: generate_next_state.c
	$(CC) $(CFLAGS) -c generate_next_state.c

count_neighbours.o: count_neighbours.c
	$(CC) $(CFLAGS) -c count_neighbours.c

clean:
	$(RM) *.o $(TARGET) 