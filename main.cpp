#include "board.h"
#include "player.h"
#include <algorithm>
#include <any>
#include <array>
#include <chrono>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

using namespace std;
using namespace SpyAlley;

mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());

void make_move(const vector<Board::Space> &board, Player &player,
               Board::AllPlayers &players, int roll, int left) {

  auto &space = board[player.space];
  space.action(board, player, players, roll, left);
}

int main(int argc, char **argv) {
  auto board = Board::make_board();

  double eliminated_count = 0;
  double total = 0;

  for (int i = 0; i < 100000; ++i) {

    vector<Spy> available_spies = {Spy::RUSSIAN, Spy::SPANISH,  Spy::GERMAN,
                                   Spy::FRENCH,  Spy::AMERICAN, Spy::ENGLISH};

    auto spy_pick = begin(available_spies);
    auto as_end = end(available_spies);

    std::shuffle(spy_pick, as_end, generator);

    int count = 1;
    Board::AllPlayers players{
        make_player(count, spy_pick++), make_player(count, spy_pick++),
        make_player(count, spy_pick++), make_player(count, spy_pick++),
        make_player(count, spy_pick++), make_player(count, spy_pick++)};

    bool done = false;
    while (!done) {

      for (auto &player : players) {
        int roll = roll_die();
        int left = roll;

        while (left) {
          // Run AI and move the player.
          make_move(board, player, players, roll, left);
          --left;
        }

        // End turn actions
        board[player.space].action(board, player, players, roll, left);

        // End after all players make it one loop.
        done = all_of(begin(players), end(players), [](const auto &player) {
          return player.times_past_go > 0;
        });
      }
    }

    if (any_of(begin(players), end(players),
               [](const auto &player) { return player.eliminated; }))
      eliminated_count++;
    total++;
  }

  cout << "Percent one eliminted: " << eliminated_count / total << "\n";

  return 0;
}
