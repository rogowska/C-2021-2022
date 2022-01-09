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

life: validate_user_input.o print_matrix.o generate_next_state.o count_neighbours.o
	$(CC) $(CFLAGS) -o $(TARGET) life_main.c validate_user_input.o print_matrix.o generate_next_state.o count_neighbours.o

validate_user_input.o: validate_user_input.c validate_user_input.h
	$(CC) $(CFLAGS) -c validate_user_input.c

print_matrix.o: print_matrix.c print_matrix.h
	$(CC) $(CFLAGS) -c print_matrix.c

generate_next_state.o: generate_next_state.c generate_next_state.h
	$(CC) $(CFLAGS) -c generate_next_state.c

count_neighbours.o: count_neighbours.c count_neighbours.h
	$(CC) $(CFLAGS) -c count_neighbours.c

clean:
	$(RM) *.o $(TARGET) 