#include <iostream>
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    char _;
    int a, b, c, d;
    cin >> a >> _ >> b >> _ >> c >> _ >> d;
    if (b > 255 || b < 0 || c > 255 || c < 0 || d > 255 || d < 0)
    {
        putchar('N');
        return 0;
    }
    switch (a)
    {
    case 1 ... 126:
        putchar('A');
        return 0;
    case 128 ... 191:
        putchar('B');
        return 0;
    case 192 ... 223:
        putchar('C');
        return 0;
    case 224 ... 239:
        putchar('D');
        return 0;
    case 240 ... 247:
        putchar('E');
        return 0;
    default:
        putchar('X');
        return 0;
    }
}