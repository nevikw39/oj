#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;

    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;

        string in, out;

        for (int i = 0; i < n; i++)
        {
            string tmp;
            cin >> tmp;
            in += tmp;
        }

        for (int i = 0; i < m; i++)
        {
            int tmp;
            cin >> tmp;
            out.push_back(in[tmp - 1]);
        }

        cout << out << endl;
    }

    return 0;
}
