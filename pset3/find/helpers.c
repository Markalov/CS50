/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm, using binary searching
    int m = 0;
    int c = (m+n+1)/2;
    while(m <= n)
    {
        if(values[c] == value)
        {
            return true;
        }else if (values[c] > value)
        {
            n = c - 1;
        }else
        {
            m = c + 1;
        }
        c = (m+n+1)/2;
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm, using bubble sort
    //storing swap values
    int temp = 0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n-i; j++)
        {
            if(values[j]>values[j+1])
            {
                temp = values[j+1];
                values[j+1] = values [j];
                values [j] = temp;
            }
        }
    }
    return;
}
