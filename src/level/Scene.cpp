/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** Scene
*/

#include "Scene.hpp"

using namespace std;

Scene::Scene() {}
Scene::~Scene() {}

void Scene::startLevel(string configFile, shared_ptr<SFML> sfml)
{
    _sfml = sfml;
    _parsing.parseFile(configFile);
    _lanesX = {50, 100, 150};
    //_sfml->loadMusic(_parsing.getFileName());
    //create all sprites of the background
}

void Scene::loop(void)
{
    bool running = true;
    //_sfml->playMusic(_parsing.getFileName());
    unsigned int cpt = 0;
    int clck = 0;

    while (running && _sfml->getClock().getElapsedTime().asMilliseconds() > clck) {
        _sfml->events();
        //handle events, remove tiles that have been catched
git
        std::vector<int> tiles = _parsing.getLine(cpt);
        for (std::size_t i = 0; i < tiles.size(); i++) {
            if (tiles[i] == 0)
                _rectangles.push_back(_sfml->create(sf::Vector2f(TILESIZEX, TILESIZEY), sf::Vector2f(_lanesX[i], -TILESIZEY), sf::Color::Black));
            if (tiles[i] == 1)
                _rectangles.push_back(_sfml->create(sf::Vector2f(TILESIZEX, TILESIZEY), sf::Vector2f(_lanesX[i], -TILESIZEY), sf::Color::White));
        }
        cpt++;
        for (std::vector<sf::RectangleShape>::iterator it = _rectangles.begin(); it != _rectangles.end(); it++)
            if (it->getPosition().y > 1080)
                _rectangles.erase(it);
        _sfml->clear();
        for (vector<sf::Sprite>::iterator it = _sprites.begin(); it != _sprites.end(); it++)
            _sfml->updateSprite(*it);
        for (vector<sf::RectangleShape>::iterator it = _rectangles.begin(); it != _rectangles.end(); it++) {
            it->setSize(sf::Vector2f(it->getSize().x, it->getSize().y + TILESIZEY));
            _sfml->updateSprite(*it, it->getSize());
        }
        _sfml->display();
        clck += 10;
    }
}

int Scene::endLevel(void)
{

}
