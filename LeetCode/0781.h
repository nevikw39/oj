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

int numRabbits(int *answers, int answersSize)
{
    int arr[1000] = {}, y = 0;
    while (answersSize--)
        ++arr[*answers++];
    for (int i = 0; i < 1000; i++)
        y += (i[arr] + i) / (i + 1) * (i + 1);
    return y;
}
