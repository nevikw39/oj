#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int m;
    while (cin >> m)
    {
        for (int i = 0; i < m; i++)
        {
            int n, d = 1, sum = 0;
            cin >> n;
            vector<int> v(n);
            for (int i = 0; i < n; i++)
            {
                d *= 10;
                v[i] = d / 17;
                d %= 17;
            }
            for (int i : v)
                sum += i;
            cout << v.back() << ' ' << sum << endl;
        }
    }
    return 0;
}
