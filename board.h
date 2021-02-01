#include <chrono>
#include <functional>
#include <optional>
#include <random>
#include <string>
#include <vector>

namespace SpyAlley {
struct Player;
}

namespace SpyAlley {
int roll_die();
} // namespace SpyAlley

namespace SpyAlley::Board {

constexpr int total_players = 1;
constexpr int num_spaces = 24;
constexpr int num_spy_alley_spaces = 9;
constexpr int spy_alley_begin = 24;
constexpr int spy_alley_end = 32;

struct Space;

using AllPlayers = std::array<Player, total_players>;

using BoardType = std::vector<Space>;

std::vector<Space> make_board();

enum class SpaceType {
  NOOP,
  START,
  MOVE_CARD,
  SPY_ALLEY_ENTRANCE,
  SPY_ALLEY_GUESS
};

typedef void (*Action)(const BoardType &board, Player &,
                       AllPlayers &, int, int);

struct Space {
  int index = 0;
  int next = -1;
  int back = -1;
  const int alternate = -1; // path into spy alley.
  const bool part_of_spy_alley = false;
  SpaceType type = SpaceType::NOOP;

  // player, players, roll, left
  Action action;
};

namespace Actions {

void noop(const BoardType &board, Player &p1, AllPlayers &players,
          int initial_roll, int moves_left);
void check_enter_spy_alley(const BoardType &board, Player &p1,
                           AllPlayers &players, int initial_roll,
                           int moves_left);
void start_space(const BoardType &board, Player &p1,
                 AllPlayers &players, int initial_roll,
                 int moves_left);

void make_guesses(const BoardType &board, Player &p1,
                  AllPlayers &players, int initial_roll,
                  int moves_left);
} // namespace Actions

} // namespace SpyAlley::Board
