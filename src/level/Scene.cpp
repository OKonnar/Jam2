/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** Scene
*/

#include "Scene.hpp"

using namespace std;

Scene::Scene(string configFile, shared_ptr<SFML> sfml) {
    _sfml = sfml;
    _parsing.parseFile(configFile);
    _lanesX = {800, 910, 1020};
    _linesCpt = 0;
    _sceneRunning = true;
    //_sfml->loadMusic(_parsing.getFileName());
    //create all sprites of the background
}

Scene::~Scene() {}

void Scene::updateFromFile()
{
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
    for (std::vector<sf::RectangleShape>::iterator it = _rectangles.begin(); it != _rectangles.end(); it++)
        if (it->getPosition().y > 1080)
            _rectangles.erase(it);
}

void Scene::updateDisplay()
{
    _sfml->clear();
    for (vector<sf::Sprite>::iterator it = _sprites.begin(); it != _sprites.end(); it++)
        _sfml->updateSprite(*it);
    for (vector<sf::RectangleShape>::iterator it = _rectangles.begin(); it != _rectangles.end(); it++) {
        it->setSize(sf::Vector2f(it->getSize().x, it->getSize().y + TILESIZEY));
        _sfml->updateSprite(*it);
    }
    _sfml->display();
}

void Scene::loop(void)
{
    //_sfml->playMusic(_parsing.getFileName());
    while (_sceneRunning) {
        if (_sfml->getClock().getElapsedTime().asMilliseconds() - _clock > 10) {
            _clock = _sfml->getClock().getElapsedTime().asMilliseconds();
            _sfml->events();
            //handle events, remove tiles that have been catched
            updateFromFile();
            updateDisplay();
        }
    }
}

int Scene::endLevel(void)
{

}
