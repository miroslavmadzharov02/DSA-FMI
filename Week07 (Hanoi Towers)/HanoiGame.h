#ifndef HANOIGAME__
#define HANOIGAME__

#include <stack>
#include <iostream>

class HanoiGame
{
private:
	struct Game
	{
		std::stack<int> poles[3];
	};

	Game state_;

	void printBoard();
	void move(const char& source, const char& auxiliary, const char& destination, const size_t& currentAmount);
	void performMove(const char& source, const char& destination);
public:
	HanoiGame(size_t maxAmount);

	void play();
};

#endif 