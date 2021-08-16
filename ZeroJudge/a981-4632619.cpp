#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using ivec = vector<int>;
int n, m;
ivec v, w;
stack<ivec> s;
void dfs(int i, int sum)
{
	if (sum == m)
		s.push(w);
	if (sum >= m || i == n)
		return;
	dfs(i + 1, sum);
	w.push_back(v[i]);
	dfs(i + 1, sum + v[i]);
	w.pop_back();
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> n >> m)
	{
		delete v.data();
		v = ivec(n);
		delete w.data();
		w = ivec();
		for (int &i : v)
			cin >> i;
		sort(v.begin(), v.end());
		dfs(0, 0);
		if (!s.size())
			cout << "-1\n";
		else
			for (; s.size(); s.pop())
			{
				for (int i : s.top())
					cout << i << ' ';
				cout << endl;
			}
	}
	return 0;
}
