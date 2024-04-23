#include<stdio.h>
int main(void)
{
    // get scores
    int scores[3]
    scores[0] = get_int ("Score: ");
    scores[1] = get_int ("Score: ");
    socres[2] = get_int ("Score: ");

    //print average
    printf("Average: %f\n", (scores[0] + scores[1] + scores[2])/3.0);
}
