#include <stdio.h>
#include <stdlib.h>

/*
    frogRiverOne
    https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/

*/

int solution(int X, int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int i=0;
    int j=0;
    int tempX[X];   // zmienna przechowujaca ciag arytmetyczny od 1+(X-1) *1 (1,2,3,4...,X)
    int checkTempX[X];  // tablica zawierajaca 1 lub 0 w zaleznosci czy znajdzie sie dany element
    int checkSol =0;    // sprawdzanie czy wszystkei elementy sa znalezione

    int searchCheck =0;    // zmienna ktora zatrzaskuje sie po znalezieniu pierwszej odpowiedniej wartosci
    int sol=0;   // zmienna przechowujaca najwyzszy indeks, rozwiazanie

    for(i=0; i<X; i++ )     // przypisanie 0 do tablicy aby potem zapelniac ja 1 jesli wszystkie komorki sie zapelnia znaczy ze wszystkie elementy sa takze mozna znalezc rozwaizanie
    {
        checkTempX[i]=0;
    }

    for(i=0; i<X; i++ )  //ciag (X, X-1, ...., 2,1)
    {
        tempX[i]=X-i;
    }

    for(i = 0; i<X; i++)   // petla dla kazdje z wartosci
    {
        searchCheck =0;
        for(j =0; j<N; j++)
        {
            if(A[j] == tempX[i] && searchCheck ==0)  // jesli zostal znaleziony element z naszego ciagu oraz jest on znaleziony jako pierwszy to
            {
                if(j >= sol)  // jesli jego index jest najwiekszy lub rowny juz nzalezionemu indexowi to przypisz do rozwiazania
                {
                    sol=j;
                }
                checkTempX[i]=1;  // zatrzaski zabezpieczajce znalezienie danego elementu oraz znalezienie danego elementu z najmniejszym indexem
                searchCheck =1;
            }
        }
    }

    for(i=0; i<X; i++ )  // dodawanie elementow z ciagu sprawdzajacego
    {
        checkSol = checkSol + checkTempX[i];
    }

    if(checkSol == X) //jesli dodane lementy = X to znaczy ze rzowiazanie istnieje
    {
        return sol;
    }
    else
    {
        return -1;
    }
}


int main()
{

    int X=5;
    int A[]={1,3,1,4,2,3,5,4};
    int N= 8;

    printf("%i\n", solution(X,A,N));
    return 0;
}
