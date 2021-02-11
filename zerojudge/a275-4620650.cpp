#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string a, b;
	while (cin >> a && a != "STOP!!")
	{
		cin >> b;
		map<char, int> ma, mb;
		for (char c : a)
			ma[c]++;
		for (char c : b)
			mb[c]++;
		cout << (ma == mb ? "yes\n" : "no\n");
	}
	return 0;
}
