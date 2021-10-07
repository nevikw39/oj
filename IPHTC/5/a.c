#include <stdio.h>

int main()
{
    int ps[1000001] = {0}, t;
    for (int i = 1; i < 1000001; i++)
    {
        i[ps] = ps[i - 1];
        for (int j = i; j; j /= 10)
            if (j % 10 == 1)
                ++i[ps];
    }
    scanf("%d", &t);
    while (t--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", ps[b] - ps[a - 1]);
    }
    return 0;
}
