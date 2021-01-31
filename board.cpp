#include "board.h"
#include "player.h"
#include <algorithm>

using namespace std;

namespace SpyAlley {

int roll_die() {

  // Init generator
  static std::mt19937 generator(
      std::chrono::system_clock::now().time_since_epoch().count());

  // Init uniform distribution.
  static std::uniform_int_distribution<int> roller(1, 6);

  return roller(generator);
}

namespace Board::Actions {
void noop(const BoardType &board, Player &player, std::vector<Player> &players,
          int initial_roll, int moves_left) {

  const auto &current_space = board[player.space];
  player.space = current_space.next;
}

void check_enter_spy_alley(const BoardType &board, Player &player,
                           std::vector<Player> &players, int initial_roll,
                           int moves_left) {

  const auto &current_space = board[player.space];
  if (initial_roll == moves_left &&
      current_space.type == Board::SpaceType::SPY_ALLEY_ENTRANCE) {
    // Forced to enter spy alley.
    player.space = current_space.alternate;
    cout << "Enterd Spy Alley\n";
  } else {
    // check if a player is in spy alley.

    bool any_in_spy_alley = any_of(begin(players), end(players), in_spy_alley);
    if (any_in_spy_alley) {
      player.space = current_space.alternate;
    } else {
      player.space = current_space.next;
    }
  }
}

void start_space(const BoardType &board, Player &player,
                 std::vector<Player> &players, int initial_roll,
                 int moves_left) {
  cout << "GO" << endl;
  player.times_past_go++;
  player.space = board[player.space].next;
};

} // namespace Board::Actions

} // namespace SpyAlley
