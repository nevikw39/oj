#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	size_t l = 0;
	deque<string> d;
	while (getline(cin, s))
	{
		d.push_front(s);
		l = max(l, s.length());
	}
	for (int i = 0; i < l; i++)
	{
		for (auto j : d)
			cout << (i < j.length() ? j[i] : ' ');
		cout << endl;
	}
}
