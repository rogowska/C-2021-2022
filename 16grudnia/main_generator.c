/*Oliwia Rogowska*/

#define _XOPEN_SOURCE
#include <stdlib.h>
#include <stdio.h>

int main(){
    int ilosc_przypadkow, liczba_przedzialow, i;
    int przedzialy[100]={0};

printf("%s\n", "podaj ilosc liczb na ktorych chcesz przeprowadzic testy:");
scanf("%i", &ilosc_przypadkow);
printf("%s\n", "podaj liczbe przedzialow:");
scanf("%i", &liczba_przedzialow);

if(ilosc_przypadkow<liczba_przedzialow){
    printf("%s\n", "Podaj ilosc liczb wieksza od liczby przedzialow");
    return -1;
}
else if(ilosc_przypadkow==0 || liczba_przedzialow==0){
    printf("%s\n", "ilosc liczb i liczba przedzialow musza byc wieksze od 0");
    return -1;
}
for(i=0; i<ilosc_przypadkow; i++){}
drand48();
return 1;
}

