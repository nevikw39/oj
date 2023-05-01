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

double average(int *salary, int salarySize)
{
    int sum = 0, min = INT_MAX, max = INT_MIN;
    for (int i = salarySize; i--; salary++)
    {
        sum += *salary;
        if (min > *salary)
            min = *salary;
        if (max < *salary)
            max = *salary;
    }
    return (sum - min - max) / (salarySize - 2.);
}
