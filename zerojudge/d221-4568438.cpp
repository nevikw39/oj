#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while (cin >> n && n)
	{
		priority_queue<int, vector<int>, greater<int>> p;
		for (int i = 0; i < n; i++)
		{
			int tmp;
			cin >> tmp;
			p.push(tmp);
		}
		long cost = 0;
		while (p.size() > 1)
		{
			long a = p.top(), b;
			p.pop();
			b = p.top();
			p.pop();
			p.push(a += b);
			cost += a;
		}
		cout << cost << endl;
	}
	return 0;
}
