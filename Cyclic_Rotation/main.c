#include <stdio.h>
#include <stdlib.h>

struct Results {
  int * A;
  int N; // Length of the array
};

struct Results solution(int A[], int N, int K) {
    int i =0;
    int j =1;
    int tempj = j;
    int temp1;
    int counter=1;



    struct Results result;

    result.A = A;
    result.N = N;

    int length = result.N;
    int tempN = result.N;

    tempN = tempN -1;

    for(i =0; i <= tempN; i++)   // wyswietla tablice pierwotna
    {
        //printf("\n\r");
        printf("%i",result.A[i]);
    }

            if(K == length)
            {
                printf("\nJstem");

                return result;
            }
            else if(K > length)
            {
                K = K%length;

                printf("\n\r");
                printf("K = %i ",K);
            }

    for(i=K; i >= 1; i--)
    {
        counter =0;
        for(j=tempN; j >= 0; j--)
        {
            tempj=j;
       //     printf("\n%i",j);
            if(counter == 0)                //petle dzialaja od tylu w pierwszej iteracji ostatnia cyfra idzie do bufora temp1 aby na koncu wpisac wartosc w pierwsza komórka A[0]
            {
                temp1 = A[tempj];
                result.A[j] = result.A[--tempj];
    //            printf("\n_______________________");
     //           printf("\n%i",A[j]);
      //          printf("\n_______________________");
            }
            else if(counter == tempN)           // Gdy dochdozimi do A[0] wpisujemy tam wartosc z bufora
            {
                result.A[tempj]=temp1;
        //         printf("\n++++++++++++++++++++++++++++++++++++");
          //      printf("\n%i",A[tempj]);
            //    printf("\n++++++++++++++++++++++++++++++++++++");
            }
            else                  //Tu sie odbywa wpiswyanie w komorke A[N] wartosci z komorki wczesniejszej A[N-1] odbywa sie to wlasnie od tylu aby nie usuwac komorki ktora bedzie potrzeban do nastepnego wpisania
            {
                result.A[j] = result.A[--tempj];
        //          printf("\n-------------------------------------");
         //       printf("\n%i",A[j]);
          //      printf("\n-------------------------------------");
            }
            counter ++;
        }

    }

 /*   printf("\n\r");      // wyswietla tablice przerobiona
    for(i =0; i <=N; i++)
    {
        //printf("\n\r");
        printf("%i",result.A[i]);
    }

*/

    return result;
}

int main()
{

    int A[5] = {3,8,9,7,6};
    int N = 5;
    int K = 1;


    struct Results rezultat;


    rezultat = solution(A,N,K);

    printf("\n\r");
    int i =0;
      for(i =0; i <N; i++)
    {
        printf("%i", rezultat.A[i]);
    }


    return 0;
}
