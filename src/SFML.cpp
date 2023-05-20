/*
** EPITECH PROJECT, 2022
** Jam2
** File description:
** SFML.cpp
*/

#include "SFML.hpp"

using namespace std;

SFML::SFML(void)    {
    _windowSize.x = 1920;
    _windowSize.y = 1080;
    _window.create(sf::VideoMode(_windowSize.x, _windowSize.y, 32), "Jam");
}

SFML::~SFML(void)   {}

void SFML::loop(void)
{
    // create();
    while (_window.isOpen()) {
        events();
        // update();
        // display();
    }
}

void SFML::events(void)
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            _window.close();
    }
}

sf::Sprite SFML::create(std::string filename, sf::Vector2f size, sf::Vector2f position)
{
    sf::Sprite sprite;
    sf::Texture texture;

    texture.loadFromFile(filename);
    sprite.setTexture(texture, true);
    sprite.setScale(size);
    sprite.setPosition(position);

    return sprite;
}

sf::RectangleShape SFML::create(sf::Vector2f size, sf::Vector2f position, sf::Color color)
{
    sf::RectangleShape rect;

    rect.setSize(size);
    rect.setPosition(position);
    rect.setFillColor(color);

    return rect;
}

void SFML::updateSprite(sf::Sprite sprite)
{
    _window.draw(sprite);
}

void SFML::updateSprite(sf::Sprite sprite, sf::Vector2f newPos)
{
    sprite.setPosition(newPos);
    _window.draw(sprite);
}

void SFML::updateSprite(sf::RectangleShape rect)
{
    _window.draw(rect);
}

void SFML::updateSprite(sf::RectangleShape rect, sf::Vector2f newPos)
{
    rect.setPosition(newPos);
    _window.draw(rect);
}

void SFML::display(std::vector<sf::RectangleShape> rects, std::vector<sf::Sprite> sprites)
{
    _window.clear(sf::Color::White);
    for (std::vector<sf::RectangleShape>::iterator it = rects.begin(); it != rects.end(); it++)
        updateSprite(*it);
    for (std::vector<sf::Sprite>::iterator it = sprites.begin(); it != sprites.end(); it++)
        updateSprite(*it);
    _window.display();
}

void SFML::playSound(string filepath)
{
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(filepath)) {
        throw std::runtime_error("wrong file path");
    }
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    while (sound.getStatus() == sf::Sound::Playing) {
        sf::sleep(sf::seconds(0.1f));
    }
}