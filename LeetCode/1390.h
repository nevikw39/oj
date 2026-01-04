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

int sumFourDivisors(int *const nums, int numsSize)
{
    int sum = 0;
    for (int *ptr = nums; numsSize--; ptr++)
    {
        int divisor = 0;
        for (int i = 2; i * i <= *ptr; i++)
            if (!(*ptr % i))
                if (!divisor)
                    divisor = i;
                else
                {
                    divisor = 0;
                    break;
                }
        if (divisor && divisor * divisor != *ptr)
            sum += 1 + *ptr + divisor + *ptr / divisor;
    }
    return sum;
}
