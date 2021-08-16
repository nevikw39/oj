#include <iostream>
#include <string>
using namespace std;
string f(string in)
{
	string out;
	for (auto i = in.begin(); i < in.end(); i++)
	{
		short n = 1;
		while (*i == *(i + 1) && i != in.end())
		{
			n++;
			i++;
		}
		out += to_string(n);
		out.push_back(*i);
	}
	return out;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short n;
	string str[31] = {"1"};
	for (char i = 1; i < 31; i++)
		str[i] = f(str[i - 1]);
	while (cin >> n)
		cout << str[n] << endl;
	return 0;
}
