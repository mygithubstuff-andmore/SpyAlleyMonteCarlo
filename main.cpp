#include "board.h"
#include "player.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

using namespace std;
using namespace SpyAlley;

std::default_random_engine generator;

auto make_player(int &count, vector<Spy>::iterator& spy) -> Player {

  Player player;
  player.id = count++;
  player.country = *spy;
  ++spy;
  return player;
}

int main(int argc, char **argv) {

  bool done = false;

  int count = 1;
  vector<Spy> available_spies = {Spy::RUSSIAN, Spy::SPANISH,  Spy::GERMAN,
                                 Spy::FRENCH,  Spy::AMERICAN, Spy::ENGLISH};

  auto spy_pick = begin(available_spies);
  auto as_end = end(available_spies);

  std::shuffle(spy_pick, as_end, generator);

  vector<Player> players{make_player(count, spy_pick),
                         make_player(count, spy_pick),
                         make_player(count, spy_pick)};

  while (!done) {
  }

  return 0;
}
