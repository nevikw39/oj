#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		for (char &c : s)
			c = (c + 3 - 'A') % 26 + 'A';
		cout << s << endl;
	}
	return 0;
}
