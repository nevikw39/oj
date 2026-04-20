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

int maxDistance(const int *const restrict colors, int colorsSize)
{
    for (int i = 0; i < colorsSize; i++)
        if (colors[0] != colors[colorsSize - 1 - i] || colors[i] != colors[colorsSize - 1])
            return colorsSize - 1 - i;
    assert(false);
}
