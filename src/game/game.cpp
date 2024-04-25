#include <raylib.h>

#include <iostream>

#include "game.hpp"

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
    Vector2 rayStart = _player.get()->_position;
    Vector2 rayDirection = Vector2Normalize(_player.get()->_direction);

    Vector2 rayUnitStep = {
        .x = sqrt(1 + (rayDirection.y / rayDirection.x) * (rayDirection.y / rayDirection.x)),
        .y = sqrt(1 + (rayDirection.x / rayDirection.y) * (rayDirection.x / rayDirection.y)),
    };

    Vector2 mapCheck = rayStart;
    Vector2 rayLength1D;
    Vector2 step;

    if (rayDirection.x < 0) {
        step.x = -1;
        rayLength1D.x = (rayStart.x - mapCheck.x) * rayUnitStep.x;
    } else {
        step.x = 1;
        rayLength1D.x = ((mapCheck.x + 1) - rayStart.x) * rayUnitStep.x;
    }

    if (rayDirection.y < 0) {
        step.y = -1;
        rayLength1D.y = (rayStart.y - mapCheck.y) * rayUnitStep.y;
    } else {
        step.y = 1;
        rayLength1D.y = ((mapCheck.y + 1) - rayStart.y) * rayUnitStep.y;
    }

    bool tileFound = false;
    float currentDistance = 0;
    const float maxDistance = 1000;
    while (!tileFound && currentDistance < maxDistance) {
        // walk
        if (rayLength1D.x < rayLength1D.y) {
            mapCheck.x += step.x;
            currentDistance = rayLength1D.x;
            rayLength1D.x += rayUnitStep.x;
        } else {
            mapCheck.y += step.y;
            currentDistance = rayLength1D.y;
            rayLength1D.y += rayUnitStep.y;
        }

        int mapX = (int) (mapCheck.x) / TILE_SIZE.x;
        int mapY = (int) (mapCheck.y) / TILE_SIZE.y;

        std::cout << mapX << " " << mapY << std::endl;

        if (mapX >= 0 && mapX < MAP_WIDTH && mapY >= 0 && mapY < MAP_HEIGHT) {
            if (_map.get()->_tiles[mapX][mapY] == WALL) {
                tileFound = true;
            } 
        }
    }

    Vector2 intersection = Vector2Zero();
    if (true) {
        intersection = Vector2Add(rayStart, Vector2Scale(rayDirection, currentDistance));

        // DrawRectangleV(intersection, { 5, 5 }, PURPLE);
        DrawLineEx(_player.get()->_position, intersection, 5, GREEN);
    }
}

// void Game::drawRays() {
//     float rayAngle = _player.get()->_angle;
//     float rayY;
//     float rayX;
//     float yOffeset;
//     float xOffset;
//     float depthOfField;

//     const int maxDepthOfField = 32;

//     for (int i = 0; i < 1; i++) {
//         float inverseTangent = -1 / tan(rayAngle);
        
//         // looking up
//         if (rayAngle > PI) {
//             rayY = (((int) _player.get()->_position.y >> 6) << 6) - 0.0001;
//             rayX = (_player.get()->_position.y - rayY) * inverseTangent + _player.get()->_position.x;
//             yOffeset = -64;
//             xOffset = -yOffeset * inverseTangent;
//         }

//         // looking down
//         if (rayAngle < PI) {
//             rayY = (((int) _player.get()->_position.y >> 6) << 6) + 64;
//             rayX = (_player.get()->_position.y - rayY) * inverseTangent + _player.get()->_position.x;
//             yOffeset = 64;
//             xOffset = -yOffeset * inverseTangent;
//         }

//         // looking straight left or right
//         if (rayAngle == 0 || rayAngle == PI) {
//             rayX = _player.get()->_position.x;
//             rayY = _player.get()->_position.y;
//             depthOfField = 8;
//         }

//         while (depthOfField < maxDepthOfField) {
//             int mapX;
//             int mapY;

//             mapX = floor((rayX) / MAP_WIDTH);
//             mapY = floor((rayY) / MAP_HEIGHT);
//             // mapPosition = mapY*MAP_WIDTH + mapX;


//             if (mapX > 0 && mapY > 0 && mapX < MAP_WIDTH && mapY < MAP_HEIGHT && _map.get()->_tiles[mapX][mapY] == WALL) {
//                 depthOfField = maxDepthOfField;
//             } else {
//                 rayX += xOffset;
//                 rayY += yOffeset;
//                 depthOfField += 1;
//             }
//         }

//         Vector2 endPosition = { rayX, rayY };
//         DrawLineV(_player.get()->_position, endPosition, BLUE);
//         // std::cout << endPosition.x << " " << endPosition.y << std::endl;
//     }
// }

void Game::draw() {
    _map.get()->draw();
    _player.get()->draw();

    drawRays();
}
