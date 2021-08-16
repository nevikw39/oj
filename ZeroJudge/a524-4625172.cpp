#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short k;
	while (cin >> k)
	{
		string s;
		do
			s.push_back(k-- + '0');
		while (k);
		do
			cout << s << endl;
		while (prev_permutation(s.begin(), s.end()));
	}
	return 0;
}
