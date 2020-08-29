#include "../inc/board.hpp"
#include "../inc/coin.hpp"

game::Board::Board(const sf::Vector2u win_size): sf::RectangleShape(sf::Vector2f(win_size.x, win_size.y))
{
    this->setFillColor(BACKGROUND);
    construct_holes();
}

sf::CircleShape get_hole()
{
    sf::CircleShape hole(game::Coin::COIN_RADIUS);
    hole.setFillColor(sf::Color::White);
    return hole;
}

void game::Board::construct_holes()
{
    sf::CircleShape hole = get_hole();

    size_t start_x = GAP, start_y = GAP;

    const size_t rows = dim.first, cols = dim.second;

    for (size_t col = 0; col < cols; ++col) {

        start_y = GAP;

        for (size_t row = 0; row < rows; ++row) {

            holes[col][row] = new sf::CircleShape(hole);
            holes[col][row]->setPosition(start_x, start_y);
            start_y += (game::Coin::COIN_RADIUS * 2 + GAP);
        }

        start_x += (game::Coin::COIN_RADIUS * 2 + GAP);
    }
}