#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, i = 0;
    cin >> n;
    cin.ignore(1, '\n');
    while (i < n)
    {
        string a, b;
        getline(cin, a);
        getline(cin, b);
        cout << "Case " << ++i << ": ";
        if (a == b)
            cout << "Yes";
        else
        {
            a.erase(remove_if(a.begin(), a.end(), ::isspace), a.end());
            b.erase(remove_if(b.begin(), b.end(), ::isspace), b.end());
            cout << (a == b ? "Output Format Error" : "Wrong Answer");
        }
        cout << endl;
    }
    return 0;
}
