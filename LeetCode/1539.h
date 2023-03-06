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

int findKthPositive(int *arr, int arrSize, int k)
{
    int y = 1;
    while (k--)
    {
        while (arrSize && y == *arr)
        {
            ++y;
            ++arr;
            --arrSize;
        }
        ++y;
    }
    return y - 1;
}
