/*Oliwia Rogowska*/
#include <stdio.h>

int zabezpieczenia(int wiersze, int kolumny, int kroki){
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