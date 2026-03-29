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

static inline void f(const char *restrict s, int *restrict o, int *restrict e)
{
    while (*s)
    {
        ++e[*s++ - 'a'];
        int *const tmp = e;
        e = o;
        o = tmp;
    }
}

bool canBeEqual(const char *const restrict s1, const char *const restrict s2)
{
    int o1[26] = {}, e1[26] = {}, o2[26] = {}, e2[26] = {};
    f(s1, o1, e1);
    f(s2, o2, e2);
    return !memcmp(o1, o2, sizeof o1) && !memcmp(e1, e2, sizeof e2);
}
