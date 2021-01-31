#include <iostream>
#include <string>
#include <vector>

namespace SpyAlley {

enum class Spy { RUSSIAN, SPANISH, GERMAN, FRENCH, AMERICAN, ENGLISH };

struct Player {
  int id = -1;
  Spy country = Spy::RUSSIAN;
  int space = 0;
  int times_past_go = -1;
};

inline auto make_player(int &count, std::vector<Spy>::iterator spy) -> Player {

  Player player;
  player.id = count++;
  player.country = *spy;
  player.space = 0;
  return player;
}

inline std::ostream &operator<<(std::ostream &str, const Spy &spy) {
  switch (spy) {
  case Spy::RUSSIAN:
    str << "RUSSIAN";
    break;
  case Spy::SPANISH:
    str << "SPANISH";
    break;
  case Spy::GERMAN:
    str << "GERMAN";
    break;
  case Spy::FRENCH:
    str << "FRENCH";
    break;
  case Spy::AMERICAN:
    str << "AMERICAN";
    break;
  case Spy::ENGLISH:
    str << "ENGLISH";
    break;
  }
  return str;
}

inline std::ostream &operator<<(std::ostream &str, const Player &player) {
  str << player.id << ":" << player.country << "\n";
  return str;
}

bool in_spy_alley(const Player &player);

} // namespace SpyAlley
