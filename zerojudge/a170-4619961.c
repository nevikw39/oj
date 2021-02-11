#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);

    while (n--)
    {
        long a, b;
        scanf("%o %o", &a, &b);
        printf("%X\n", a + b);
    }

    return 0;
}
