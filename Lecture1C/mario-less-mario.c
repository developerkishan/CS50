#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n, i, j;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1);


    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if(j>=n-i){
                printf("#");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

}
