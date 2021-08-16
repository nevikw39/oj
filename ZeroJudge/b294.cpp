#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n)
    {
        int sum = 0;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        for (auto const &i : v)
        {
            sum += i * (&i - &(v.front()) + 1);
        }
        cout << sum << endl;
    }
    return 0;
}
