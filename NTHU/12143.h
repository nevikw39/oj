#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <stdio.h>
#include <stdlib.h>

int BS(int *arr, int x, int n)
{
    int y = 0;
    for (int jump = n >> 1; jump; jump >>= 1)
        while (y + jump < n && arr[y + jump] <= x)
            y += jump;
    return y;
}

#endif
