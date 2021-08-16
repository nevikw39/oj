#include <cmath>
#include <iostream>
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
    int a, b;
    while (cin >> a >> b)
    {
        int n = 0;
        for (int i = a; i <= b; i++)
            n += isprime(i);
        cout << n << endl;
    }
    return 0;
}
