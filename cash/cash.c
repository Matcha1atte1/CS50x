#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{

    // prompt user for integer change owed in cents
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    // calculate how many quarters to give customer
    int quarters = calculate_quarters(cents);
    cents = cents - (quarters * 25);

    // calculate how many dimes to give customer
    int dimes = calculate_dimes(cents);
    cents = cents - (dimes * 10);

    // calculate how many nickels to give customer
    int nickels = calculate_nickels(cents);
    cents = cents - (nickels * 5);

    // calculate how many pennies to give customer
    int pennies = calculate_pennies(cents);
    cents = cents - (pennies * 1);

    // sum total coins used
    int coins = quarters + dimes + nickels + pennies;

    // print the sum of coins used
    printf("%i\n", coins);sub
}

int calculate_quarters(int cents)
{
    // calculate how many quarters to give customer
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
    // calculate how many dimes to give customer
    int dimes = 0;
    while (cents >= 10)
    {
        dimes++;
        cents = cents - 10;
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    // calculate how many nickels to give customer
    int nickels = 0;
    while (cents >= 5)
    {
        nickels++;
        cents = cents - 5;
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    // calculate how many pennies to give customer
    int pennies = 0;
    while (cents >= 1)
    {
        pennies++;
        cents = cents - 1;
    }
    return pennies;
}
