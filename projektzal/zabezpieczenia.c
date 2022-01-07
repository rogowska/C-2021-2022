/*Oliwia Rogowska*/
/*@ZR 
 - propozycja: nazwa pliku wynikowego life
 - zmiana nazwy funkcji zabezpieczenia na inputValidator
 - przekazanie przez wskaźnik wartośći columns, rows, steps w funkcji inputValidator
 - nazewnictwo w języku angielskim
 - komunikacja z uzytkownikiem j.w.
 - zrezygnowanie z trybu interaktywnego na rzecz argumentów wywowałania z commandline
  getopt https://azrael.digipen.edu/~mmead/www/Courses/CS180/getopt.html
 - max value dla columns i rows 10000 - czas obliczeniowy rośnie do 13sec, wymagana pamięc ~800MB
 - propozycja na help:

life --help

usage:  life --columns --rows --steps [--delay]
    or
        life --tryout

Symulator game of 'Life' based on 23/3 Johna Conwaya rule with pseudo-random initial conditions.

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

int zabezpieczenia(int wiersze, int kolumny, int kroki){
// zabezpieczenia --> validate_user_input
// wiersze - row_amount / rows
// kolumny - columns / column_amount
// kroki --> steps / step amount
// można by było tu rzucić komentarz do funkcji w stylu: jeśli któryś z poniższych warunków zostanie spełniony, 
// to użytkownik otrzyma komunikat o błędzie i program zostanie zakończony
// jeśli parametry wejściowe podane przez użytkownika okażą się poprawne - program będzie kontynouwany
 if (wiersze<1){
     printf("Podaj dodatnia liczbe wierszy\n");
     return 0;
 }
 if (wiersze>50){
     printf("Podaj liczbe wierszy mniejsza lub rowna 50\n");
     return 0;
 }
 if (kolumny<1){
     printf("Podaj dodatnia liczbe kolumn\n");
     return 0;
 }
  if (kolumny>200){
     printf("Podaj liczbe kolumn mniejsza lub rowna 200\n");
     return 0;
 }
 if(kroki<1){
     printf("Podaj dodatnia liczbe krokow\n");
     return 0;
 }
 return 1;
}
