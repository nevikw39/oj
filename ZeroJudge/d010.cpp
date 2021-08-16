#include <iostream>
using namespace std;
int main()
{
    int n;

    while (cin >> n)
    {
        int s = 1;
        for (int i = 2; i < n; i++)
            if (n % i == 0)
                s += i;

        cout << (s > n ? "盈數" : (s < n ? "虧數" : "完全數")) << endl;
    }

    return 0;
}
