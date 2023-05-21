/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** Scene
*/

#include "Scene.hpp"

using namespace std;

Scene::Scene(string configFile, shared_ptr<SFML> sfml)
{
    font.loadFromFile("./assets/font.ttf");
    _sfml = sfml;
    _parsing.parseFile(configFile);
    _lanesX = {800, 910, 1020};
    _linesCpt = 0;
    _sceneRunning = true;
    _scoreWhite = 0;
    _scoreBlack = 0;
    _clock = 0;
    sw.setFont(font);
    sb.setFont(font);
    sw.setColor(sf::Color(sf::Color::Black));
    sb.setColor(sf::Color(sf::Color::White));
    sw.setString("0");
    sb.setString("0");
    sw.setPosition(sf::Vector2f(50, 50));
    sb.setPosition(sf::Vector2f(1870, 50));
    backgroundTexture.loadFromFile("./assets/background.png");
    background.setTexture(backgroundTexture);
    background.setScale(sf::Vector2f(1.75, 1.75));
    _sfml->loadMusic(_parsing.getFileName());
}

Scene::~Scene() {}

bool Scene::isNewLine()
{
    for (std::vector<sf::RectangleShape>::iterator it = _rectangles.begin(); it != _rectangles.end(); it++) {
        if (it->getPosition().y <= 0)
            return false;
    }
    return true;
}

void Scene::updateFromFile()
{
    if (!isNewLine())
        return;
    if (_linesCpt == _parsing.getLinesNbr() - 1)
        _sceneRunning = false;
    std::vector<int> tiles = _parsing.getLine(_linesCpt);
    for (std::size_t i = 0; i < tiles.size(); i++) {
        if (tiles[i] == 0)
            _rectangles.push_back(_sfml->create(sf::Vector2f(TILESIZEX, TILESIZEY), sf::Vector2f(_lanesX[i], -TILESIZEY), sf::Color::Black));
        if (tiles[i] == 1)
            _rectangles.push_back(_sfml->create(sf::Vector2f(TILESIZEX, TILESIZEY), sf::Vector2f(_lanesX[i], -TILESIZEY), sf::Color::White));
    }
    _linesCpt++;

    for (std::vector<sf::RectangleShape>::iterator it = _rectangles.begin(); it != _rectangles.end(); it++) {
        if (it->getPosition().y > 1080)
            _rectangles.erase(it);
    }
}

void Scene::updateDisplay()
{
    _sfml->clear();
    _sfml->draw(background);
    for (vector<sf::Sprite>::iterator it = _sprites.begin(); it != _sprites.end(); it++)
        _sfml->updateSprite(*it);
    for (vector<sf::RectangleShape>::iterator it = _rectangles.begin(); it != _rectangles.end(); it++) {
        it->setPosition(sf::Vector2f(it->getPosition().x, it->getPosition().y + static_cast<float>(TILESIZEX * _parsing.getBPM()) / 10000));
        _sfml->updateSprite(*it);
    }
    _sfml->updateSprite(_sfml->create(sf::Vector2f(1920, 5), sf::Vector2f(0, 980), sf::Color::Red));
    sw.setString(to_string(_scoreWhite));
    sb.setString(to_string(_scoreBlack));
    _sfml->draw(sw);
    _sfml->draw(sb);
    _sfml->display();
}

std::optional<std::vector<sf::RectangleShape>::iterator> Scene::getCollision(sf::Vector2f position)
{
    for (std::vector<sf::RectangleShape>::iterator it = _rectangles.begin(); it != _rectangles.end(); it++) {
        if (position.x > it->getPosition().x && position.x < it->getPosition().x + it->getSize().x &&
            position.y > it->getPosition().y && position.y < it->getPosition().y + it->getSize().y)
                return it;
    }
    return nullopt;
}

int Scene::getScoreTile(sf::RectangleShape rect)
{
    int result = (980 - rect.getPosition().y + rect.getSize().y / 2);
    std::cout << result << std::endl;
    return 20 - result / 10;
}

void Scene::handleEvents()
{
    static array<bool, 6> keyStatus = {false, false, false, false, false, false};
    _sfml->events();
    if (!keyStatus[0] && _sfml->isButtonPressed(sf::Keyboard::Q) && getCollision(sf::Vector2f(_lanesX[0] + TILESIZEX / 2, 980 )) != std::nullopt)
    {
        std::vector<sf::RectangleShape>::iterator it = (*getCollision(sf::Vector2f(_lanesX[0] + TILESIZEX / 2, 980 )));
        it->getFillColor() == sf::Color::White ? _scoreWhite += getScoreTile(*it) : _scoreWhite -= 20;
        _rectangles.erase(it);
    }
    if (!keyStatus[1] && _sfml->isButtonPressed(sf::Keyboard::S) && getCollision(sf::Vector2f(_lanesX[1] + TILESIZEX / 2, 980 )) != std::nullopt)
    {
        std::vector<sf::RectangleShape>::iterator it = (*getCollision(sf::Vector2f(_lanesX[1] + TILESIZEX / 2, 980 )));
        it->getFillColor() == sf::Color::White ? _scoreWhite += getScoreTile(*it) : _scoreWhite -= 20;
        _rectangles.erase(it);
    }
    if (!keyStatus[2] && _sfml->isButtonPressed(sf::Keyboard::D) && getCollision(sf::Vector2f(_lanesX[2] + TILESIZEX / 2, 980 )) != std::nullopt)
    {
        std::vector<sf::RectangleShape>::iterator it = (*getCollision(sf::Vector2f(_lanesX[2] + TILESIZEX / 2, 980 )));
        it->getFillColor() == sf::Color::White ? _scoreWhite += getScoreTile(*it) : _scoreWhite -= 20;
        _rectangles.erase(it);
    }

    if (!keyStatus[3] && _sfml->isButtonPressed(sf::Keyboard::K) && getCollision(sf::Vector2f(_lanesX[0] + TILESIZEX / 2, 980 )) != std::nullopt)
    {
        std::vector<sf::RectangleShape>::iterator it = (*getCollision(sf::Vector2f(_lanesX[0] + TILESIZEX / 2, 980 )));
        it->getFillColor() == sf::Color::Black ? _scoreBlack += getScoreTile(*it) : _scoreBlack -= 20;
        _rectangles.erase(it);
    }
    if (!keyStatus[4] && _sfml->isButtonPressed(sf::Keyboard::L) && getCollision(sf::Vector2f(_lanesX[1] + TILESIZEX / 2, 980 )) != std::nullopt)
    {
        std::vector<sf::RectangleShape>::iterator it = (*getCollision(sf::Vector2f(_lanesX[1] + TILESIZEX / 2, 980 )));
        it->getFillColor() == sf::Color::Black ? _scoreBlack += getScoreTile(*it) : _scoreBlack -= 20;
        _rectangles.erase(it);
    }
    if (!keyStatus[5] && _sfml->isButtonPressed(sf::Keyboard::M) && getCollision(sf::Vector2f(_lanesX[2] + TILESIZEX / 2, 980 )) != std::nullopt)
    {
        std::vector<sf::RectangleShape>::iterator it = (*getCollision(sf::Vector2f(_lanesX[2] + TILESIZEX / 2, 980 )));
        it->getFillColor() == sf::Color::Black ? _scoreBlack += getScoreTile(*it) : _scoreBlack -= 20;
        _rectangles.erase(it);
    }

    keyStatus[0] = _sfml->isButtonPressed(sf::Keyboard::Q) ? true : false;
    keyStatus[1] = _sfml->isButtonPressed(sf::Keyboard::S) ? true : false;
    keyStatus[2] = _sfml->isButtonPressed(sf::Keyboard::D) ? true : false;
    keyStatus[3] = _sfml->isButtonPressed(sf::Keyboard::K) ? true : false;
    keyStatus[4] = _sfml->isButtonPressed(sf::Keyboard::L) ? true : false;
    keyStatus[5] = _sfml->isButtonPressed(sf::Keyboard::M) ? true : false;
}

void Scene::loop(void)
{
    int test = 0;
    _sfml->playMusic(_parsing.getFileName().substr(0, _parsing.getFileName().size() - 4));
    while (_sceneRunning && _sfml->windowIsOpen()) {
        if (_sfml->getClock().getElapsedTime().asSeconds() - _clock > 1 / 60 ) {
            _clock = _sfml->getClock().getElapsedTime().asSeconds();
            if (test >= 10) {
                handleEvents();
                test = 0;
            }
            test++;
            updateFromFile();
            updateDisplay();
        }
    }
}

int Scene::endLevel(void)
{
}
