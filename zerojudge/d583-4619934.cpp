#include <iostream>
#include <set>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;

    while (cin >> n)
    {
        set<int> s;

        while (n--)
        {
            int tmp;
            cin >> tmp;
            s.insert(tmp);
        }

        for (int i : s)
            cout << i << ' ';

        cout << endl;
    }

    return 0;
}
