#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	vector<bool> v(n + 1, true);
	for (int i = 0; i < m; i++)
	{
		int k;
		scanf("%d", &k);
		if (!v[k])
			printf("0u0 ...... ?\n");
		else
		{
			int j = k + 1;
			while (!v[j] && v.begin() + j != v.end())
				j++;
			if (v.begin() + j == v.end())
			{
				printf("0u0 ...... ?\n");
				continue;
			}
			v[j] = false;
			printf("%d\n", j);
		}
	}
	return 0;
}
