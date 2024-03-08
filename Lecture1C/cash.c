#include <stdio.h>
#include <cs50.h>
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickel(int cents);
int calculate_pennies(int cents);

int main (void)
{
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);




    int change = 0;
    int quarters = calculate_quarters(cents);
    cents = cents - (quarters * 25);
    int dimes = calculate_dimes(cents);
    cents = cents - (dimes * 10);
    int nickel = calculate_nickel(cents);
    cents = cents - (nickel * 5);
    int pennies = calculate_pennies(cents);
    cents = cents - (pennies * 1);

    change = quarters + dimes + nickel + pennies;

    printf("%i \n",change);


}
 int calculate_quarters(int cents)
{
    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents = cents - 25;
    }
    return quarters;
}

 int calculate_dimes(int cents)
{
    int dimes = 0;
    while (cents >= 10)
    {
        dimes++;
        cents = cents - 10;
    }
    return dimes;
}
int calculate_nickel(int cents)
{
    int nickel = 0;
    while (cents >= 5)
    {
        nickel++;
        cents = cents - 5;
    }
    return nickel;
}
int calculate_pennies(int cents)
{
    int pennies = 0;
    while (cents >= 1)
    {
        pennies++;
        cents = cents - 1;
    }
    return pennies;
}

