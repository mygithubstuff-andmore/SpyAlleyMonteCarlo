#include "board.h"

namespace SpyAlley::Board {
BoardType make_board() {
  // Populate the spaces.
  BoardType spaces{
      Space{0, 1, 23, -1, false, SpaceType::START, Actions::start_space},
      Space{1, 2, 1, -1, false, SpaceType::NOOP, Actions::noop},
      Space{2, 3, 2, -1, false, SpaceType::MOVE_CARD, Actions::noop},
      Space{3, 4, 3, -1, false, SpaceType::NOOP, Actions::noop},
      Space{4, 5, 4, -1, false, SpaceType::NOOP, Actions::noop},
      Space{5, 6, 5, -1, false, SpaceType::MOVE_CARD, Actions::noop},
      Space{6, 7, 6, -1, false, SpaceType::NOOP, Actions::noop},
      Space{7, 8, 7, -1, false, SpaceType::NOOP, Actions::noop},
      Space{8, 9, 8, -1, false, SpaceType::NOOP, Actions::noop},
      Space{9, 10, 9, -1, false, SpaceType::NOOP, Actions::noop},
      Space{10, 11, 10, -1, false, SpaceType::NOOP, Actions::noop},
      Space{11, 12, 11, -1, false, SpaceType::NOOP, Actions::noop},
      Space{12, 13, 12, -1, false, SpaceType::MOVE_CARD, Actions::noop},
      Space{13, 14, 13, -1, false, SpaceType::NOOP, Actions::noop},
      Space{14, 15, 14, 24, false, SpaceType::SPY_ALLEY_ENTRANCE,
            Actions::check_enter_spy_alley},
      Space{15, 16, 15, -1, false, SpaceType::NOOP, Actions::noop},
      Space{16, 17, 16, -1, false, SpaceType::NOOP, Actions::noop},
      Space{17, 18, 17, -1, false, SpaceType::NOOP, Actions::noop},
      Space{18, 19, 18, -1, false, SpaceType::NOOP, Actions::noop},
      Space{19, 20, 19, -1, false, SpaceType::MOVE_CARD, Actions::noop},
      Space{20, 21, 20, -1, false, SpaceType::NOOP, Actions::noop},
      Space{21, 22, 21, -1, false, SpaceType::NOOP, Actions::noop},
      Space{22, 23, 22, -1, false, SpaceType::MOVE_CARD, Actions::noop},
      Space{23, 0, 23, 0, false, SpaceType::NOOP, Actions::noop},
      // Begin Spy Alley Spaces
      Space{24, 25, 14, -1, true, SpaceType::NOOP, Actions::noop},
      Space{25, 26, 24, -1, true, SpaceType::SPY_ALLEY_GUESS, Actions::make_guesses},
      Space{26, 27, 25, -1, true, SpaceType::NOOP, Actions::noop},
      Space{27, 28, 26, -1, true, SpaceType::NOOP, Actions::noop},
      Space{28, 29, 27, -1, true, SpaceType::NOOP, Actions::noop},
      Space{29, 30, 28, -1, true, SpaceType::NOOP, Actions::noop},
      Space{30, 31, 29, -1, true, SpaceType::NOOP, Actions::noop},
      Space{31, 32, 30, -1, true, SpaceType::NOOP, Actions::noop},
      Space{32, 22, 31, -1, true, SpaceType::NOOP, Actions::noop}};

  return spaces;
}
} // namespace SpyAlley::Board
