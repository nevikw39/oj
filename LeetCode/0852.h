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

int peakIndexInMountainArray(int *arr, int arrSize)
{
    int l = 0, r = arrSize - 1;
    while (l < r)
    {
        int mid1 = l + (r - l) / 3, mid2 = r - (r - l) / 3;
        if (mid1[arr] <= mid2[arr])
            l = mid1 + 1;
        if (mid1[arr] >= mid2[arr])
            r = mid2 - 1;
    }
    return l;
}
