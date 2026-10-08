/* Task 2: Commander Rex Fuel Calculator */
#include <stdio.h>

int main(void)
{
    char fuel;
    double distance;
    double weight;
    double rate = 0.0;
    double cost;

    if (scanf(" %c %lf %lf", &fuel, &distance, &weight) != 3)
    {
        printf("Mission aborted — invalid data!\n");
        return 0;
    }

    /* Accept lowercase codes too */
    if (fuel == 'A' || fuel == 'a')
    {
        rate = 5.0;
    }
    else if (fuel == 'B' || fuel == 'b')
    {
        rate = 3.0;
    }
    else if (fuel == 'C' || fuel == 'c')
    {
        rate = 7.0;
    }
    else
    {
        printf("Mission aborted — invalid data!\n");
        return 0;
    }

    if (distance <= 0 || weight < 0)
    {
        printf("Mission aborted — invalid data!\n");
        return 0;
    }

    cost = rate * distance;

    if (weight > 1000)
    {
        cost = cost * 1.40;
    }
    else if (weight > 500)
    {
        cost = cost * 1.20;
    }

    printf("Fuel cost: %.2f credits\n", cost);

    return 0;
}
