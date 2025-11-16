#include <any>
#include <iostream>
//defines future functions to eliminate need for putting functions in any specific order
int render();
int renderinitial();
int positioncheck();
int repeated();
int win();
int boardclear();
//defines variables (arrays and not) for program to use
std::string res[10] = {"E", "E", "E", "E", "E", "E", "E", "E", "E", "E"};
int position;
int usedpositions[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int playerselect = 2;
int boardcleartally = 0;
int boardclearchecktally = 0;
std::string letter[2] = {"X", "O"};
std::string winner;
std::string response;

int main()
{
    std::cout << "This is Tic-Tac-Go!" << std::endl << "Press Enter to begin!" << std::endl;
    std::cin.get();
    render();
    repeated();
}

int render()
{
    std::cout << res[1] << res[2] << res[3] << std::endl;
    std::cout << res[4] << res[5] << res[6] << std::endl;
    std::cout << res[7] << res[8] << res[9] << std::endl;

  /*  std::cout << usedpositions[0] << std::endl;
    std::cout << usedpositions[1] << std::endl;
    std::cout << usedpositions[2] << std::endl;
    std::cout << usedpositions[3] << std::endl;
    std::cout << usedpositions[4] << std::endl;
    std::cout << usedpositions[5] << std::endl;
    std::cout << usedpositions[6] << std::endl;
    std::cout << usedpositions[7] << std::endl;
    std::cout << usedpositions[8] << std::endl;
    std::cout << usedpositions[9] << std::endl;*/
    return 67;
}

int wincheck()
{
    if (res[1] == "X" && res[2] == "X" && res[3] == "X")
    {
        winner = "Player 1";
        win();
    }
    else if (res[4] == "X" && res[5] == "X" && res[6] == "X")
    {
        winner = "Player 1";
        win();
    }
    else if (res[7] == "X" && res[8] == "X" && res[9] == "X")
    {
        winner = "Player 1";
        win();
    }
    else if (res[1] == "X" && res[5] == "X" && res[9] == "X")
    {
        winner = "Player 1";
        win();
    }
    else if (res[3] == "X" && res[5] == "X" && res[7] == "X")
    {
        winner = "Player 1";
        win();
    }
    else if (res[2] == "X" && res[5] == "X" && res[8] == "X")
    {
        winner = "Player 1";
        win();
    }
    else if (res[1] == "X" && res[4] == "X" && res[7] == "X")
    {
        winner = "Player 1";
        win();
    }
    else if (res[3] == "X" && res[6] == "X" && res[9] == "X")
    {
        winner = "Player 1";
        win();
    }
    else if (res[1] == "O" && res[2] == "O" && res[3] == "O")
    {
        winner = "Player 2";
        win();
    }
    else if (res[4] == "O" && res[5] == "O" && res[6] == "O")
    {
        winner = "Player 2";
        win();
    }
    else if (res[7] == "O" && res[8] == "O" && res[9] == "O")
    {
        winner = "Player 2";
        win();
    }
    else if (res[1] == "O" && res[5] == "O" && res[9] == "O")
    {
        winner = "Player 2";
        win();
    }
    else if (res[3] == "O" && res[5] == "O" && res[7] == "O")
    {
        winner = "Player 2";
        win();
    }
    else if (res[2] == "O" && res[5] == "O" && res[8] == "O")
    {
        winner = "Player 2";
        win();
    }
    else if (res[1] == "O" && res[4] == "O" && res[7] == "O")
    {
        winner = "Player 2";
        win();

    }
    else if (res[3] == "O" && res[6] == "O" && res[9] == "O")
    {
        winner = "Player 2";
        win();
    }
    else
    {
        for (int i = 0; i < 9; i++)
        {
            if (res[i] == "X" || res[i] == "O")
            {
                boardclearchecktally++;
            }
        }
        if (boardclearchecktally > 9)
        {
            boardclear();
            boardclearchecktally = 0;
            return 0;
        }
        boardclearchecktally = 0;
        return 0;
    }
}

int positioncheck()
{
    if (position > 9)
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Try again!" << std::endl;
        position = -1;
        std::cin >> position;
        positioncheck();
    }
    else if (position != usedpositions[position])
    {
        usedpositions[position] = position;
        res[position] = letter[playerselect-1];
        position = -1;
    }
    else if (std::cin.fail())
    {
    std::cin.clear();
    std::cin.ignore();
    std::cout << "Try again!" << std::endl;
    position = -1;
    std::cin >> position;
    positioncheck();
    }
    else
    {
        std::cout << "Pick another space!" << std::endl;
        position = -1;
        std::cin >> position;
        positioncheck();
    }
    return 67;
}

int repeated()
{
    if (playerselect == 1)
    {
        playerselect = 2;
    }
    else if (playerselect == 2)
    {
        playerselect = 1;
    }

    if (playerselect == 1)
    {
        std::cout << "Select an available space, Player 1!" << std::endl;
        std::cin >> position;
        positioncheck();
        wincheck();
        render();
        repeated();
    }
    else if (playerselect == 2)
    {
        std::cout << "Select an available space, Player 2!" << std::endl;
        std::cin >> position;
        positioncheck();
        wincheck();
        render();
        repeated();
    }
}

int boardclear()
{
    for (int i = 1; i < 10; i++)
    {
        res[i] = "E";
        usedpositions[i] = 0;
    }
    boardcleartally++;
    return 0;
}

int win()
{
    render();
    std::cout << "Congratulations, " << winner << ", you win!" << std::endl;
    std::cout << "The board was cleared " << boardcleartally << " times!" << std::endl;
    std::cout << "Want to play again? (y or n)" << std::endl;
    std::cin >> response;
    if (response == "y" || response == "yes")
    {
        boardclear();
        playerselect = 2;
        boardcleartally = 0;
        main();
    }
    else if (response == "n" || response == "no")
    {
        return 0;
    }
}