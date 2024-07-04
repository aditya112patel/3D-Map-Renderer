#pragma once
#include <SFML/graphics.hpp>
#include <iostream>

sf::Vector2f windowsize=sf::Vector2f(1024,600);

const int margin_up = 38;
const int margin_left = 9;

const int col = 48;
const int row = 32;
const int tilesize = 16;

const int empty = 0;
const int wall = 1;
const int grass = 2;
const int floor_ = 3;
const int border = 4;