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

            if(event.type == sf::Event::KeyPressed)
            {
              if (window.is_valid_key(event.key.code))
              {
                if (event.key.code == sf::Keyboard::Escape)
                  window.close();
                
                else if(window.process_move(event.key.code - sf::Keyboard::Num1))
                {
                  std::cout << "game ends here, do whatever" << std::endl;
                }
              }
            }
        }

        window.clear();
        window.draw_components();
        window.display();
    }

    return 0;
}
