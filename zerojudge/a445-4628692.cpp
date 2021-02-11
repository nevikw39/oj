#include <iostream>
#include <vector>
using namespace std;
class disjoint_set
{
  private:
	int n;
	vector<int> par, rank;
  public:
	disjoint_set(int _n) : n(_n + 1)
	{
		rank = vector<int>(n);
		for (int i = 0; i < n;)
			par.push_back(i++);
	}
	int find(int x)
	{
		if (x >= n)
			return -1;
		if (par[x] == x)
			return x;
		return par[x] = find(par[x]);
	}
	void unite(int x, int y)
	{
		x = find(x);
		y = find(y);
		if (x == y)
			return;
		if (rank[x] < rank[y])
			par[x] = y;
		else
		{
			par[y] = x;
			rank[x] += rank[x] == rank[y];
		}
	}
	bool same(int x, int y)
	{
		return find(x) == find(y);
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	disjoint_set ds(n);
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		ds.unite(a, b);
	}
	while (q--)
	{
		int p, _q;
		cin >> p >> _q;
		cout << (ds.same(p, _q) ? ":)\n" : ":(\n");
	}
	return 0;
}
