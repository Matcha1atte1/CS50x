#include <cs50.h>
#include <stdio.h>
int main(void)
{
    //prompt user for integer change
    int change;
    do
    {
        change = get_int ("Change owed: ");
    }
    while(change < 1);
}
