/* Task 5: Triangle Artifact Classifier */
#include <stdio.h>

int main(void)
{
    double a, b, c;

    if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
    {
        printf("Not a valid triangle!\n");
        return 0;
    }

    /* All sides positive and triangle inequality must hold */
    if (a <= 0 || b <= 0 || c <= 0 ||
        a + b <= c || a + c <= b || b + c <= a)
    {
        printf("Not a valid triangle!\n");
    }
    else if (a == b && b == c)
    {
        printf("Equilateral triangle!\n");
    }
    else if (a == b || a == c || b == c)
    {
        printf("Isosceles triangle!\n");
    }
    else
    {
        printf("Scalene triangle!\n");
    }

    return 0;
}
