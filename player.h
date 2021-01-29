#include <string>

namespace SpyAlley
{

  class enum Spy {
		  RUSSIAN,
		  SPANISH,
		  GERMAN,
		  FRENCH,
		  AMERICAN,
		  ENGLISH
  };
  
  struct Player
  {
    int id;
    Spy country;
    
  };
}
