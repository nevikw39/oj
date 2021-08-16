#include <iostream>
using namespace std;
int main()
{
    string c("");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (getline(cin, c))
    {
        string p("");
        for (auto i : c)
            p += i - 7;
        cout << p << endl;
    }
    return 0;
}
