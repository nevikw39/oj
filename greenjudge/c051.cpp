// C
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// C++
#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#pragma GCC optimize("Ofast")

using namespace std;

struct S
{
    int i, j;
    S(int _i, int _j)
    {
        i = _i;
        j = _j;
    }
    bool operator<(const S &x) const
    {
        return 500 * i + 200 * j <= 500 * x.i + 200 * x.j;
    }
};

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    S s(0, 0);
    for (int i = 0; i <= 4; i++)
        for (int j = 0; j <= 5; j++)
            if (n - 500 * i - 200 * j > 0)
                s = max(s, S(i, j));
    cout << s.i << ' ' << s.j << ' ' << n - 500 * s.i - 200 * s.j << '\n';
    return 0;
}