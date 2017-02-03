#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int readkey(char k);
char encrypt(char text, int ck);

int main(int argc, string argv[])
{
    //error check
    if (argc != 2)
    {
        printf ("argument error!\n");
        return 1;
    }
    
    int len = strlen (argv[1]);
    for (int i=0; i<len; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf ("argument error!\n");
            return 1;
        }
    }
    //code start
    
    //read keys and they are stored in int array keys.
    int keys[len];
    for (int j=0; j<len; j++)
    {
        keys[j] = readkey(argv[1][j]);
    }
    
    
    printf ("plaintext: ");
    string input = get_string();
    //len2 is the length of the input text
    int len2 = strlen(input);
    int counter = 0;
    
    printf("ciphertext: ");
    for (int ii = 0; ii<len2; ii++)
    {
        if (isalpha(input[ii]))
        {
            printf("%c", encrypt(input[ii], keys[counter%len]));
            counter++;
        }else
        {
            printf("%c", input[ii]);
        }
    }
    printf("\n");
    
   
}

int readkey(char k)
{
    if ((int)k > 91)
    {
        k -= 97;
    }else
    {
        k -= 65;
    }
    return k;
}

char encrypt(char text, int ck)
{
    if((int)text>91)
    {
        if((int)text + ck > 122)
            {
                return text + ck -26;
            }
            else
            {
                return text + ck;
            }
    }else
    {
        if((int)text + ck > 90)
            {
                return text + ck -26;
            }
            else
            {
                return text + ck;
            }
    }
}