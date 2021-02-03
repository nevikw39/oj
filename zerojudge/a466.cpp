#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        cout << (s.length() > 3 ? 3 : ((s[0] == 'o') + (s[1] == 'n') + (s[2] == 'e') > 1 ? 1 : 2)) << endl;
    }
    return 0;
}
