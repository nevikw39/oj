#include <algorithm>
#include <iterator>
#include <iostream>
#include <sstream>
#include <string>
#include <set>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string sa, sb;
	while (getline(cin, sa) && getline(cin, sb))
	{
		int tmp;
		set<int> a, b;
		stringstream ssa, ssb;
		ssa.str(sa);
		ssb.str(sb);
		while (ssa >> tmp)
			a.insert(tmp);
		while (ssb >> tmp)
			b.insert(tmp);
		if (includes(a.begin(), a.end(), b.begin(), b.end()))
			cout << (a == b ? "A equals B\n" : "B is a proper subset of A\n");
		else if (includes(b.begin(), b.end(), a.begin(), a.end()))
			cout << "A is a proper subset of B\n";
		else
		{
			set<int> c;
			set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));
			cout << (c.empty() ? "A and B are disjoint\n" : "I'm confused!\n");
		}
	}
	return 0;
}
