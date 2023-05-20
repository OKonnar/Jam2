/*
** EPITECH PROJECT, 2022
** Jam2
** File description:
** SFML.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace std;

class SFML
{
    private:
        struct Vector2u {
            unsigned int x, y;
        };

        Vector2u            _windowSize;
        sf::Event           _event;
        sf::RenderWindow    _window;
        sf::Clock           _clock;

    public:
        SFML(void);
        ~SFML(void);

        void loop();

        sf::Sprite create(std::string filename, sf::Vector2f size, sf::Vector2f position);
        sf::RectangleShape create(sf::Vector2f size, sf::Vector2f position, sf::Color color);

        void updateSprite(sf::Sprite);
        void updateSprite(sf::Sprite, sf::Vector2f newPos);
        void updateSprite(sf::RectangleShape);
        void updateSprite(sf::RectangleShape, sf::Vector2f newPos);

        void display(std::vector<sf::RectangleShape> rects, std::vector<sf::Sprite> sprites);
        void events();
        void playSound(string filepath);
};
