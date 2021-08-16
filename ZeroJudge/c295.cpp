#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ivec = vector<int>;
using tab = vector<ivec>;
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        tab t(n, ivec(m));
        bool b = false;
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> t[i][j];
            sort(t[i].begin(), t[i].end());
            s += t[i].back();
        }
        cout << s << endl;
        for (int i = 0; i < n; i++)
        {
            if (s % t[i].back() == 0)
            {
                cout << t[i].back();
                if (i != n)
                    cout << ' ';
                b = true;
            }
        }
        if (!b)
            cout << -1;
    }
    return 0;
}
