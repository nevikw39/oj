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

int f(const char *l, const char *r) { return *l - *r; }
int g(const char *l, const char * const *r) { return strcmp(l, *r); }

bool reorderedPowerOf2(int n)
{
    static const char *arr[] = {"0112344778", "011237", "0122579", "012356789", "0124", "0134449", "0145678", "01466788", "0248", "0368888", "0469", "1", "112234778", "11266777", "122446", "1234446788", "125", "128", "1289", "13468", "16", "2", "224588", "23", "23334455", "234455668", "23678", "256", "35566", "4", "46", "8"};
    char str[10];
    qsort(str, sprintf(str, "%d", n), sizeof(char), f);
    return bsearch(str, arr, 32, sizeof(char *), g);
}
