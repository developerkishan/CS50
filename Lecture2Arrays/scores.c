#include<stdio.h>
#include<cs50.h>
float calculate_average(int length , int arrays[]);

const int size = 4;

int main(void)
{
    int arrays[size];

    for(int i = 0; i < size; i++){
        arrays[i] = get_int("score: ");

    }
    printf("the average is : %f " , calculate_average(size , arrays));
}
float calculate_average(int length , int arrays[]){
    int total =0;
    for(int i =0; i < length ; i ++){
         total = total + arrays[i];
    }
    return (float)total/length;
}
