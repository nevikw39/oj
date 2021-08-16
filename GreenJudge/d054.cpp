#include <iostream>
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int n, z;
    char c[10], s[10][64];
    for (int i = 0; i < 10; i++)
        scanf("%s", s + i);
    scanf("%d,%d", &n, &z);
    sprintf(c, "%d", n);
    for (int k = 0; k < 8; k++)
    {
        for (int n = 0; n < z; n++)
        {
            for (char *i = c; *i; i++)
            {
                if (i != c)
                    printf("___");
                for (char j = '0'; j <= '9'; j++)
                {
                    if (*i != j)
                        continue;
                    for (int l = 0; l < 8; l++)
                        for (int m = 0; m < z; m++)
                            putchar(s[j - '0'][8 * k + l] == '1' ? '*' : '_');
                }
            }
            putchar('\n');
        }
    }
    return 0;
}
