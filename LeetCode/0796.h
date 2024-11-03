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

bool rotateString(char *const __restrict s, char *const __restrict goal)
{
    const unsigned l_s = strlen(s), l_goal = strlen(goal);
    if (l_s != l_goal)
        return false;
    char *const goal_double = malloc(sizeof(char) * (l_goal << 1 | 1));
    strcpy(goal_double, goal);
    strcpy(goal_double + l_goal, goal); // strcat(goal_double, goal);
    bool y = strstr(goal_double, s);    // `strstr()` might have a quadratic worst-case complexity! Consider to use Gusfield algorithm (Z function)
    free(goal_double);
    return y;
}
