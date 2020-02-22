#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n = 0;
    string s;
    map<string, string> m({{"HELLO", "ENGLISH\n"}, {"HOLA", "SPANISH\n"}, {"HALLO", "GERMAN\n"}, {"BONJOUR", "FRENCH\n"}, {"CIAO", "ITALIAN\n"}, {"ZDRAVSTVUJTE", "RUSSIAN\n"}});
    while (cin >> s && s != "#")
        cout << "Case " << ++n << ": " << (m.count(s) ? m[s] : "UNKNOWN\n");
    return 0;
}