#include <stdio.h>
#include <cs50.h>


int main(void)
{
    printf("Height: \n");
    
    int c = get_int();
    
    if (c>=24)
    {
        return 1;
    }
    
    for(int i=0; i<c; i++)
    {
        for(int j=0;j<c+1;j++)
        {
            if (j<c-1-i)
            {
                printf(" ");
            }else
            {
                printf ("#");
            }
        }
        printf ("\n");
    }
}