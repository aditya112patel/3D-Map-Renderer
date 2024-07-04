#include <SFML/Graphics.hpp>
#include<iostream>
#include "map.h"
#include "helper.h"
#include "global_const.h"

using namespace sf;

    Sprite sidebar;
    Texture sb;
    
int main()
{
    sf::RenderWindow window(sf::VideoMode(windowsize.x,windowsize.y), "MAP EDITOR");

    sb.loadFromFile("assets/sidebar.png");
    sidebar.setTexture(sb);
    Vector2f pos = sidebar.getLocalBounds().getSize();
    sidebar.setPosition(window.getSize().x - pos.x, 0);
    
    int curr_active = wall , prev_active=wall;
    
    int level[row*col];
    for (int i = 0; i < row * col; i++)
    {
        level[i] = empty;
        if (check_border(i))level[i] = border;
    }
    
    
    TileMap map;
    if (!map.load("assets/tileset.png", sf::Vector2u(16, 16), level, 48, 32))
        return -1;

    map.setPosition(10,10);
    bool mousebutton = false;
    //map.setPosition(10, 10);
    while (window.isOpen())
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            Mouse mouse;
            if (event.type == Event::MouseButtonPressed) {
                mousebutton = true;
                int x = (mouse.getPosition().x-window.getPosition().x -margin_left)-sidebar.getPosition().x;
                int y = (mouse.getPosition().y-window.getPosition().y-margin_up) - sidebar.getPosition().y;
                int button=set_func(x, y);
                if (button != -1) {
                    if (button == 2) {
                        clear_map(level);
                    }
                    if (button == 6) {

                    }
                    else {
                        if (curr_active != empty)prev_active = curr_active;
                        curr_active = active_tool(button,prev_active);
                    }
                        
                }
                std::cout << x << " " << y << button << "\n";
         
            }
            if (event.type == Event::MouseButtonReleased) {
                    mousebutton = false;
            }
            if(mousebutton)
            { 
                int x = (mouse.getPosition().x - window.getPosition().x - margin_left-map.getPosition().x);
                int y = (mouse.getPosition().y - window.getPosition().y - margin_up - map.getPosition().y);

                if (tile_number(x,y) != -1) {
                    int tile_num = tile_number(x,y);
                    std::cout << curr_active<< " " <<tile_num << "\n";
                    level[tile_num] = curr_active;
                }
            }
            if (!map.load("assets/tileset.png", sf::Vector2u(16, 16), level, 48, 32))
                return -1;
        }
        
        
        window.clear();
        //window.draw(shape);
        window.draw(map);
        window.draw(sidebar);
        window.display();
    }

    return 0;
}