#include <stdio.h>
int main()
{
    int a, b = 1;
    scanf("%d", &a);
    while(a >= b << 1)
        b <<= 1;
    printf("%d\n", (a - b) << 1 | 1);
    return 0;
}