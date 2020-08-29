#include "../inc/coin.hpp"

game::Coin::Coin(sf::Color main_color):
    CircleShape(COIN_RADIUS)
{
    this->setFillColor(main_color);

    sf::Color& border_color(main_color);
    main_color.r /= m_border_shade;
    main_color.g /= m_border_shade;
    main_color.b /= m_border_shade;

    constexpr float border_thickness = m_border_perc * COIN_RADIUS/100.f;
    constexpr float shape_radius = COIN_RADIUS - border_thickness;

    this->setOutlineThickness(border_thickness);
    this->setOutlineColor(border_color);
}

std::string game::P1_Coin::m_player_name {"Player1"};
std::string game::P2_Coin::m_player_name {"Player2"};

game::P1_Coin::P1_Coin(sf::Color color): Coin(color)
{
}

game::P1_Coin::P1_Coin(std::string p_name): P1_Coin()
{
    m_player_name = p_name;
}

game::P2_Coin::P2_Coin(sf::Color color): Coin(color)
{
}

game::P2_Coin::P2_Coin(std::string p_name): P2_Coin()
{
    m_player_name = p_name;
}