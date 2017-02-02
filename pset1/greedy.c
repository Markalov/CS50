#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float c;
    do 
    {
        printf("hai! How much change is owed?\n");
        c = get_float();
    }while(c<0);
    
    int counter = 0;
    float r=0;
    c *= 100;
    
    counter = floor (c/25);
    r = c - 25 * counter;
    
    counter += floor (r/10);
    r = r - 10 * floor (r/10);
    
    counter += floor (r/5);
    r = r - 5* floor (r/5);
    
    counter += floor (r/1);
    
    
    printf("%i\n", counter);
    
}