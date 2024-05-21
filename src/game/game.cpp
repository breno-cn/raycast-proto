#include <raylib.h>

#include <iostream>

#include "game.hpp"
#include "../rendering/raycast.h"

#define ONE_DEGREE_IN_RADIUS 0.0174533

Game::Game(std::shared_ptr<Player> player, std::shared_ptr<GameMap> map) {
    _player = player;
    _map = map;
}

void Game::init() {
    // _map.get()->init();
    _player.get()->init();
}

void Game::handleInput() {
    PollInputEvents();
}

void Game::update() {
    _player.get()->update();
}

void Game::drawRays() {
    Vector2 playerPosition = _player.get()->_position;

    int screenWidth = 1024;

    int fov = 60;
    float angle = _player.get()->_angle - (fov / 2 * ONE_DEGREE_IN_RADIUS);
    if (angle < 0) {
        angle += 2*PI;
    }
    Vector2 direction = { cos(angle) * 5, sin(angle) * 5 };

    for (int i = 0; i < fov; i++) {
        Raycast ray = castRay(_player.get()->_position, direction, _map);

        DrawLineEx(_player.get()->_position, ray.position, 1, GREEN);

        angle += ONE_DEGREE_IN_RADIUS;
        if (angle > 2*PI) {
            angle -= 2*PI;
        }
        direction = { cos(angle) * 5, sin(angle) * 5 };

        // draw line
        float distance = ray.length;
        // Color color = { 150 - distance * 1.5, 150 - distance * 1.5, 150 - distance * 1.5, 255 };
        Color color = BLACK;

        float lineThickness = 10;
        // DrawRectangle((i * lineThickness + (lineThickness * fov/2) + (10*TILE_SIZE.x)), 5*TILE_SIZE.x - (1000 / distance)/2, lineThickness, (1000 / distance), color);
        DrawRectangle(i*lineThickness + 512, 3*TILE_SIZE.x - (1000 / distance)/2, lineThickness, (10000 / distance), color);
    }

}

void Game::draw() {
    _map.get()->draw();
    _player.get()->draw();

    drawRays();
}
