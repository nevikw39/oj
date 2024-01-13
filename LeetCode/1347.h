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

int inline bwabs(int x) { return (x ^ (x >> ((sizeof(int) << 3) - 1))) - (x >> ((sizeof(int) << 3) - 1)); }

int minSteps(char *s, char *t)
{
    int arr[26] = {}, sum = 0;
    while (*s)
        ++arr[*s++ - 'a'];
    while (*t)
        --arr[*t++ - 'a'];
    for (int i = 0; i < 26; i++)
        sum += bwabs(i[arr]);
    assert(~sum & 1);
    return sum >> 1;
}
