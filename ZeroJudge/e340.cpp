#include <iostream>
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    long n, m;
    cin >> n >> m;
    cout << m << ' ';
    n--;
    while (n--)
    {
        long tmp;
        cin >> tmp;
        cout << tmp - m << ' ';
        m = tmp;
    }
    return 0;
}
