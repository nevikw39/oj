#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int a, b, n;
    while (cin >> a >> b >> n)
    {
        int d = a, sum = 0;
        vector<int> v(n);
        cout << a / b << '.';
        a %= b;
        for (int i = 0; i < n; i++)
        {
            a *= 10;
            v[i] = a / b;
            a %= b;
        }
        for (int i : v)
            cout << i;
        cout << endl;
    }
    return 0;
}
