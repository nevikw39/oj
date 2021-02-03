#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int m, d;
    vector<string> s({"´¶³q", "¦N", "¤j¦N"});
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> m >> d)
        cout << s[(m * 2 + d) % 3] << endl;
    return 0;
}
