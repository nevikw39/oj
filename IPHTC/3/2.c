/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <stdio.h>
#include <stdlib.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("tune=native")
#pragma comment(linker, "/stack:200000000")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

typedef union
{
    float f;
    unsigned int n;
} U;

int main()
{
    U u;
    while (~scanf("%f", &u.f))
    {
        for (int i = 31; i >= 0; i--)
            putchar_unlocked('0' + !!(u.n & (1U << i)));
        putchar_unlocked('\n');
    }
    return 0;
}