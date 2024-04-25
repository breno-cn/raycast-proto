#include <memory>
// #include <raylib.h>
// #include <raymath.h>

// #include "../map/game_map.hpp"
#include "raylib.h"
#include "raymath.h"

// #define PLAYER_SIZE Vector2{8,8}
constexpr Vector2 PLAYER_SIZE = Vector2 { .x = 16, .y = 16 };

class Player {

private:
    float _acceleration;
    // float _dx;
    // float _dy;

public:
    float _angle;
    Vector2 _position;
    Vector2 _direction;

    void init();    
    void update();
    void draw();

};
