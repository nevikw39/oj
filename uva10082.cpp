#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
int main()
{
    const string s = "1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    int i;
    char c;
    while ((c = getchar_unlocked()) != EOF)
    {
        for (i = 0; s[i] && s[i] != c; i++)
            ;
        putchar_unlocked(s[i] ? s[i - 1] : c);
    }
    return 0;
}