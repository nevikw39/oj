#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long a, b;
    while (cin >> a >> b)
    {
        cout << __gcd(a, b) << endl;
    }
    return 0;
}
