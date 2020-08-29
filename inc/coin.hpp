#pragma once

#include <SFML/Graphics/CircleShape.hpp>

namespace game {

class Coin : public sf::CircleShape
{
public:
    // TODO: make use of point count?
    Coin(float radius, float border_perc = 10, sf::Color main_color = sf::Color(100,100,100));

private:
    const int m_border_shade = 2;
    const float m_border;
};

}