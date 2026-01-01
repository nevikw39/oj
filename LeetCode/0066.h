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

int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    int *y = malloc((*returnSize = digitsSize + 1) * sizeof(int));
    bool carry = true;
    for (int i = digitsSize - 1; ~i; i--)
    {
        const int sum = digits[i] + carry;
        y[i] = sum % 10;
        carry = sum / 10;
    }
    if (carry)
    {
        *y = 1;
        y[digitsSize] = 0;
    }
    else
        --*returnSize;
    return y;
}
