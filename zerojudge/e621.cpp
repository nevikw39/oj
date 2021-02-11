#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        bool flag = true;
        for (int i = a + 1; i < b; i++)
            if (i % c)
                cout << i << ' ', flag = false;
        if (flag)
            cout << "No free parking spaces.";
        cout.put('\n');
    }
    return 0;
}