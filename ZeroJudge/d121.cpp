#include <cmath>
#include <iostream>
#include <set>
using namespace std;
bool isprime(int x)
{
    int gap = 4;
    if (x == 1)
        return false;
    else if (x < 4)
        return true;
    else if (!(x % 2) || !(x % 3))
        return false;
    for (int i = 5; i <= ceil(sqrt(x)); gap = 6 - gap, i += gap)
        if (!(x % i))
            return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    set<unsigned short> s;
    for (int i = 2; i < 46338; i++)
        if (isprime(i))
            s.insert(i);
    int n;
    while (cin >> n && n)
    {
        auto i = s.begin();
        cout << n << " = ";
        if (n == 1)
        {
            cout << "1\n";
            continue;
        }
        else if (n < 0)
        {
            cout << "-1 x ";
            n /= -1;
        }
        while (n - 1 && i != s.end())
        {
            if (!(n % *i))
            {
                n /= *i;
                cout << *i << (n - 1 ? " x " : "");
            }
            else
                i++;
        }
        cout << (n - 1 ? to_string(n) : "") << endl;
    }
    return 0;
}
