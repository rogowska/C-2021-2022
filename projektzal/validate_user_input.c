/*Oliwia Rogowska*/
/*@ZR 
 - propozycja: nazwa pliku wynikowego life
 - przekazanie przez wskaźnik wartośći columns, rows, steps w funkcji inputValidator
 - zrezygnowanie z trybu interaktywnego na rzecz argumentów wywowałania z commandline
  getopt https://azrael.digipen.edu/~mmead/www/Courses/CS180/getopt.html
 - propozycja na help:

life --help

usage:  life --columns --rows --steps [--delay]
    or
        life --tryout

Symulator game of 'Life' based on 23/3 John Conway rule with pseudo-random initial conditions.

Mandatory arguments to long options are mandatory for short options too.

       -c, --columns=n
              column size of board as positive value in range <1-10000>

       -d, --delay=n
              delay in seconds between printing current board (default 1)

       -h, --help
              display this help and exit

       -r, --rows=n
              rows size of board as positive value in range <1-10000>

       -s, --steps=n
              number of simulation steps, positive natural number

       -t, --tryout
              run demo, predifine usaged arguments: -c 40 -r 20 -s 100

*/

#include <stdio.h>

int validate_user_input(int row_amount, int column_amount, int step_amount){
       
/*if any of the conditions below are fullfilled, program ends*/
 if (row_amount<1){
     printf("Value or row amount must be positive. Exiting...\n");
     return 0;
 }
 if (row_amount>10000){
     printf("Value of row amount must be under 10000. Exiting...\n");
     return 0;
 }
 if (column_amount<1){
     printf("Value of column amount must be positive. Exiting...\n");
     return 0;
 }
  if (column_amount>10000){
     printf("Value of column amount must be under 10000. Exiting...\n");
     return 0;
 }
 if(step_amount<1){
     printf("Value of step amount must be positive. Exiting...\n");
     return 0;
 }
 return 1;
}
