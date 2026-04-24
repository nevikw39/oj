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

int furthestDistanceFromOrigin(const char *restrict moves)
{
    int l = 0, r = 0, cnt = 0;
    while (*moves)
        switch (*moves++)
        {
        case 'L':
            ++l;
            continue;
        case 'R':
            ++r;
            continue;
        default:
            ++cnt;
        }
    return (l > r ? l - r : r - l) + cnt;
}
