#include <optional>
#include <string>
#include <vector>

namespace SpyAlley{
  struct Player;
}

namespace SpyAlley::Board {

const int num_spaces = 24 + 9;
  
  struct Space {
    int index = 0;
    const int back = -1;
    const int forward = -1;
    const int alternate = -1; // path into spy alley.
    virtual void action(Player &player, std::optional<Player*> other_player,
                      int moves_left){};
};

namespace Actions {
struct DrawMoveCard {
  void action(Player &p1, Player &p2) {}
};

struct EnterSpyAlley {};

} // namespace Actions

} // namespace SpyAlley::Board
