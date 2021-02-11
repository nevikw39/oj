#include <iostream>
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    long n, sum = 0;
    cin >> n;
    while (n--)
    {
        long tmp;
        cin >> tmp;
        sum += tmp;
        cout << sum << ' ';
    }
    return 0;
}
