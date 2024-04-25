#include <memory>

#include "../player/player.hpp"
#include "../map/game_map.hpp"

class Game {

private:
    std::shared_ptr<Player> _player;
    std::shared_ptr<GameMap> _map;

    void drawRays();

public:
    Game(std::shared_ptr<Player> player, std::shared_ptr<GameMap> map);

    void init();
    void handleInput();
    void update();
    void draw();

};
