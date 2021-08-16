#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        vector<int> v(n), s(n + 1);
        for (auto &i : v)
        {
            cin >> i;
            int x = &i - &v.front();
            s[x + 1] = (x > 0 ? s[x] : 0) + i;
        }
        for (int i = 0; i < m; i++)
        {
            int l, r;
            cin >> l >> r;
            cout << s[r] - s[l - 1] << endl;
        }
    }
    return 0;
}
