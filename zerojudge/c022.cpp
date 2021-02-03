#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    short t;
    cin >> t;
    for (short i = 0; i < t; i++)
    {
        int sum;
        short a, b, n, m;
        cin >> a >> b;
        n = (a + 1 + !(a % 2)) / 2;
        m = (b + 1 - !(b % 2)) / 2;
        sum = (m + n - 1) * (m - n + 1);
        cout << "Case " << i + 1 << ": " << sum << endl;
    }
    return 0;
}
