/* Task 4: Alien World Temperature Zone
   Uses strictly nested if-else statements (no else-if chains). */
#include <stdio.h>

int main(void)
{
    double temperature;

    if (scanf("%lf", &temperature) != 1)
    {
        return 0;
    }

    if (temperature < 0)
    {
        printf("Freezing zone — wear thermal suit.\n");
    }
    else
    {
        if (temperature < 21)
        {
            printf("Cool zone — wear jacket.\n");
        }
        else
        {
            if (temperature <= 35)
            {
                printf("Comfortable zone — light clothes.\n");
            }
            else
            {
                printf("Danger zone — activate cooling gear.\n");
            }
        }
    }

    return 0;
}
