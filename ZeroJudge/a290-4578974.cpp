#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
class graph
{
	int n;
	vector<deque<int>> adj;
	vector<bool> v;
  public:
	graph(int _n)
	{
		this->n = _n + 1;
		this->adj = vector<deque<int>>(this->n, deque<int>());
		this->v = vector<bool>(this->n, false);
	}
	void push(int x, int val)
	{
		this->adj[x].push_back(val);
	}
	void dfs(int x)
	{
		for (int i : this->adj[x])
		{
			int t = i;
			if (this->v[t])
				continue;
			this->v[t] = true;
			this->dfs(t);
		}
	}
	bool isvisit(int x)
	{
		return this->v[x];
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	while (cin >> n >> m)
	{
		int a, b;
		graph g(n);
		while (m--)
		{
			int x, y;
			cin >> x >> y;
			g.push(x, y);
		}
		cin >> a >> b;
		g.dfs(a);
		cout << (g.isvisit(b) ? "Yes!!!\n" : "No!!!\n");
	}
	return 0;
}
