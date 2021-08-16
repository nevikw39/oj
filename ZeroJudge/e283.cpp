#include <cstdint>
#include <cstdio>
#include <cstdlib>
#pragma GCC optimize("O3")
char get()
{
    char c;
    do
        c = getchar();
    while (c == ' ' || c == '\n');
    return c;
}
int main()
{
    char arr[2][2][2][2];
    arr[0][1][0][1] = 'A';
    arr[0][1][1][1] = 'B';
    arr[0][0][1][0] = 'C';
    arr[1][1][0][1] = 'D';
    arr[1][0][0][0] = 'E';
    arr[1][1][0][0] = 'F';
    int n;
    while (~scanf("%d", &n))
    {
        while (n--)
            putchar(arr[get() - '0'][get() - '0'][get() - '0'][get() - '0']);
        putchar('\n');
    }
    return 0;
}