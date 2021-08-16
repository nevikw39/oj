#include <set>
#include <iostream>
#include <iterator>
#include <algorithm>
#define endl '\n'
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int n;
    set<int> a, b, c;
    cin >> n;
    while (n--)
    {
        int tmp;
        cin >> tmp;
        b.insert(tmp);
    }
    cin >> n;
    while (n--)
        a.insert(n--);
    set_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.end()));
    for (set<int>::iterator i = c.begin(); i != c.end(); i++)
        cout << *i << ' ';
    return 0;
}