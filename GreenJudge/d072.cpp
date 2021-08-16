#include <iostream>
#include <vector>
#include <map>
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    map<string, int> psi;
    map<int, string> pis;
    map<string, map<string, int> > asi;
    map<string, map<int, string> > ais;
    map<int, map<int, int> > m;
    while (n--)
    {
        int v;
        string a, p;
        cin >> a >> v >> p;
        if (!asi[p].count(a))
        {
            const int na = asi[p].size();
            asi[p][a] = na;
            ais[p][na] = a;
        }
        if (!psi.count(p))
        {
            const int np = psi.size();
            psi[p] = np;
            pis[np] = p;
        }
        m[psi[p]][asi[p][a]] += v;
    }
    for (map<int, map<int, int> >::iterator it = m.begin(); it != m.end(); it++)
    {
        string p = pis[it->first];
        cout << p << ':';
        map<int, int>::iterator jt = (it->second).begin();
        cout << ais[p][jt->first] << ' ' << jt->second;
        for (jt++; jt != (it->second).end(); jt++)
            cout << ',' << ais[p][jt->first] << ' ' << jt->second;
        cout << endl;
    }
    return 0;
}
