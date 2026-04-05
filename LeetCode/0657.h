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

bool judgeCircle(const char *moves)
{
    int x = 0, y = 0;
    while (*moves)
        switch (*moves++)
        {
        case 'R':
            ++x;
            break;
        case 'L':
            --x;
            break;
        case 'U':
            ++y;
            break;
        default: // 'D'
            --y;
            break;
        }
    return !x && !y;
}
