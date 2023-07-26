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

double f(int *dist, int distSize, int speed)
{
    double h = 0;
    while (distSize)
    {
        double t = 1. * *dist++ / speed;
        h += --distSize ? ceil(t) : t;
    }
    return h;
}

int minSpeedOnTime(int *dist, int distSize, double hour)
{
    int speed = 1e7;
    for (int jump = speed >> 1; jump; jump >>= 1)
        while (speed - jump > 0 && f(dist, distSize, speed - jump) <= hour)
            speed -= jump;
    return speed == 1e7 && f(dist, distSize, speed) > hour ? -1 : speed;
}
