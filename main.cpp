#include "board.h"
#include "player.h"
#include <algorithm>
#include <any>
#include <chrono>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>


using namespace std;
using namespace SpyAlley;

mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());

void make_move(const vector<Board::Space> &board, Player &player,
               vector<Player> &players, int roll, int left) {

  auto &space = board[player.space];
  space.action(board, player, players, roll, left);
}

int main(int argc, char **argv) {

  bool done = false;

  int count = 1;
  vector<Spy> available_spies = {Spy::RUSSIAN, Spy::SPANISH,  Spy::GERMAN,
                                 Spy::FRENCH,  Spy::AMERICAN, Spy::ENGLISH};

  auto spy_pick = begin(available_spies);
  auto as_end = end(available_spies);

  std::shuffle(spy_pick, as_end, generator);

  vector<Player> players{make_player(count, spy_pick++),
                         make_player(count, spy_pick++),
                         make_player(count, spy_pick++)};

  for (const auto &player : players) {
    cout << player;
  }

  auto board = Board::make_board();

  while (!done) {

    for (auto &player : players) {
      int roll = roll_die();
      int left = roll;

      cout << player.id << " rolled " << roll << "\n";
      while (left) {
        // Run AI and move the player.
        make_move(board, player, players, roll, left);
        --left;
      }

      done = all_of(begin(players), end(players), [](const auto &player) {
        return player.times_past_go > 0;
      });
    }
  }

  return 0;
}
