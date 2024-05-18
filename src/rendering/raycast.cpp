#include "raycast.h"

Raycast castRay(Vector2 rayStart, Vector2 direction, std::shared_ptr<GameMap> map) {
    Vector2 rayDirection = Vector2Normalize(direction);

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
    const float maxDistance = 10000;
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


        if (mapX >= 0 && mapX < MAP_WIDTH && mapY >= 0 && mapY < MAP_HEIGHT) {
            if (map.get()->_tiles[mapY][mapX] == WALL) {
                tileFound = true;
                // std::cout << mapX << " " << mapY << std::endl;
            } 
        }
    }

    Vector2 rayPosition = Vector2Add(rayStart, Vector2Scale(rayDirection, currentDistance));
    Raycast ray = { .position = rayPosition, .hitWall = tileFound };

    return ray;
}