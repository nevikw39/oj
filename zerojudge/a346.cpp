#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
	long n, m;
    cin >> n;
    vector<long> v(n), s(n + 1);
    for (auto &i : v)
    {
        cin >> i;
        long x = &i - &v.front();
        s[x + 1] = (x > 0 ? s[x] : 0) + i;
    }
    cin >> m;
    for (long i = 0; i < m; i++)
    {
        long l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }
	return 0;
}
