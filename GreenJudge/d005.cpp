#include <iostream>
#include <sstream>
#include <stack>
// #pragma GCC optimize("O3")
using namespace std;
struct node
{
    int n;
    node *l, *r;
};
node *f(const string &x)
{
    if (!x.length())
        return NULL;
    stringstream ss(x);
    string sl, sr;
    node *y = new node;
    int n, i, l, r;
    ss >> n;
    y->n = n;
    for (i = x.find('(') + 1, l = 1, r = 0; l != r; i++)
    {
        sl.push_back(x[i]);
        l += x[i] == '(';
        r += x[i] == ')';
    }
    y->l = f(sl.substr(0, sl.length() - 1));
    for (i = x.find('(', i) + 1, l = 1, r = 0; l != r; i++)
    {
        sr.push_back(x[i]);
        l += x[i] == '(';
        r += x[i] == ')';
    }
    y->r = f(sr.substr(0, sr.length() - 1));
    return y;
}
int g(node *n)
{
    if (n == NULL)
        return 0;
    return n->n + max(g(n->l), g(n->r));
}
int main()
{
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    // ios::sync_with_stdio(false);
    const string strs[] = {"一", "二", "三", "四", "五", "六", "七", "八", "九", "十"};
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        string s;
        int l = 0, r = 0;
        do
        {
            char c;
            cin >> c;
            s.push_back(c);
            l += c == '(';
            r += c == ')';
        } while (l != r);
        node *t = f(s.substr(1, s.length() - 2));
        cout << "第" << strs[i] << "棵二元樹最長路徑長度：" << g(t) << '\n';
    }
    return 0;
}