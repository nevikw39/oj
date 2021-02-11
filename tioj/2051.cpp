#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;
void f(const string &x, map<string, int> &y)
{
    string s;
    int l = x.length(), n = 0;
    for (int i = 0; i < l; i++)
        switch (x[i])
        {
            case 'a' ... 'z':
                s += x[i];
                break;
            case 'A' ... 'Z':
                y[s] += n;
                n = 0;
                s = x[i];
                if (i + 1 == l || isupper(x[i + 1]) || (islower(x[i + 1]) && (i + 2 == l || isupper(x[i + 2]))))
                    n = 1;
                break;
            default:
                n = n * 10 + x[i] - '0';
        }
    y[s] += n;
}
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    string str;
    cin >> str;
    cout << str << '\n';
    str = '(' + str + ')';
    vector<map<string, int>> v(1);
    int l = str.length(), d = 0;
    stack<char> stk;
    for (int i = 0; i < l; i++)
    {
        if (str[i] == '(')
        {
            stk.push('(');
            d++;
            v.push_back(move(map<string, int>()));
        }
        else if (str[i] == ')')
        {
            string x;
            while (stk.top() != '(')
            {
                x.push_back(stk.top());
                stk.pop();
            }
            stk.pop();
            reverse(x.begin(), x.end());
            f(x, v[d]);
            int n;
            if (i + 1 == l || !isdigit(str[i + 1]))
                n = 1;
            else
            {
                i++;
                for (n = 0; i < l && isdigit(str[i]); i++)
                    n = 10 * n + str[i] - '0';
                i--;
            }
            for (auto j : v[d])
                v[d - 1][j.first] += j.second * n;
            v.pop_back();
            d--;
        }
        else
            stk.push(str[i]);
    }
    v.front().erase("\0");
    for (auto i : v.front())
        cout << i.first << ':' << i.second << '\n';
    cout << '\n';
    return 0;
}