#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<int> fib = {1, 2};
    for (int i = 2; fib.size() < 40; i++)
        fib.push_back(fib[i - 2] + fib[i - 1]);
    int n, t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        auto l = lower_bound(fib.begin(), fib.end(), n);
        short d = l - fib.begin() - 1;
        cout << n << " = ";
        if (n == *l)
        {
            cout << 1;
            for (int i = ++d; i; i--)
                cout << 0;
        }
        else
            for (int i = d; i >= 0; i--)
            {
                if (n >= fib[i])
                {
                    n -= fib[i];
                    cout << 1;
                }
                else
                    cout << 0;
            }
        cout << " (fib)\n";
    }
    return 0;
}
