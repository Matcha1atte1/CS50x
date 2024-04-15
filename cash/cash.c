#include <cs50.h>
#include <stdio.h>
int main(void)
{
    //prompt user for integer change
    int cents;
    do
    {
        cents = get_int ("Change owed: ");
    }
    while(cents < 0);
}

