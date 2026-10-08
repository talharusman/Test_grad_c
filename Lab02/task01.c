/* Task 1: Space-Bot Vital Scanner */
#include <stdio.h>

int main(void)
{
    double temperature;
    int pulse;
    double oxygen;
    int failCount = 0;
    int tempFail = 0;
    int pulseFail = 0;
    int oxygenFail = 0;

    if (scanf("%lf %d %lf", &temperature, &pulse, &oxygen) != 3)
    {
        printf("Scanner malfunction!\n");
        return 0;
    }

    /* Reject impossible readings first */
    if (temperature <= 0 || pulse <= 0 || oxygen < 0 || oxygen > 100)
    {
        printf("Scanner malfunction!\n");
        return 0;
    }

    /* Standard ranges: temp 36.0-38.0 C, pulse 60-100 bpm, oxygen 95-100 % */
    if (temperature < 36.0 || temperature > 38.0)
    {
        tempFail = 1;
        failCount++;
    }
    if (pulse < 60 || pulse > 100)
    {
        pulseFail = 1;
        failCount++;
    }
    if (oxygen < 95.0)
    {
        oxygenFail = 1;
        failCount++;
    }

    if (failCount == 0)
    {
        printf("All systems healthy — robot cleared!\n");
    }
    else if (failCount >= 2)
    {
        printf("Critical condition — send to repair bay!\n");
    }
    else if (tempFail)
    {
        printf("Temperature alert — run cooling subroutine.\n");
    }
    else if (pulseFail)
    {
        printf("Pulse alert — check motor circuits.\n");
    }
    else if (oxygenFail)
    {
        printf("Oxygen alert — replace battery pack.\n");
    }

    return 0;
}
