#include "player.h"
#include "board.h"

namespace SpyAlley {

bool in_spy_alley(const Player &player) {
  return player.space >= Board::spy_alley_begin &&
         player.space <= Board::spy_alley_end;

  return false;
}
} // namespace SpyAlley
