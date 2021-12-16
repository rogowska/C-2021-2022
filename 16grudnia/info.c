/*unsigned int w bibliotece aby pozbyc sie minusa albo nie uzywanie maski - - poprzedni projekt*/

/*liczby przypadkowe, dwa generatory liczb losowych
od 0 do 1 liczby rzeczywiste srand48() czy generator jest jednorodny? sprawdzanie za pomoca histogramu
od 0 do rand_max liczby calkowite drand48() rand()
program ma przyjac 2 liczby ilosc na ktorej testuje funkcje
i na ile dzieli podprzedzialow aby stworzyc histogram
N - liczba punktow do ktorego przedzialu wpada punkt? n- liczba przedzialow
V                                                     V
zapamietuje w macierzy a wlasciwie to                int przedzialy[100]={0} mozna na sztywno bo tyle na pewno nie bedzie przedzialow
potrzebujemy wektora np 
double *przypadki = malloc(N*sizeof(double))
dynamiczna alokacja pamieci (uzycie ktorejs z mallocow)
petla od 0 do N
 przypadki[0]=drand48();
 mozna od razu sprawdzac w jaki przedzial wpada za pomoca sortowanie przez zliczanie
 liczba*liczba przedzialow = wskaznik do przedzialu
 przedzialy[przypadki[i]*n]++
na koncu wykres tyle gwiazdeczek aby najwiekszej liczbie odpowiadalo ilestam czegos petelka ktora ustala max liczb w przedziale, do niej sklauje [liczba gwiazdek(przedzialy[i]*78.0)/max +0,5] i zaokraglenia do liczby calkowitej czy obciecie? powinno byc zaokraglenie i robienie prinftu gwiazdeczek ile potrzeba na dany przedzial a na koncu new line i kolejny przedzial
nie patrzymy na liczby bo one beda prawie na pewno rozne

mozna uzyc czegos co wlacza funkcje 
#define _XOPEN_SOURCE
lub -D_XOPEN_SOURCE w kompilatorze*/

