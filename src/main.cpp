#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../inc/game.hpp"
#include "../inc/board.hpp"
#include "../inc/coin.hpp"
#include <iostream>

int main()
{
    sf::SoundBuffer buffer;
    sf::Sound sound;

    game::Game window("Four In A Row");

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                // sf::Vector2i click_pos = sf::Mouse::getPosition(window);
                window.process_move( sf::Mouse::getPosition(window).x);
            }
        }

        window.clear();
        window.draw_components();
        window.display();
    }

    return 0;
}