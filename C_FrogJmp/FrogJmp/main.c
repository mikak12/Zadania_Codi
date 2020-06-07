#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*
    frogRiverOne
    https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/

*/

int solution(int X, int Y, int D) {
    int temp;
    int steps=0;
    temp = X;
    if(X!=Y)
    {
        do
        {
            temp = temp+D;
            steps++;
        }while(temp<Y);

    }
    else
    {

    }



    return steps;
}


int main()
{

    printf("%i\n", solution(10, 85, 30));
    return 0;
}
