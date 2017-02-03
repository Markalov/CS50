#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    int key = atoi(argv[1]);
    if (argc!=2 || key<0)
    {
        printf("argument failures\n");
        return 1;
    }
    key %= 26;
    
    printf ("plaintext: ");
    string input = get_string();
    int length = strlen (input);
    printf ("ciphertext: ");
    for (int i = 0; i<length; i++)
    {
        if (isalpha(input[i]))
        {
            //check if its caps
            if (!(int)(input[i] > 91))
            {
                if((int)input[i]+key > 90)
                {
                    printf ("%c", input[i]+key-26);
                }else
                {
                    printf ("%c", input[i]+key);
                }
            }else //normal situation
            {
                if((int)input[i]+key > 122)
                {
                    printf ("%c", input[i]+key-26);
                }
                else
                {
                    printf ("%c", input[i]+key);
                }
            }
            
        }else
        {
            printf ("%c", input[i]);
        }
    }
    printf("\n");
  
}