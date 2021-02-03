#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        int x[3] = {0};
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            x[tmp % 3]++;
        }
        cout << x[0] << ' ' << x[1] << ' ' << x[2] << endl;
    }
    return 0;
}
