#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int n, m;
vector<int> v;
stack<vector<int>> s;
void dfs(int i, vector<int> w)
{
	if (w.size() == m)
	{
		s.push(w);
		return;
	}
	if (i == n)
		return;
	dfs(i + 1, w);
	w.push_back(v[i]);
	dfs(i + 1, w);
	w.pop_back();
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> n && n)
	{
		v = vector<int>(n);
		for (int &i : v)
			cin >> i;
		cin >> m;
		sort(v.begin(), v.end());
		dfs(0, vector<int>());
		for (; s.size(); s.pop())
		{
			for (int i : s.top())
				cout << i << ' ';
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
