#include "player.hpp"

void Player::init() {
    _position = Vector2 { .x = 300, .y = 300 };
    _acceleration = 5;

    _direction = { cos(_angle) * 5, sin(_angle) * 5 };
}

void Player::update() {
    if (IsKeyDown(KEY_A)) {
        _angle -= 0.1;
        if (_angle < 0) {
            _angle += 2*PI;
        }

        _direction = { cos(_angle) * 5, sin(_angle) * 5 };
    }

    if (IsKeyDown(KEY_D)) {
        _angle += 0.1;
        if (_angle >2*PI) {
            _angle -= 2*PI;
        }

        _direction = { cos(_angle) * 5, sin(_angle) * 5 };
    }

    if (IsKeyDown(KEY_W)) {
        _position = Vector2Add(_position, _direction);
    }

    if (IsKeyDown(KEY_S)) {
        _position = Vector2Subtract(_position, _direction);
    }
}

void Player::draw() {
    Rectangle rec = {
        .x = _position.x,
        .y = _position.y,
        .width = PLAYER_SIZE.x,
        .height = PLAYER_SIZE.y,
    };

    Vector2 origin = { PLAYER_SIZE.x / 2, PLAYER_SIZE.y / 2 };

    DrawRectanglePro(rec, origin, _angle * 180/PI, RED);

    Vector2 startPosition = _position;
    Vector2 endPosition = Vector2Add(startPosition, Vector2Scale(_direction, 5));

    DrawLineEx(startPosition, endPosition, 3, PURPLE);
}
