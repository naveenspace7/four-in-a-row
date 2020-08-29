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

    for (size_t i = 0; i < cols; ++i) {

        start_y = GAP;

        for (size_t j = 0; j < rows; ++j) {

            holes[i][j] = new sf::CircleShape(hole);
            // holes[i][j] = new sf::CircleShape(10.f);

            holes[i][j]->setPosition(start_x, start_y);
            // holes[i][j]->setFillColor(sf::Color::Blue);
            
            start_y += (game::Coin::COIN_RADIUS * 2 + GAP);
        }

        start_x += (game::Coin::COIN_RADIUS * 2 + GAP);
    }
}