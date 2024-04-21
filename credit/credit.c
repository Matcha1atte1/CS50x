#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card;
    do
    {
        card = get_long("Card no: ");
    }
    while(card < 0)
}
