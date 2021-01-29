#include <string>
#include <functional>

struct Player;

namespace SpyAlley::Board
{

  const int num_spaces = 24 + 9;

  template<typename T>
    concept has_action = requires(T& a, U& p1, U& p2, int moves_left){
								      { a.action(p1, p2, moves_left) } -> std::convertable_to<void>;
  };

  // Space that is not important for this simulation
  template<has_action Action>
  struct Space{
    int index = 0 ;
    const int back = -1;
    const int forward = -1;
    const int alternate = -1;  // path into spy alley.
    Action action;
  };

  namespace Actions {
    struct DrawMoveCard{
      void action(Player& p1, Player& p2
    };

    struct EnterSpyAlley{
    };

    
  }

  std::vector<BoardSpace> board;
}

