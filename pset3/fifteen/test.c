#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int d = 3;
    int board[d][d];
    for (int i=0; i<d; i++)
    {
        for (int j=0; j<d; j++)
        {
            board[i][j]=d*d-(i*d+j+1);
            printf("%i\t", board[i][j]);
        }
        printf("\n");
    }
    
    if (d%2 == 0)
    {
        board[d][d-2]=2;
        board[d][d-3]=1;
    }
}
