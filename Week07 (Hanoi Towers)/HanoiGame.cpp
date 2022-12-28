#include "HanoiGame.h"

template<typename T>
void printStack(std::stack<T> stack)
{
	if (stack.empty())
		return;

	T top = stack.top();
	stack.pop();

	printStack(stack);
	std::cout << "-" << top;
}

void HanoiGame::printBoard()
{
	for (std::stack<int> pole : state_.poles)
	{
		std::cout << "|";
		printStack(pole);
		std::cout << '\n';
	}
}

void HanoiGame::move(const char& source, const char& auxiliary, const char& destination, const size_t& currentAmount)
{
	if (currentAmount == 0)
		return;

	move(source, destination, auxiliary, currentAmount - 1);
	std::cout << "Moving disk from " << source << " to " << destination << '\n';
	performMove(source, destination);
	printBoard();
	std::cin.get();
	move(auxiliary, source, destination, currentAmount - 1);
}

void HanoiGame::performMove(const char& source, const char& destination)
{
	int sourceIndex = source - 'A';
	int destinationIndex = destination - 'A';
	state_.poles[destinationIndex].push(state_.poles[sourceIndex].top());
	state_.poles[sourceIndex].pop();
}

HanoiGame::HanoiGame(size_t maxAmount)
{
	while (maxAmount > 0)
	{
		state_.poles[0].push(maxAmount--);
	}
}

void HanoiGame::play()
{
	std::cout << "Current state of the board is:\n";
	printBoard();
	std::cin.get();
	move('A', 'B', 'C', state_.poles[0].size());
}
