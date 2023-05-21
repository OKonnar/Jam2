/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Menu.cpp
*/

#include "Menu.hpp"

Menu::Menu(shared_ptr<SFML> sfml)
{
    _sfml = sfml;
    _screenRunning = true;
    _p = 0;
    _backgroundTexture.loadFromFile("assets/background.png");
    _background.setTexture(_backgroundTexture);
    _background.setScale(sf::Vector2f(1.75, 1.75));
    _select = 0;
}

std::vector<std::string> Menu::getFiles(const std::string &path)
{
    std::vector<std::string> files;

    try {
        for (const auto& entry : fs::directory_iterator(path)) {
            if (fs::is_regular_file(entry))
                files.push_back(entry.path().string());
        }
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return files;
}

void Menu::getInfos(const std::vector<std::string> &files)
{
    std::vector<Info> infoVector;

    for (const auto& file : files)
    {
        std::ifstream inputFile(file);

        if (inputFile.is_open())
        {
            Info info;

            std::getline(inputFile, info.musicName);
            std::string bpmString, durationString;
            std::getline(inputFile, bpmString);
            std::getline(inputFile, durationString);

            // Conversion des données en entiers
            std::istringstream bpmStream(bpmString);
            bpmStream >> info.bpm;

            std::istringstream durationStream(durationString);
            durationStream >> info.duration;

            info.path = file;
            info.musicName.substr(0, info.musicName.find_last_of('.'));
            infoVector.push_back(info);

            inputFile.close();
        }
        else
        {
            std::cerr << "Failed to open file: " << file << std::endl;
        }
    }

    _infos = infoVector;
}

void Menu::updateDisplay(void)
{
    _sfml->clear();
    _sfml->draw(_background);
    for (auto it = _buttons.begin(); it != _buttons.end(); ++it) {
        Button but = *it;
        _sfml->draw(but.rect);
        _sfml->draw(but.song);
        _sfml->draw(but.bpm);
        _sfml->draw(but.duration);
    }
    _sfml->display();
}

void Menu::initNewButton(Menu::Info info)
{
    Button newButton;

    newButton.rect.setPosition(sf::Vector2f(75, 155 + 100 * _p));
    newButton.rect.setSize(sf::Vector2f(600, 50));
    newButton.rect.setFillColor(sf::Color(200, 200, 200, 255));
    newButton.rect.setOutlineThickness(5);
    newButton.rect.setOutlineColor(sf::Color(150, 150, 150, 255));

    newButton.font.loadFromFile("assets/font.ttf");

    newButton.song.setFont(newButton.font);
    newButton.song.setFillColor(sf::Color::Black);
    newButton.song.setString(info.musicName);
    newButton.song.setPosition(sf::Vector2f(80, 160 + 100 * _p));

    _p++;
    _buttons.push_back(newButton);
}

int Menu::vecLen(void)
{
    int i = 0;
    for (auto t = _infos.begin(); t != _infos.end(); ++t, i++);
    return i;
}

void Menu::unselectedRect(void)
{
    int i = 0;
    for (auto t = _buttons.begin(); i != _select + 1; t++, i++) {
        t->rect.setOutlineColor(sf::Color(150, 150, 150, 255));
        t->rect.setFillColor(sf::Color(200, 200, 200, 255));
    }
}

void Menu::selectedRect(void)
{
    int i = 0;
    for (auto t = _buttons.begin(); i != _select + 1; ++t, i++) {
        if (i == _select) {
            t->rect.setFillColor(sf::Color(150, 150, 150, 255));
            t->rect.setOutlineColor(sf::Color(200, 200, 200, 255));
        }
    }
}

void Menu::handleEvents(void)
{
    static int vl = vecLen();

    if (_sfml->isButtonPressed(sf::Keyboard::Down) && _release && _select < vl - 1) {
        unselectedRect();
        _select++;
        _release = false;
    }
    if (_sfml->isButtonPressed(sf::Keyboard::Up) && _release && _select > 0) {
        unselectedRect();
        _select--;
        _release = false;
    }
}

std::string Menu::givePath(void)
{
    int i = 0;
    for (auto t = _infos.begin(); i != _select + 1; ++t, i++) {
        if (i == _select)
            return t->path;
    }
}

void Menu::loop(void)
{
    int test = 0;
    getInfos(getFiles("songs/"));
    for (auto t = _infos.begin(); t != _infos.end(); ++t) {
        const Info &info = *t;
        initNewButton(*t);
    }
    while (_screenRunning && _sfml->windowIsOpen()) {
        if (_sfml->getClock().getElapsedTime().asSeconds() - _clock > 1 / 60 ) {
            _clock = _sfml->getClock().getElapsedTime().asSeconds();
            if (test >= 150) {
                test = 0;
                _release = true;
                selectedRect();
            }
            if (_sfml->isButtonPressed(sf::Keyboard::Enter)) break;
            handleEvents();
            test++;
            updateDisplay();
        }
    }
    Scene scene(givePath(), _sfml);
    scene.loop();
}
