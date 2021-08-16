#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string in;
	while (cin >> in)
	{
		string out;
		for (auto i = in.begin(); i < in.end(); i++)
		{
			short n = 0;
			while (*i == *(i + 1) && i != in.end())
			{
				n++;
				i++;
			}
			switch (n)
			{
			case 1:
				out.push_back(*i);
			case 0:
				out.push_back(*i);
				break;
			default:
				out += to_string(n + 1);
				out.push_back(*i);
			}
		}
		cout << out << endl;
	}
	return 0;
}
