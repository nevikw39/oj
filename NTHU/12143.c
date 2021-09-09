#include "12143.h"
#include <stdio.h>
#define ll long long int

int input[2000000];

int main()
{
    int n, t;
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++)
        scanf("%d", input + i);
    for (int i = 0; i < t; i++)
    {
        int q;
        scanf("%d", &q);
        printf("%d is at index: %d\n", q, BS(input, q, n));
    }
    return 0;
}
