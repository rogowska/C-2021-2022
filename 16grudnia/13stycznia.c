
/*sortowanie i pomiar czasu sortowanie raz qsort wbudowany a bubble napiszemy próbki i sprawdzam róznice miedzy koejnymi (niearest neighbour). jesli zmienna x to zmienna losowa
deltaxi = xi+1-xi . histogram na ilustam przedzialach dla roznicy iksow
roznic jest o 1 mniej niz samych wartosci, wiec skrocimy petle
roznica przypadki[i+1]-przypadki[i]

jak wywolac qsort
i napisac funkcje porownujaca dla niego
jak zmierzyc czas wykonania kawalka kodu 
napisac wlasny bubblesort i qsort, dopisac je - ktore biora juz tylko dwa arguemt, macierz i rozmiar, i powinnismy sortowac w tej samej tablicy
czasy dla 3 na jednym wykresie, najlepiej dopasowac funkcje do nich na wzglad od liczby przypadkow...?

przypadki[i] - mamy ja posortowac
qsort(*przypadki[0], ilosc elementow, sizeof(double), porownywanie)

mierzenie czasu - clock_t tp, tk (zmiennie dwie)
tp = clock();
tk = clock();
double czas sortowania = (tk - tp)/(double)CLOCKS_PER_SEC; 


int porowywanie(const void *x1, const void *x2){
    if (*(double*x1)==*(double*x2)){
        return 0;
    }
    if (*(double*x1)>*(double*x2)){
        return 1;
    }
    return -1}
} - zwraca 1, 0 lub -1 zaleznie od tg czy arguemnt pierwszy jest wiekszy mniejszy lub rowny ma sortowac rosnaco

bubblesort(){

}
*/

