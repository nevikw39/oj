#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        vector<int> v(0);
        for (int i = n; i <= m; i++)
        {
            int sum = 0;
            string s = to_string(i);
            for (auto c : s)
                sum += pow(c - '0', s.length());
            if (sum == i)
                v.push_back(i);
        }
        if (v.size() > 0)
            for (auto const &i : v)
                cout << i << ((&i == &v.back()) ? "\n" : " ");
        else
            cout << "none" << endl;
    }
    return 0;
}
