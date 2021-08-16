#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int a, x, n = 0;
        cin >> a >> x;
        for (int i = 1; i <= x; i++)
            n += (i & ~a) == i;
        cout << n << '\n';
    }
    return 0;
}
