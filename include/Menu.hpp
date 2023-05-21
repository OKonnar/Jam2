/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Menu.hpp
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "Scene.hpp"

class Menu
{
    private:
        shared_ptr<SFML> _sfml;
        vector<sf::RectangleShape> _rectangles;

    public:
        Menu(shared_ptr<SFML> sfml);
        ~Menu() {};
};

#endif /* MENU_HPP_ */