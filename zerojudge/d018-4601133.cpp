#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;
int main()
{
	string s;
	while(getline(cin, s))
	{
		int n;
		double d, sum = 0;
		string sn, sd;
		stringstream ss;
		ss.str(s);
		while (getline(ss, s, ':') && ss >> d)
		{
			int n = stoi(s);
			sum += -1 * !(n % 2) * d + (n % 2) * d;
		}	
		cout << sum << endl;
	}
	return 0;
}
