#include <stdio.h>
#include <stdlib.h>

int n, pre[10], post[10], i, cnt;

int dfs(int l, int r)
{
    if (l > r)
        return 0;
    if (l == r)
    {
        --i;
        return 1;
    }
    int root = post[--i], mid = l;
    while (pre[mid] != root)
        ++mid;
    int b = dfs(mid, r), a = dfs(l + 1, mid - 1);
    if (a ^ b)
        ++cnt;
    return a | b;
}

int main()
{
    while (~scanf("%d", &n))
    {
        i = cnt = 0;
        for (int i = 0; i < n; i++)
            scanf("%d", pre + i);
        for (int i = 0; i < n; i++)
            scanf("%d", post + i);
        i = n - 1;
        cnt = 0;
        dfs(0, n - 1);
        printf("%d\n", 1 << cnt);
    }
    return 0;
}
