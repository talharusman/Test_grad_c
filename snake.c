#include "snake.h"
#include <raylib.h>

void update_movement_intent(Snake *player) {
    if ((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) && player->direction.y != 1) {
        player->direction.x = 0;
        player->direction.y = -1;
    }

    if ((IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) && player->direction.y != -1) {
        player->direction.x = 0;
        player->direction.y = 1;
    }

    if ((IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) && player->direction.x != 1) {
        player->direction.x = -1;
        player->direction.y = 0;
    }

    if ((IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) && player->direction.x != -1) {
        player->direction.x = 1;
        player->direction.y = 0;
    }
}

void setup_snake(Snake *snake_ptr) {
    snake_ptr->length = 3;
    snake_ptr->body[0] = (Vector2Grid){12, 12};
    snake_ptr->body[1] = (Vector2Grid){11, 12};
    snake_ptr->body[2] = (Vector2Grid){10, 12};
    snake_ptr->direction = (Vector2Grid){1, 0};
}

void advance_snake(Snake *snake_ptr) {
    for (int tracker = snake_ptr->length - 1; tracker > 0; tracker--) {
        snake_ptr->body[tracker] = snake_ptr->body[tracker - 1];
    }

    snake_ptr->body[0].x += snake_ptr->direction.x;
    snake_ptr->body[0].y += snake_ptr->direction.y;
}
