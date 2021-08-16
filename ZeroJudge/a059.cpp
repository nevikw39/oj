#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int t;
    while (cin >> t)
    {
        for (int i = 0; i < t; i++)
        {
            int a, b, sum = 0;
            cin >> a >> b;
            for (int i = ceil(sqrt(a)); i < ceil(sqrt(b)); i++)
                sum += i * i;
            cout << "Case " << i + 1 << ": " << sum << endl;
        }
    }
    return 0;
}
