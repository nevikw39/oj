#include <cstdio>
#include <cstdlib>
#pragma GCC optimize("O3")
using namespace std;
int get()
{
    char buf[1];
    size_t cnt = fread_unlocked(buf, 1, 1, stdin);
    if (cnt)
        return *buf;
    return -1;
}
template <typename T>
inline T in()
{
    T n = 0;
    char c = '0';
    do
    {
        n = (n << 3) + (n << 1) + c - '0';
        c = get();
        if (c == -1)
        {
            if (n)
                return n;
            else
                exit(0);
        }
    } while (c >= '0' && c <= '9');
    return n;
}
template <typename T>
inline void out(T n)
{
    if (n == 0)
    {
        putchar_unlocked('0');
        return;
    }
    int l = 0;
    char s[20];
    do
    {
        s[l] = n % 10 + '0';
        ++l;
        n /= 10;
    } while (n);
    for (int i = l; i;)
        putchar_unlocked(s[--i]);
}
int main()
{
    int n;
    while (~(n = in<int>()))
    {
        if (n == 1)
        {
            putchar_unlocked('0');
            putchar_unlocked('\n');
            in<int>();
            continue;
        }
        while (n > 1)
        {
            out(in<int>() * --n);
            putchar_unlocked(' ');
        }
        putchar_unlocked('\n');
        in<int>();
    }
    return 0;
}