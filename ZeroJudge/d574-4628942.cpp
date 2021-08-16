#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string in;
	while (cin >> n >> in)
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
		cout << (out.length() < in.length() ? out : in) << endl;
	}
	return 0;
}
