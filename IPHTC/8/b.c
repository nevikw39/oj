/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("tune=native")
#pragma comment(linker, "/stack:200000000")
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")

int main()
{
    int n, arr[26] = {0};
    scanf("%d\n", &n);
    if (n == 1)
    {
        puts("I'm the god of Knuckles!");
        return 0;
    }
    while (n--)
        ++arr[getchar_unlocked() - 'a'];
    for (int i = 0; i < 26; i++)
        if (arr[i] > 1)
        {
            puts("I'm the god of Knuckles!");
            return 0;
        }
    puts("Different makes perfect");
    return 0;
}
