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

auto make_player(int &count, vector<Spy>::iterator &available_spies_begin,
                 vector<Spy>::iterator &available_spies_end) -> Player {

  Player player;
  player.id = count++;

  std::shuffle(available_spies_begin, available_spies_end, generator);

  std::advance(available_spies_end, -1);
  player.country = *available_spies_end;

  return player;
}

int main(int argc, char **argv) {

  bool done = false;

  int count = 1;
  vector<Spy> available_spies = {Spy::RUSSIAN, Spy::SPANISH,  Spy::GERMAN,
                                 Spy::FRENCH,  Spy::AMERICAN, Spy::ENGLISH};

  auto as_begin = begin(available_spies);
  auto as_end = end(available_spies);

  vector<Player> players{make_player(count, as_begin, as_end),
                         make_player(count, as_begin, as_end),
                         make_player(count, as_begin, as_end)};

  while (!done) {
  }

  return 0;
}
