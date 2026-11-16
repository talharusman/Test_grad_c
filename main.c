#include "food.h"
#include "snake.h"

#include <raylib.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_WIDTH 20
#define BOARD_HEIGHT 20
#define CELL_SIZE 25
#define WINDOW_WIDTH (BOARD_WIDTH * CELL_SIZE)
#define WINDOW_HEIGHT (BOARD_HEIGHT * CELL_SIZE)
#define MOVE_INTERVAL 0.12f

static bool snake_contains(const Snake *snake, int x, int y) {
    for (int i = 0; i < snake->length; i++) {
        if (snake->body[i].x == x && snake->body[i].y == y) {
            return true;
        }
    }
    return false;
}

static bool snake_hit_itself(const Snake *snake) {
    for (int i = 1; i < snake->length; i++) {
        if (snake->body[0].x == snake->body[i].x &&
            snake->body[0].y == snake->body[i].y) {
            return true;
        }
    }
    return false;
}

static bool snake_outside_board(const Snake *snake) {
    return snake->body[0].x < 0 || snake->body[0].x >= BOARD_WIDTH ||
           snake->body[0].y < 0 || snake->body[0].y >= BOARD_HEIGHT;
}

static void place_food(Food *food, const Snake *snake) {
    do {
        respawn_food(food);
    } while (snake_contains(snake, food->x, food->y));
}

static void reset_game(Snake *snake, Food *food) {
    setup_snake(snake);
    *food = generate_food(BOARD_WIDTH, BOARD_HEIGHT);
    place_food(food, snake);
}

static void draw_game(const Snake *snake, const Food *food, int score,
                      bool game_over) {
    ClearBackground((Color){25, 25, 25, 255});

    for (int x = 0; x < BOARD_WIDTH; x++) {
        for (int y = 0; y < BOARD_HEIGHT; y++) {
            DrawRectangleLines(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE,
                               CELL_SIZE, (Color){45, 45, 45, 255});
        }
    }

    DrawRectangle(food->x * CELL_SIZE, food->y * CELL_SIZE, CELL_SIZE,
                  CELL_SIZE, RED);

    for (int i = 0; i < snake->length; i++) {
        Color color = i == 0 ? LIME : GREEN;
        DrawRectangle(snake->body[i].x * CELL_SIZE,
                      snake->body[i].y * CELL_SIZE, CELL_SIZE, CELL_SIZE,
                      color);
    }

    DrawText(TextFormat("Score: %d", score), 10, 10, 20, WHITE);

    if (game_over) {
        const char *message = "GAME OVER - Press R to restart";
        int width = MeasureText(message, 24);
        DrawRectangle(0, WINDOW_HEIGHT / 2 - 25, WINDOW_WIDTH, 50,
                      (Color){0, 0, 0, 190});
        DrawText(message, (WINDOW_WIDTH - width) / 2, WINDOW_HEIGHT / 2 - 12,
                 24, WHITE);
    }
}

int main(void) {
    srand((unsigned int)time(NULL));
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Snake Game");
    SetTargetFPS(60);

    Snake snake;
    Food food;
    int score = 0;
    float move_timer = 0.0f;
    bool game_over = false;
    reset_game(&snake, &food);

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_R)) {
            score = 0;
            move_timer = 0.0f;
            game_over = false;
            reset_game(&snake, &food);
        }

        if (!game_over) {
            update_movement_intent(&snake);
            move_timer += GetFrameTime();

            if (move_timer >= MOVE_INTERVAL) {
                move_timer = 0.0f;
                Vector2Grid previous_tail = snake.body[snake.length - 1];
                advance_snake(&snake);

                if (snake_outside_board(&snake) || snake_hit_itself(&snake)) {
                    game_over = true;
                } else if (snake.body[0].x == food.x &&
                           snake.body[0].y == food.y) {
                    if (snake.length < MAX_SNAKE) {
                        snake.body[snake.length] = previous_tail;
                        snake.length++;
                    }
                    score++;
                    place_food(&food, &snake);
                }
            }
        }

        BeginDrawing();
        draw_game(&snake, &food, score, game_over);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
