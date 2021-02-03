#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
        {
            cout << v[i];
            if (i != n - 1)
                cout << " ";
        }
        cout << endl;
        if (v.front() >= 60)
            cout << "best case" << endl;
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (v[i] >= 60)
                {
                    cout << v[i - 1] << endl;
                    break;
                }
                continue;
            }
        }
        if (v.back() < 60)
            cout << v.back() << endl
                 << "worst case" << endl;
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (v[i] >= 60)
                {
                    cout << v[i] << endl;
                    break;
                }
                continue;
            }
        }
    }
    return 0;
}
