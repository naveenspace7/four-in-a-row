#include "../inc/game.hpp"
#include <iostream>

void game::Game::set_valid_keys()
{
    m_valid_keys.insert(sf::Keyboard::Key::Num1);
    m_valid_keys.insert(sf::Keyboard::Key::Num2);
    m_valid_keys.insert(sf::Keyboard::Key::Num3);
    m_valid_keys.insert(sf::Keyboard::Key::Num4);
    m_valid_keys.insert(sf::Keyboard::Key::Num5);
    m_valid_keys.insert(sf::Keyboard::Key::Num6);
    m_valid_keys.insert(sf::Keyboard::Key::Num7);

    m_valid_keys.insert(sf::Keyboard::Key::Escape);
}

bool game::Game::is_valid_key(sf::Keyboard::Key key_pressed)
{
    if (m_valid_keys.find(key_pressed) != m_valid_keys.end())
        return true;
    return false;
}

void game::Game::single_drop_sound()
{
    if (sound_buff.loadFromFile("drop.wav")) {
        sound_handle.setBuffer(sound_buff);
        sound_handle.play();
    }
}

game::Game::Game(const std::string& game): 
                sf::RenderWindow(sf::VideoMode(GAME_FRAME_WIDTH, GAME_FRAME_HEIGHT), game, sf::Style::Default, sf::ContextSettings(0, 0, 24, 1, 1, 0, false)), board(this->getSize())
{
    this->setFramerateLimit(GAME_FRAME_RATE);

    // create place holder for the moves

    moves.resize(game::Board::dim.second);

    for (size_t i = 0; i < game::Board::dim.second; ++i)
        moves[i].reserve(game::Board::dim.first);

    set_valid_keys();
}

void game::Game::draw_components()
{
    // draw board
    this->draw(board);

    // TODO: if hole or coin needs to be drawn

    // draw holes
    for(int i = 0; i < game::Board::dim.first; ++i) {
        for(int j = 0; j < game::Board::dim.second; ++j) {
            this->draw(*board.holes[j][i]);
        }
    }

    // draw player coins
    for (std::vector<game::Coin*> cols: moves)
    {
        for (game::Coin* col: cols)
            this->draw(*col);
    }
}

// Handle player's move
bool game::Game::process_move(int new_x)
{
    single_drop_sound();

    static bool p1_move = false;
    const int COLUMN_WID = 115;
    int column = new_x;
    if(!((column >= 0) && (column < 7))) return false;
    int TOTAL = 110 * 6;
    int Point = TOTAL - 110*(moves[column].size() + 1);

    game::Coin * new_coin = nullptr;

    if (p1_move) new_coin = new game::P1_Coin();

    else new_coin = new game::P2_Coin();

    new_coin->setPosition(column*110 + 10, Point + 10);
    moves[column].push_back(new_coin);

    // BEGIN game logic

    int count = 0; // count the new coin as 1
    int i = column, j = moves[column].size() - 1;

    // row check
    while((++i < 7) && (j < moves[i].size()) && (typeid(*moves[i][j]) == typeid(*new_coin)));
    while((--i >= 0) && (j < moves[i].size()) && (typeid(*moves[i][j]) == typeid(*new_coin))) count++;
    if(count == 4) { print_winner(new_coin); return true; }

    // column check
    i = column;
    count = 1;
    while((--j >= 0) && (typeid(*moves[i][j]) == typeid(*new_coin))) count++;
    if(count == 4) { print_winner(new_coin); return true; }

    // diagonal check +45
    count = 0;
    i = column;
    j = moves[column].size() - 1;
    while(((++i < 7) && (++j < moves[i].size())) && (typeid(*moves[i][j]) == typeid(*new_coin)));
    while(((--i >= 0) && (--j >= 0) && (j < moves[i].size())) && (typeid(*moves[i][j]) == typeid(*new_coin))) count++;
    if(count == 4) { print_winner(new_coin); return true; }

    // diagonal check -45
    count = 0;
    i = column;
    j = moves[column].size() - 1;
    while(((++i < 7) && (--j >= 0) && (j < moves[i].size())) && (typeid(*moves[i][j]) == typeid(*new_coin)));
    while(((--i >= 0) && (++j < moves[i].size())) && (typeid(*moves[i][j]) == typeid(*new_coin))) count++;
    if(count == 4) { print_winner(new_coin); return true; }

    // END game logic

    if (p1_move) p1_move = false;
    else p1_move = true;

    return false;
}

void game::Game::print_moves()
{
    for (std::vector<game::Coin*> v: moves)
    {
        for (game::Coin* c: v)
        {
            // Use the below method to decide to 
            // which player a coins belongs to
            if (typeid(*c) == typeid(game::P1_Coin))
                std::cout << "p1" << std::endl;
            else
                std::cout << "p2" << std::endl;
        }
    }
}

void game::Game::print_winner(Coin* last_coin)
{
    std::cout << "game is done" << std::endl;
    if (typeid(*last_coin) == typeid(game::P1_Coin))
        std::cout << "p1 wins !" << std::endl;
    else
        std::cout << "p2 wins !" << std::endl;
}
