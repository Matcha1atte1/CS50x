#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);

int main(void)
{

    //prompt user for integer change owed in cents
    int cents;
    do
    {
        cents = get_int ("Change owed: ");
    }
    while(cents < 0);

    //calculate how many quarters to give customer
    int quarters = calculate_quarters(cents)
    cents = cents - (quarters * 25)

    //calculate how many dimes to give customer
    
}

int calculate_quarters(int cents)
{
    //calculate how many quarters to give customer
    int quarters = 0
    while(cents >= 25)
    {
        quarters++
        cents = cents - 25
    }
    return quarters;
}

int calculate_dimes(int cents)
{
    //calculate how many dimes to give customer
    int dimes = 0
    while(cents >= 10)
    {
        dimes++
        cents = cents - 10
    }
    return dimes;
}

