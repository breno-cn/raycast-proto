#include <raylib.h>

#define DEFAULT_TILE_WIDTH 16
#define DEFAULT_TILE_HEIGHT 16

enum class TileType {
    Floor, Wall,
};

class Tile {

private:
    Tile(TileType type, int width, int height);

public:
    TileType _type;
    int _width;
    int _height;

    static Tile wall();
    static Tile floor();

    Tile();
};
