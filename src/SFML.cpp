/*
** EPITECH PROJECT, 2022
** Jam2
** File description:
** SFML.cpp
*/

#include "SFML.hpp"

using namespace std;

SFML::SFML(void)    {_window.create(sf::VideoMode {1280, 720, 32}, "Jam");}
SFML::~SFML(void)   {}

void SFML::loop(void)
{
    create();
    while (_window.isOpen()) {
        events();
        update();
        display();
    }
}

void SFML::events(void)
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            _window.close();
    }
}

void SFML::create(void)
{
    // creation des sprites
}

void SFML::update(void)
{
     // update des sprites
}

void SFML::display(void)
{
    // display des sprites
    _window.display();
}

void SFML::playSoundFromFile(string filepath)
{
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(filepath)) {
        throw runtime_error("wrong file path");
    }
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    while (sound.getStatus() == sf::Sound::Playing) {
        sf::sleep(sf::seconds(0.1f));
    }
}

void SFML::loadSounds() {
    const string path = "assets/sounds/";

    for (const auto & entry : filesystem::directory_iterator(path)) {
        if (entry.path().extension() == ".wav") {
            auto sound = make_shared<Sounds>();

            // Load the sound buffer from the file
            if (!sound->buffer.loadFromFile(entry.path())) {
                // Handle the error if needed
                continue;
            }

            // Attach the sound buffer to the sound instance
            sound->sound.setBuffer(sound->buffer);

            // Get the filename without the extension
            string filename = entry.path().stem().string();

            // Add the filename and the sound to the map of sounds
            _sounds[filename] = sound;
        }
    }
}

void SFML::playSound(string name)
{
    auto it = _sounds.find(name);
    if (it == _sounds.end()) {
        throw runtime_error("sound not found");
    }
    if (it->second->sound.getBuffer() == nullptr) {
        throw runtime_error("missing buffer for the sound");
    }
    it->second->sound.play();
    while (it->second->sound.getStatus() == sf::Sound::Playing) {
        sf::sleep(sf::seconds(0.1f));
    }
}