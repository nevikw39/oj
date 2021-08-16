#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <set>
using namespace std;
void inline ps(set<int> &x)
{
	if (!x.size())
	{
		cout << 'N';
		return;
	}
	int n = *(prev(x.end()));
	x.erase(prev(x.end()));
	cout << '{';
	for (int i : x)
		cout << i << ", ";
	cout << n << '}';
}
int main()
{
	char n;
	cin >> n;
	n -= '0';
	while (n--)
	{
		int tmp;
		set<int> a, b, u, i, d, ds;
		cin.ignore(5, '{');
		string s;
		stringstream ss;
		getline(cin, s, '}');
		s.erase(remove_if(s.begin(), s.end(), [](char x) { return x == ','; }), s.end());
		ss.str(s);
		while (ss >> tmp)
			a.insert(tmp);
		ss.clear();
		cin.ignore(5, '{');
		getline(cin, s, '}');
		s.erase(remove_if(s.begin(), s.end(), [](char x) { return x == ','; }), s.end());
		ss.str(s);
		while (ss >> tmp)
			b.insert(tmp);
		set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(u, u.begin()));
		set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(i, i.begin()));
		set_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(d, d.begin()));
		set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(ds, ds.begin()));
		ps(u);
		cout << ", ";
		ps(i);
		cout << ", ";
		ps(d);
		cout << ", ";
		ps(ds);
		cout << endl;
	}
	return 0;
}
