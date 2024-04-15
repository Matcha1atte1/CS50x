#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);

int main(void)
{

    //prompt user for integer change
    int cents;
    do
    {
        cents = get_int ("Change owed: ");
    }
    while(cents < 0);

    int quarters = calculate_quarters(cents)
    cents = cents - (quarters * 25)
}

int calculate_quarters(int cents)
{
    
}

