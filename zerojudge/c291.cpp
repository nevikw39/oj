#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
using ivec = vector<int>;
using tab = vector<ivec>;
int main()
{
    int x;
    while (cin >> x)
    {
        map<int, int> m;
        ivec v;
        int n = 0;
        for (int i = 0; i < x; i++)
        {
            int tmp;
            cin >> tmp;
            m[i] = tmp;
        }
        for (auto i : m)
        {
            int a = i.second;
            if (find(v.begin(), v.end(), i.first) != v.end())
                continue;
            do
            {
                v.push_back(a);
                a = m.find(a)->second;
            } while (i.first != a);
            n++;
        }
        cout << n << endl;
    }
    return 0;
}
