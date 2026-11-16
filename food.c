#include "food.h"
#include <stdlib.h>

Food generate_food(int board_width, int board_height) {
    Food food = {0, 0, board_width, board_height};
    return respawn_food(&food);
}

Food respawn_food(Food *food) {
    food->x = rand() % food->board_width;
    food->y = rand() % food->board_height;
    return *food;
}
