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

int cmp(const int *const lhs, const int *const rhs) { return *lhs - *rhs; }

long long putMarbles(int *weights, int weightsSize, int k)
{
    int *arr = calloc(sizeof(int), weightsSize - 1);
    for (int i = 0; i < weightsSize - 1; i++)
        arr[i] = weights[i] + weights[i + 1];
    qsort(arr, weightsSize - 1, sizeof(int), cmp);
    int64_t y = 0;
    for (int i = 0; i < k - 1; i++)
        y += arr[weightsSize - 1 - i - 1] - arr[i];
    free(arr);
    return y;
}
