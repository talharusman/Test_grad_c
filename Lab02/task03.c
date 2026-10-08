/* Task 3: Princess Pixel Outfit Selector */
#include <stdio.h>

int main(void)
{
    int day;
    char weather;

    if (scanf("%d %c", &day, &weather) != 2)
    {
        printf("Wardrobe error!\n");
        return 0;
    }

    /* Validate day and weather code first */
    if (day < 1 || day > 7 || (weather != 'S' && weather != 'R'))
    {
        printf("Wardrobe error!\n");
        return 0;
    }

    if (day >= 6)
    {
        printf("Royal Robe\n");
    }
    else if (weather == 'S')
    {
        printf("Golden Gown\n");
    }
    else
    {
        printf("Blue Bubble Coat\n");
    }

    return 0;
}
