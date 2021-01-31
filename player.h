#include <string>

namespace SpyAlley
{

enum class Spy { RUSSIAN, SPANISH, GERMAN, FRENCH, AMERICAN, ENGLISH };

struct Player {
  int id;
  Spy country;
    
  };
}
