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

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
    int k, i = 0, x = 0, y = 0;
    cin >> k;
    while (--k)
    {
        if (x == 100 && !y || x == 100 && y == 100 || !x && y == 100)
            i++;
        x += 5 * dx[i];
        y += 5 * dy[i];
    }
    cout << '(' << x << ',' << y << ")\n";
    return 0;
}