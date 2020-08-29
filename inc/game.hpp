#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "board.hpp"
#include "coin.hpp"

namespace game
{

class Game: public sf::RenderWindow
{
private:
    static const int GAME_FRAME_WIDTH = 1200, GAME_FRAME_HEIGHT = 700;
    Board board;

    std::vector<std::vector<Coin*>> moves;

public:
    Game(const std::string& game = "Game");

    void draw_components();

    void process_move(int new_x);

    void print_moves();
};

}