#include <stdio.h>
#include <stdlib.h>

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)

    int i =0;
    int j =0;
    int swapA;
    int swapB;
    int tempA[N];

    for(i =0; i<N; i++)
    {
        tempA[i] = A[i];
    }

    for(i=0; i<N; i++)
    {
        for(j=1; j<N-1; j++)
        {
            if(tempA[j-1]>tempA[j])
            {
               swapA=tempA[j-1];
               swapB=tempA[j];
               tempA[j-1]= swapB;
               tempA[j] = swapA;
            }
        }
    }

    for(i=0; i<N-1; i++)
    {
        if(tempA[i]+1 == tempA[i+1])
        {

        }
        else
        {
           return tempA[i]+1;
        }
    }

    return 0;
}




int main()
{
    int A[] ={2,3,1,5};
    int N = 4;

    printf("%i\n",solution(A, N));
    return 0;
}
