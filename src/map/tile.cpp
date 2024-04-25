#include "tile.hpp"

Tile::Tile() {
    _type = TileType::Floor;
    _width = DEFAULT_TILE_WIDTH;
    _height = DEFAULT_TILE_HEIGHT;
}

Tile::Tile(TileType type, int width, int height) {
    _type = type;
    _width = width;
    _height = height;
}

Tile Tile::wall() {
    return Tile(TileType::Wall, DEFAULT_TILE_WIDTH, DEFAULT_TILE_HEIGHT);
}

Tile Tile::floor() {
    return Tile(TileType::Floor, DEFAULT_TILE_WIDTH, DEFAULT_TILE_HEIGHT);
}
