#include <raylib.h>
#include <memory>

#include "game/game.hpp"

int main() {
    int width = 1024;
    int height = 512;

    auto player = std::make_shared<Player>();
    auto map = std::make_shared<GameMap>();
    Game game(player, map);

    InitWindow(width, height, "3D or 2.5D prototype");

    game.init();
    
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);

            // handle input
            game.handleInput();

            // update
            game.update();

            // draw
            game.draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}