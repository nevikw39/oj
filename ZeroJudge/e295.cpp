#include <cstdint>
#include <cstdio>
#include <cstdlib>
#pragma GCC optimize("O3")
int_fast8_t get()
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
    uint_fast8_t l = 0;
    char s[20];
    do
    {
        s[l] = n % 10 + '0';
        ++l;
        n /= 10;
    } while (n);
    for (uint_fast8_t i = l; i;)
        putchar_unlocked(s[--i]);
}
int main()
{
    while (!feof(stdin))
    {
        uint_fast64_t a = in<decltype(a)>(), b = in<decltype(b)>();
        out(a + b);
        putchar_unlocked('\n');
    }
    return 0;
}