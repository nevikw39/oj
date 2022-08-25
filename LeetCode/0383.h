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

inline bool canConstruct(char *ransomNote, char *magazine)
{
    int arr[26] = {0}, brr[26] = {0};
    for (char *ptr = ransomNote; *ptr; ptr++)
        ++arr[*ptr - 'a'];
    for (char *ptr = magazine; *ptr; ptr++)
        ++brr[*ptr - 'a'];
    for (int i = 0; i < 26; i++)
        if (arr[i] > brr[i])
            return false;
    return true;
}
