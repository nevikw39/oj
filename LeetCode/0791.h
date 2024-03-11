/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#ifndef nevikw39
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

char arr[26];

int cmp(char *l, char *r) { return arr[*l - 'a'] - arr[*r - 'a']; }

char *customSortString(char *order, char *s)
{
    for (char *ptr = order, cnt = 0; *ptr;)
        arr[*ptr++ - 'a'] = ++cnt;
    qsort(s, strlen(s), sizeof(char), cmp);
    return s;
}
