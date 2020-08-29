#include "../inc/game.hpp"
#include <iostream>

// game::Game::single_drop_sound()
// {
    

// }

game::Game::Game(const std::string& game): 
                sf::RenderWindow(sf::VideoMode(GAME_FRAME_WIDTH, GAME_FRAME_HEIGHT), game), board(this->getSize())
{
    moves.resize(game::Board::dim.second);

    for (size_t i = 0; i < game::Board::dim.second; ++i)
    {
        moves[i].reserve(game::Board::dim.first);
    }
}

void game::Game::draw_components()
{
    // make sound


    // draw board
    this->draw(board);

    // draw holes
    for(int i = 0; i < game::Board::dim.first; ++i) {
        for(int j = 0; j < game::Board::dim.second; ++j) {
            this->draw(*board.holes[j][i]);
        }
    }

    for (std::vector<game::Coin*> cols: moves)
    {
        for (game::Coin* col: cols)
            this->draw(*col);
    }
}

void game::Game::process_move(int new_x)
{
    static bool p1_move = false;

    const int COLUMN_WID = 115;

    int column = new_x/COLUMN_WID;

    int TOTAL = 110 * 6;

    int Point = TOTAL - 110*(moves[column].size() + 1);

    game::Coin * new_coin = nullptr;

    if (p1_move) new_coin = new game::P1_Coin();

    else new_coin = new game::P2_Coin();

    new_coin->setPosition(column*110 + 10, Point + 10);
    moves[column].push_back(new_coin);

    if (p1_move) p1_move = false;
    else p1_move = true;
}

void game::Game::print_moves()
{
    for (std::vector<game::Coin*> v: moves)
    {
        for (game::Coin* c: v)
        {
            if (typeid(*c) == typeid(game::P1_Coin))
                std::cout << "p1" << std::endl;
            else
                std::cout << "p2" << std::endl;
        }
    }
}