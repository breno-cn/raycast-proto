#include <raylib.h>

#include <iostream>

#include "game.hpp"
#include "../rendering/raycast.h"

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
    Raycast ray = castRay(_player.get()->_position, _player.get()->_direction, _map);

    DrawLineEx(_player.get()->_position, ray.position, 5, GREEN);
}

void Game::draw() {
    _map.get()->draw();
    _player.get()->draw();

    drawRays();
}
