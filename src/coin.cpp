#include "../inc/coin.hpp"

game::Coin::Coin(float radius, float border_perc, sf::Color main_color):
    CircleShape(radius), m_border(border_perc * radius/100.f)
{
    this->setFillColor(main_color);

    sf::Color border_color = sf::Color(main_color.r/m_border_shade,
                                        main_color.g/m_border_shade,
                                        main_color.b/m_border_shade);

    this->setOutlineThickness(m_border);
    this->setOutlineColor(border_color);
}