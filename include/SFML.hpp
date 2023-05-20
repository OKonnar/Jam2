/*
** EPITECH PROJECT, 2022
** Jam2
** File description:
** SFML.hpp
*/

#pragma once

#include <filesystem>
#include <memory>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace std;

class SFML
{
    public :
        struct Sounds {
            sf::SoundBuffer buffer;
            sf::Sound sound;
        };

    private:
        struct Vector2u {
            unsigned int x, y;
        };

        Vector2u            _windowSize;
        sf::Event           _event;
        sf::RenderWindow    _window;
        sf::Clock           _clock;
        std::map<std::string, std::shared_ptr<Sounds>> _sounds;

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

        //! Sounds
        void playSoundFromFile(string filepath);
        std::map<std::string, std::shared_ptr<Sounds>> getSounds() {return _sounds;};
        void playSound(string name);
        void loadSounds();
};
