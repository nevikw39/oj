#include <iostream>
#include <cstring>
#include <map>
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int n, start, end, h;
    cin >> n;
    map<int, int> m;
    bool *start_arr = new bool[n + 1], *end_arr = new bool[n + 1];
    memset(start_arr, 0, (n + 1) * sizeof(bool));
    memset(end_arr, 0, (n + 1) * sizeof(bool));
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        m[a] = b;
        start_arr[b] = true;
        end_arr[a] = true;
    }
    for (start = 1; start <= n; start++)
        if (!start_arr[start])
            break;
    for (end = 1; end <= n; end++)
        if (!end_arr[end])
            break;
    h = start % 997;
    for (int i = m[start]; i != end; i = m[i])
        h = (h * 7 + i) % 997;
    cout << (h * 7 + end) % 997;
    return 0;
}
