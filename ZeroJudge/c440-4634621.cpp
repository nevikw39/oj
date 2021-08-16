#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long n = 0, a, b = 0;
	string s;
	cin >> s;
	s.erase(remove_if(s.begin(), s.end(), [](char x) { return x != 'Q' && x != 'A'; }), s.end());
	a = count(s.begin(), s.end(), 'Q');
	for (char c : s)
	{
		if (c == 'Q')
		{
			a--;
			b++;
		}
		else
			n += a * b;
	}
	cout << n << endl;
	return 0;
}
