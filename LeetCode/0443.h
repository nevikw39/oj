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

int compress(char *chars, int charsSize)
{
    char *ptr = chars;
    for (int i = 1, cnt = 1; i <= charsSize; i++)
        if (i == charsSize || chars[i] != chars[i - 1])
        {
            *ptr++ = chars[i - 1];
            if (cnt != 1)
            {
                char buf[10];
                int l = sprintf(buf, "%d", cnt);
                memcpy(ptr, buf, l);
                ptr += l;
            }
            cnt = 1;
        }
        else
            ++cnt;
    return ptr - chars;
}
