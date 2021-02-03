#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    char x;
    string s;
    while (cin >> n >> x)
    {
        string s;
        for (int i = 1; i <= n; i++)
            s += to_string(i);
        cout << count(s.begin(), s.end(), x) << endl;
    }
    return 0;
}
