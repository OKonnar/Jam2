/*
** EPITECH PROJECT, 2022
** Jam2
** File description:
** SFML.cpp
*/

#include "SFML.hpp"

using namespace std;

SFML::SFML(void)
{
    _windowSize.x = 1920;
    _windowSize.y = 1080;
    _window.create(sf::VideoMode(_windowSize.x, _windowSize.y, 32), "Jam");
    //loadSounds();
}

SFML::~SFML(void)
{}

bool SFML::windowIsOpen()
{
    return (_window.isOpen());
}

void SFML::events()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            _window.close();
    }
}

bool SFML::isButtonPressed(sf::Keyboard::Key c)
{
    return sf::Keyboard::isKeyPressed(c);
}

void SFML::draw(sf::Sprite sprite)
{
    _window.draw(sprite);
}

void SFML::draw(sf::Text text)
{
    _window.draw(text);
}

sf::Sprite SFML::create(string filename, sf::Vector2f size, sf::Vector2f position)
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

void SFML::clear()
{
    _window.clear(sf::Color(127, 127, 127, 255));
}

void SFML::display()
{
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

void SFML::loadSounds()
{
    const char *path = "./assets/sounds/";
    DIR *dir = opendir(path);
    if (dir == nullptr) {
        cerr << "Failed to open directory\n";
        return;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != nullptr) {
        if (strstr(entry->d_name, ".wav") != nullptr) {
            auto sound = make_shared<Sounds>();
            string filepath = string(path) + entry->d_name;
            if (!sound->buffer.loadFromFile(filepath)) {
                cerr << "Failed to load sound file: " << filepath << "\n";
                continue;
            }
            sound->sound.setBuffer(sound->buffer);
            string filename = entry->d_name;
            filename = filename.substr(0, filename.size() - 4);
            _sounds[filename] = sound;
        }
    }
    closedir(dir);
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
        sf::sleep(sf::seconds(0.05f));
    }
}

void SFML::loadMusic(const string& filename)
{
    const string path = "assets/musics/";
    shared_ptr<sf::Music> music = make_shared<sf::Music>();
    if (!music->openFromFile(path + filename)) {
        std::cout << path + filename << endl;
        throw runtime_error("Failed to load music file: " + filename);
    }
    string name = filename.substr(0, filename.size() - 4);
    _musics[name] = music;
}

void SFML::playMusic(const std::string& name)
{
    auto it = _musics.find(name);
    if (it != _musics.end()) {
        it->second->play();
    }
    else {
        throw std::runtime_error("Music not found: " + name);
    }
}

void SFML::startClock()
{
    _clock.restart();
}

sf::Clock SFML::getClock(void)
{
    return _clock;
}
