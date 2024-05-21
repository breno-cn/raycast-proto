#pragma once

#include <raylib.h>
#include <raymath.h>
#include <memory>

#include "../map/game_map.hpp"

typedef struct {
    Vector2 position;
    float length;
    bool hitWall;
} Raycast;

Raycast castRay(Vector2 startPosition, Vector2 dir, std::shared_ptr<GameMap> map);
