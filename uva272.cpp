#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main()
{
    char c;
    bool b = false;
    while ((c = getchar_unlocked()) != EOF)
        if (c == '"')
            printf((b = !b) ? "``" : "''");
        else
            putchar(c);
    return 0;
}