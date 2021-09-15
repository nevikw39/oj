/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const char **l, const char **r)
{
    if (strstr(*l, *r) != NULL)
        return 1;
    if (strstr(*r, *l) != NULL)
        return -1;
    puts("NO");
    exit(0);
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    char **strs = malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++)
    {
        strs[i] = malloc(sizeof(char) * 10001);
        scanf("%s", strs[i]);
    }
    qsort(strs, n, sizeof(char *), cmp);
    puts("YES");
    for (int i = 0; i < n; i++)
    {
        puts(strs[i]);
        free(strs[i]);
    }
    free(strs);
    return 0;
}