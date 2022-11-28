#include "HanoiGame.h"

int main()
{
    size_t disksAmount;
    std::cout << "Enter the amount of disks the game will have:\n";
    std::cin >> disksAmount;
    std::cin.ignore();

    HanoiGame game(disksAmount);

    game.play();

    return 0;
}
