#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int w, v1, v2;
	string s = "A";
	cin >> w >> v1 >> v2;
	for (int i = 0; i < w; i++)
	{
		while (s.length() < v1 + i && s.length() < v2)
			s.push_back('a');
		if (v1 + i > v2)
		{
			s = "A";
			for (int j = 1; j < v2; j++)
				s.push_back((j - 1) % 26 + 'a');
			for (int j = i; j < w; j++)
			{
				next_permutation(s.begin(), s.end());
				cout << s << ": hello, " << s << endl;
			}
			break;
		}
		cout << s << ": hello, " << s << endl;
	}
	return 0;
}
