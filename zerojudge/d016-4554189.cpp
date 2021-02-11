#include <iostream>
#include <stack>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	while (getline(cin, s))
	{
		stack<int> st;
		int i = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (isspace(s[i]))
				continue;
			else if (isdigit(s[i]))
			{
				int j = s.find(' ', i);
				st.push(stoi(s.substr(i, j - i)));
				i = j;
				continue;
			}
			int b = st.top();
			st.pop();
			int a = st.top();
			st.pop();
			switch (s[i])
			{
			case '+':
				st.push(a + b);
				break;
			case '-':
				st.push(a - b);
				break;
			case '*':
				st.push(a * b);
				break;
			case '/':
				st.push(a / b);
				break;
			case '%':
				st.push(a % b);
				break;
			}
		}
		cout << st.top() << endl;
	}
	return 0;
}
