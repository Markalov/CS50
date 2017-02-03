#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    printf("please enter your name: \n");
    string name = get_string();
    int counter = strlen(name);
    printf("%c", toupper(name[0]));
    for (int i=0; i<counter; i++)
    {
        if ( name[i] == ' ' )
        {
            printf("%c", toupper(name[i+1]));
        }
    }
    printf("\n");
    
}