#include <raylib.h>
#include <raymath.h>
#include <memory>

#include <iostream>

#include "game_map.hpp"

GameMap::GameMap() {
}

void GameMap::init() {
}

void GameMap::draw() {
    Vector2 position = Vector2Zero();

    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (_tiles[i][j] == WALL) {
                DrawRectangleV(position, TILE_SIZE, BLACK);
            } else {
                DrawRectangleLines(position.x, position.y, TILE_SIZE.x, TILE_SIZE.y, BLACK);
            }

            position.x += TILE_SIZE.x;
        }

        position.x = 0;
        position.y += TILE_SIZE.y;
    }

    DrawFPS(0, 0);
}
