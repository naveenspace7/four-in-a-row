#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include <array>
#include <utility>


namespace game
{

using Dimension = std::pair<int,int>;

class Board: public sf::RectangleShape
{
private:
    const size_t GAP = 10;
    const sf::Color BACKGROUND = sf::Color(0, 0, 255);

public:
    static constexpr Dimension dim {6,7};
    std::array<std::array<sf::CircleShape*, dim.first>, dim.second> holes;
    Board(const sf::Vector2u win_size);

    void construct_holes();
};


}