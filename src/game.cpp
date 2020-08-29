#include "../inc/game.hpp"
#include <iostream>

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
    // draw board
    this->draw(board);

    // draw holes
    for(int i = 0; i < game::Board::dim.first; ++i) {
        for(int j = 0; j < game::Board::dim.second; ++j) {
            this->draw(*board.holes[j][i]);
        }
    }
}

void game::Game::process_move(int new_x)
{
    static bool p1_move = false;

    //TODO: replace 115 with const
    int column = new_x/115;
    // std::cout << column << std::endl;

    if (p1_move)
    {
        // std::cout << "p1_add" << std::endl;
        moves[column].push_back(new game::P1_Coin());
    }

    else
    {
        // std::cout << "p2_add" << std::endl;
        moves[column].push_back(new game::P2_Coin());
    }

    if (p1_move) p1_move = false;
    else p1_move = true;

    // p1_move = ~p1_move;
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