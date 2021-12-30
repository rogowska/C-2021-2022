#include <stdio.h>

int zabezpieczenia(int wiersze, int kolumny, int kroki){
 if (wiersze<1){
     printf("Podaj dodatnia liczbe wierszy\n");
     return 0;
 }
 if (kolumny<1){
     printf("Podaj dodatnia liczbe kolumn\n");
     return 0;
 }
 if(kroki<1){
     printf("Podaj dodatnia liczbe krokow\n");
     return 0;
 }
 return 1;
}