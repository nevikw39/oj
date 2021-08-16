#include <iostream>
#include <stack>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	stack<int> s;
	int n;
	cin >> n;
	while (n--)
	{
		int m;
		cin >> m;
		switch (m)
		{
		case 1:
			s.pop();
			break;
		case 2:
			cout << s.top() << endl;
			break;
		case 3:
			int x;
			cin >> x;
			s.push(x);
		}
	}
	return 0;
}
