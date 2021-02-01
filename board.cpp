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
void noop(const BoardType &board, Player &player,
          AllPlayers &players, int initial_roll, int moves_left) {

  // no end of turn actions
  if (moves_left == 0)
    return;
  const auto &current_space = board[player.space];
  player.space = current_space.next;
}

void check_enter_spy_alley(const BoardType &board, Player &player,
                           AllPlayers &players, int initial_roll,
                           int moves_left) {

  // no end of turn actions
  if (moves_left == 0)
    return;

  const auto &current_space = board[player.space];

  if (initial_roll == moves_left &&
      current_space.type == Board::SpaceType::SPY_ALLEY_ENTRANCE) {
    // If this is that start of a turn enter spy alley.
    // Forced to enter spy alley.
    player.space = current_space.alternate;
  } else {
    // check if a player is in spy alley.
    const int DIST_FROM_ENTRANCE_TO_GUESS = 2;
    bool any_in_spy_alley = any_of(begin(players), end(players), in_spy_alley);
    if (any_in_spy_alley && moves_left == DIST_FROM_ENTRANCE_TO_GUESS) {
      player.space = current_space.alternate;
    } else {
      player.space = current_space.next;
    }
  }
}

void start_space(const BoardType &board, Player &player,
                 AllPlayers &players, int initial_roll,
                 int moves_left) {
  // no end of turn actions
  if (moves_left == 0)
    return;

  player.times_past_go++;
  player.space = board[player.space].next;
};

void make_guesses(const BoardType &board, Player &p1,
                  AllPlayers &players, int initial_roll,
                  int moves_left) {
  static mt19937 generator(
      std::chrono::system_clock::now().time_since_epoch().count());

  //  Only guess if end of turn.
  if (moves_left != 0) {
    p1.space = board[p1.space].next;
    return;
  }

  for (auto &other_player : players) {
    if (p1.id != other_player.id && in_spy_alley(other_player)) {
      vector<Spy> available_spies = {Spy::RUSSIAN, Spy::SPANISH,  Spy::GERMAN,
                                     Spy::FRENCH,  Spy::AMERICAN, Spy::ENGLISH};

      auto spy_pick = begin(available_spies);
      auto as_end = end(available_spies);

      std::shuffle(spy_pick, as_end, generator);

      auto guess_is = *spy_pick;
      if (other_player.country == guess_is) {
        other_player.eliminated = true;
      } else {
      }
    }
  }
}

} // namespace Board::Actions

} // namespace SpyAlley
