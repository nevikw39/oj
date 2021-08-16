#include <functional>
#include <iostream>
using namespace std;
int main()
{
    int n;
    long a, b, o;
    function<long()> funcs[] = {
        [&] { return a + b; },
        [&] { return a - b; },
        [&] { return a * b; },
        [&] { return a / b; },
    };
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> o >> a >> b;
            cout << funcs[o - 1]() << endl;
        }
    }
    return 0;
}
