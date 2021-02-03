#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            sum += tmp;
        }
        cout << (sum <= 59 * n ? "yes" : "no") << endl;
    }
    return 0;
}
