#include "../inc/coin.hpp"

game::Coin::Coin(sf::Color main_color, float radius, float border_perc):
    CircleShape(radius), m_border(border_perc * radius/100.f)
{
    this->setFillColor(main_color);

    sf::Color border_color = sf::Color(main_color.r/m_border_shade,
                                        main_color.g/m_border_shade,
                                        main_color.b/m_border_shade);

    this->setOutlineThickness(m_border);
    this->setOutlineColor(border_color);
}

std::string game::P1_Coin::m_player_name {"Player1"};

game::P1_Coin::P1_Coin(sf::Color color): Coin(color)
{
}

game::P1_Coin::P1_Coin(std::string p_name): P1_Coin()
{
    m_player_name = p_name;
}