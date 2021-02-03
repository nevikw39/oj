#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        sort(v.begin(), v.end());
        for (auto const &i : v)
            cout << i << ((&i == &v.back()) ? "" : " ");
        cout << endl;
    }
    return 0;
}
