#include<stdio.h>
#include <cs50.h>

int main (void)
{
    int size , i , j;
    do
    {
        size = get_int("what's the size ");

    }
    while(size <1 || size >8 );
    for (i = 0;i<size; i++)
    {
        for(j= 0; j< size ; j++)
        {
            if(size - i <=j)
            {
                printf("#");
                if(j==size-1)
                {
                    printf("  ");
                }
            }
            else
            {
                printf(" ");
            }
        }
    int counter = 0;
    do
    {
        printf("#");
        counter++;
    }
    while(counter<i);
    printf("\n");
    }


}
