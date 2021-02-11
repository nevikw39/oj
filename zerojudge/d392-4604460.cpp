#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	while (getline(cin, s))
	{
		long sum = 0, tmp;
		stringstream ss;
		ss.str(s);
		while (ss >> tmp)
			sum += tmp;
		cout << sum << endl;
	}
	return 0;
}
