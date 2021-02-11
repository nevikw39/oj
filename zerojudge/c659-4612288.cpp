#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s, str;
	cin >> s >> str;
	cout << str;
	while (cin >> str)
		cout << ' ' << s << ' ' << str;
	return 0;
}
