/*
    Testy algorytmu dla automatu komórkowego - gra w życie;
    Mamy tablicę 2D w wymiarach 4x4.
*/

/* W poniższych przypadkach komórką, której żywotność badamy będzie odpowiednio*/
/* Komórka brzegowa [0,1]
    0000
    X000
    0000
    0000
*/
/*Żywa, <2 sąsiadów*/
macierz_current[0][0] = 0;
macierz_current[0][1] = 1;
macierz_current[0][2] = 0;
macierz_current[0][3] = 0;
macierz_current[1][0] = 0;
macierz_current[1][1] = 0;
macierz_current[1][2] = 0;
macierz_current[1][3] = 0;
macierz_current[2][0] = 0;
macierz_current[2][1] = 0;
macierz_current[2][2] = 0;
macierz_current[2][3] = 0;
macierz_current[3][0] = 0;
macierz_current[3][1] = 0;
macierz_current[3][2] = 0;
macierz_current[3][3] = 0;

/*     
    Komórka brzegowa [0,1]
    0000
    X000
    0000
    0000
Żywa, <2 sąsiadów - umiera
1 sąsiad*/
macierz_current[0][0] = 1; 
macierz_current[0][1] = 1; 
macierz_current[0][2] = 0;
macierz_current[0][3] = 0;
macierz_current[1][0] = 0;
macierz_current[1][1] = 0;
macierz_current[1][2] = 0;
macierz_current[1][3] = 0;
macierz_current[2][0] = 0;
macierz_current[2][1] = 0;
macierz_current[2][2] = 0;
macierz_current[2][3] = 0;
macierz_current[3][0] = 0;
macierz_current[3][1] = 0;
macierz_current[3][2] = 0;
macierz_current[3][3] = 0;



/*
    Komórka brzegowa [0,2]
    0000
    0000
    X000
    0000
Martwa, <3 sąsiadów - nadal martwa*/
macierz_current[0][0] = 0; 
macierz_current[0][1] = 1; 
macierz_current[0][2] = 0;
macierz_current[0][3] = 0;
macierz_current[1][0] = 0;
macierz_current[1][1] = 0;
macierz_current[1][2] = 1;
macierz_current[1][3] = 0;
macierz_current[2][0] = 0;
macierz_current[2][1] = 0;
macierz_current[2][2] = 0;
macierz_current[2][3] = 0;
macierz_current[3][0] = 0;
macierz_current[3][1] = 0;
macierz_current[3][2] = 0;
macierz_current[3][3] = 0;




/*     
    Komórka brzegowa [1,0]
    0X00
    0000
    0000
    0000
Żywa, 2 sąsiadów - pozostaje żywa*/

/*
    Komórka brzegowa [2,0]
    00X0
    0000
    0000
    0000
Martwa, 3 sąsiadów - ożywa*/

/* 
    Komórka brzegowa [1,3]
    0000
    0000
    0000
    0X00
Żywa, 3 sąsiadów - pozostaje żywa*/

/*
    Komórka brzegowa [2,3]
    0000
    0000
    0000
    00X0
Martwa, >3 sąsiadów - nadal martwa*/

/* 
    Komórka brzegowa [3,1]
    0000
    000X
    0000
    0000
Żywa, >3 sąsiadów - umiera z zatłoczenia*/


/*
-------------------------------------------------------------------
Komórki narożne
*/
/* Komórka narożna [0,0]
    X000
    0000
    0000
    0000
Żywa, <2 sąsiadów - umiera*/

/*Martwa, <3 sąsiadów - nadal martwa*/

/* Komórka narożna [0,3]
    0000
    0000
    0000
    X000
Żywa, 2 sąsiadów - pozostaje żywa*/

/*Martwa, 3 sąsiadów - ożywa*/

/* Komórka narożna [3,0]
    000X
    0000
    0000
    0000
Żywa, 3 sąsiadów - pozostaje żywa*/

/*Martwa, >3 sąsiadów - nadal martwa*/

/* Komórka narożna [3,3]
    0000
    0000
    0000
    000X
Żywa, >3 sąsiadów - umiera z zatłoczenia*/

/*
--------------------------------------------------------------------------
Komórki środkowe
*/


/* Komórka środkowa [1,1]
    0000
    0X00
    0000
    0000
Żywa, <2 sąsiadów - umiera*/

/*Martwa, <3 sąsiadów - nadal martwa*/

/* Komórka środkowa [1,2]
    0000
    0000
    0X00
    0000
Żywa, 2 sąsiadów - pozostaje żywa*/

/*Martwa, 3 sąsiadów - ożywa*/

/* 
    Komórka środkowa [2,1]
    0000
    00X0
    0000
    0000
Żywa, 3 sąsiadów - pozostaje żywa*/

/*Martwa, >3 sąsiadów - nadal martwa*/

/*
    Komórka środkowa [2,2]
    0000
    0000
    00X0
    0000
Żywa, >3 sąsiadów - umiera z zatłoczenia*/

3 kroki do przeprowadzenia

0111
0101
0000
0110

