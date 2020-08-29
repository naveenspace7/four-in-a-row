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

    game::Board b(window.getSize());

    game::P1_Coin p1;
    p1.setPosition(200, 100);
    game::P2_Coin p2;
    p2.setPosition(50, 50);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i click_pos = sf::Mouse::getPosition(window);
                // std::cout << click_pos.x << ", " << click_pos.y << std::endl;

                
                if (!buffer.loadFromFile("drops.wav")) {
                    std::cout << "failed to play music" << std::endl;
                    return -1;
                }

                sound.setBuffer(buffer);
                sound.play();

                window.process_move(click_pos.x);

                window.print_moves();
            }
        }


        window.clear();

        window.draw_components();
        // window.draw(b);
        // for(int i = 0; i < game::Board::dim.first; ++i) {
        //     for(int j = 0; j < game::Board::dim.second; ++j) {
        //         window.draw(*b.holes[j][i]);
        //     }
        // }

        // window.draw(p1);
        // window.draw(p2);
        // window.draw(shape);
        window.display();
    }

    return 0;
}