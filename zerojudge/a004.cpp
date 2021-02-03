#include <iostream>
using namespace std;
bool leap(int n)
{
    if (n % 4 == 0)
    {
        if (n % 100 == 0)
        {
            if (n % 400 == 0)
                return true;
            else
                return false;
        }
        else
            return true;
    }
    else
        return false;
}
int main()
{
    int x;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> x)
        cout << (leap(x) ? "¶|¦~" : "¥­¦~") << endl;
    return 0;
}
