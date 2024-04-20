#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);

int main(void)
{

    //prompt user for integer change owed in cents
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
    //calculate how many quarters to give customer 
    int quarter = 0
    while(cents >= 25)
    {
        quarter++
        cents = cents - 25
    }
    return quarters;

}

