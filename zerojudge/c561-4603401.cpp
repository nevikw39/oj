#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	set<int, greater<int>> s;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		reverse(str.begin(), str.end());
		s.insert(stoi(str));
	}
	cout << *s.begin();
	return 0;
}
