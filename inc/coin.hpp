#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <string>

namespace game {

// Adjust the coin radius here
const float COIN_RADIUS = 50.f;
const sf::Color GREEN_COLOR = sf::Color(50, 200, 50);



class Coin : public sf::CircleShape
{
private:
    const int m_border_shade = 2;
    const float m_border;
public:
    // TODO: make use of point count?
    Coin(sf::Color main_color = sf::Color(100,100,100), float radius = COIN_RADIUS, float border_perc = 10);
};



class P1_Coin : public Coin
{
private:
    static std::string m_player_name;
public:
    P1_Coin(sf::Color color = GREEN_COLOR);
    P1_Coin(std::string p_name);
};

}