all:
	clang++ -g board.cpp make_board.cpp player.cpp main.cpp -std=c++17 -o SpyAlley
release:
	clang++ -O3 board.cpp make_board.cpp player.cpp main.cpp -std=c++17 -o SpyAlley
