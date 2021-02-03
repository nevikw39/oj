#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int sum = 0;
    vector<vector<int>> v(5, vector<int>(3));
    for (auto &i : v)
    {
        for (auto &j : i)
            cin >> j;
        sort(i.begin(), i.end());
        if (i[2] < i[1] + i[0] && i[2] > i[1] - i[0])
            sum++;
    }
    cout << sum << endl;
    return 0;
}
