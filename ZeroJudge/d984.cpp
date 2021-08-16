#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using uint = unsigned int;
int main()
{
    uint n[3];
    char c[] = "ABC";
    while (cin >> n[0] >> n[1] >> n[2])
    {
        vector<pair<uint, char>> v(3);
        for (int i = 0; i < 3; i++)
            v[i] = make_pair(n[i], c[i]);
        sort(v.begin(), v.end());
        cout << (v[2].first > v[1].first + v[0].first ? v[2].second : v[1].second) << endl;
    }
    return 0;
}
