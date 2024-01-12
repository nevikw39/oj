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

bool halvesAreAlike(char *s)
{
    int a = 0, b = 0;
    for (int i = 0, l = strlen(s), *ptr = &a; i < l; i++)
    {
        if (i == l >> 1)
            ptr = &b;
        switch (*s++ | ' ')
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            ++*ptr;
            break;
        }
    }
    return a == b;
}
