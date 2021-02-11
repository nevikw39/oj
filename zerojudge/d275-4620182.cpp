#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	cin.ignore(1, '\n');
	while (n--)
	{
		short m = 0, f = 0;
		string s;
		getline(cin, s);
		s.erase(remove_if(s.begin(), s.end(), not1(ptr_fun(::isalpha))), s.end());
		for (char c : s)
			(c == 'M' ? m : f)++;
		cout << (m == f && m > 1 ? "LOOP\n" : "NO LOOP\n");
	}
	return 0;
}
