#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
using P = pair<int, int>;
int main()
{
	int n;
	const int x [] = {1, 0, -1, 0}, y[] = {0, 1, 0, -1};
	while (cin >> n)
	{
		map<P, int> m;
		queue<P> q;
		vector<vector<char>> v(n, vector<char>(n));
		for (auto &i : v)
			for (auto &j : i)
				cin >> j;
		q.push({1, 1});
		m[ {1, 1}] = 0;
		while (q.size())
		{
			P p = q.front();
			q.pop();
			if (p.first == n - 2 && p.second == n - 2)
				break;
			for (char i = 0; i < 4; i++)
			{
				int a = p.first + x[i], b = p.second + y[i];
				if (0 <= a && a < n && 0 <= b && b < n && v[a][b] == '.' && m.find({a, b}) == m.end())
				{
					q.push({a, b});
					m[ {a, b}] = m[p] + 1;
				}
			}
		}
		cout << (m.find({n - 2, n - 2}) == m.end() ? "No solution!" : to_string(m[ {n - 2, n - 2}] + 1)) << endl;
	}
	return 0;
}
