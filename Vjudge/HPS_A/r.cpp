/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <bits/stdc++.h>
#ifndef nevikw39
#define nevikw39 cin.tie(nullptr), ios::sync_with_stdio(false)
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")
#define ALL(X) begin(X), end(X)
#define ST first
#define ND second
using namespace std;

int main()
{
    nevikw39;
    int n, m;
    cin >> n >> m;
    vector<bool> v(n + 1);
    vector<int> e(m);
    for (int &i : e)
        cin >> i;
    reverse(ALL(e));
    for (const int &i : e)
        if (!v[i])
        {
            v[i] = true;
            cout << i << '\n';
        }
    for (int i = 1; i <= n; i++)
        if (!v[i])
            cout << i << '\n';
    return 0;
}