#pragma once

#include <raylib.h>
#include <memory>
#include <vector>

#include "tile.hpp"

#define MAP_WIDTH 8
#define MAP_HEIGHT 8

#define WALL 1
#define FLOOR 0

// #define TILE_SIZE 64

constexpr Vector2 TILE_SIZE = Vector2 { .x = 64, .y = 64 };

class GameMap {

private:


public:    
    int _tiles[MAP_HEIGHT][MAP_WIDTH] = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
    };
    GameMap();

    void init();
    void draw();

};
