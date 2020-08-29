#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <string>

namespace game {

const sf::Color GREEN_COLOR = sf::Color(50, 200, 50);
const sf::Color RED_COLOR = sf::Color(250, 26, 26);

class Coin : public sf::CircleShape
{
private:
    static constexpr float COIN_RADIUS = 50.f;
    static const int m_border_shade  =  2;
    static constexpr float m_border_perc = 10;

public:
    Coin(sf::Color main_color = sf::Color(100,100,100));
};



class P1_Coin : public Coin
{
private:
    static std::string m_player_name;
public:
    P1_Coin(sf::Color color = RED_COLOR);
    P1_Coin(std::string p_name);
};



class P2_Coin : public Coin
{
private:
    static std::string m_player_name;
public:
    P2_Coin(sf::Color color = GREEN_COLOR);
    P2_Coin(std::string p_name);
};

}