#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long credit_card = get_long("Number: ");
    int counter =0,last_digit=0 ,temp=0;
    int sum =0;
    int product = 0;
    int total = 0;

    while(credit_card > 0)
    {
        last_digit = credit_card %10;
        credit_card = credit_card /10;
        if(counter%2 == 0){
            sum = sum + last_digit;
        }
       else
       {
            temp = last_digit * 2;
            do{
                product = product + (temp%10) ;
                temp = temp /10;
            }while(temp > 0);
       }
       counter++;
    }
    total = product + sum;
    if(total % 10 ==0){
        printf("VALID\n");
    }
    else
        printf("INVALID\n");

}
