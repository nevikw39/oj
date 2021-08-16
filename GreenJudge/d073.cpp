#include <iostream>
#include <stack>
#define endl '\n'
// #pragma GCC optimize("O3")
using namespace std;
int priority(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
        switch (s[i])
        {
        case '(':
            st.push('(');
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            while (st.size() && priority(st.top()) >= priority(s[i]))
            {
                cout << st.top();
                st.pop();
            }
            st.push(s[i]);
            break;
        case ')':
            while (st.top() != '(')
            {
                cout << st.top();
                st.pop();
            }
            st.pop();
            break;
        default:
            cout << s[i];
        }
    while (st.size())
    {
        cout << st.top();
        st.pop();
    }
    return 0;
}
