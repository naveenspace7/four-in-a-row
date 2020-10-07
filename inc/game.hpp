#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "board.hpp"
#include "coin.hpp"
#include <unordered_set>

namespace game
{

class Game: public sf::RenderWindow
{
private:
    static const int GAME_FRAME_WIDTH = 800, GAME_FRAME_HEIGHT = 700;
    Board board;

    std::vector<std::vector<Coin*>> moves;

    sf::Sound sound_handle;
    sf::SoundBuffer sound_buff;

    std::unordered_set<sf::Keyboard::Key> m_valid_keys;

    const int GAME_FRAME_RATE = 10; // FPS

public:
    Game(const std::string& game = "Game");

    void draw_components();

    bool process_move(int new_x);

    void print_moves();

    void print_winner(Coin* last_coin);

    void single_drop_sound();

    bool is_valid_key(sf::Keyboard::Key);

    void set_valid_keys();
};

}
