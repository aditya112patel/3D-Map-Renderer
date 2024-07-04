#pragma once
#include "global_const.h"
#include<iostream>
#include <SFML/graphics.hpp>

using namespace sf;
bool check_border(int i) {
	if ((i + 1) % col == 0 || i < col || i >= col * (row - 1) || (i + 1) % col == 1)return true;
	else return false;
}

int tile_number(int x,int y) {
    if (x > 0 && x < (col * tilesize) && y>0 && y < (row * tilesize)) {
        int tile_num = (y / tilesize) * col + (x / tilesize);
        if (!check_border(tile_num)) {
            return tile_num;
        }
        else return -1;
    }
    else return -1;
}

std::vector<std::pair<int, int>> range_x = {
    {64,96},
    {128,160},
    {80,80+64},
    {64,96},
    {128,160},
    {96,96+32},
    {80,80 + 64},
},
range_y = {
    {64,96},
    {64,96},
    {96+24,96+24+24},
    {224,224+32},
    {224,224 + 32},
    {224+32+32,224+32+32+32},
    {288+32+128,288+32+128+24}
};

int set_func(int x, int y) {
    for (int i = 0; i < 7; i++)
    {
        if (x > range_x[i].first && x <range_x[i].second && y>range_y[i].first && y < range_y[i].second) {
            return i;
        }
    }
    return -1;
}

int active_tool(int x,int y) {
    if (x==0) {
        return y;
    }
    else if (x == 1) {
        return empty;
    }
    else if (x == 3) {
        return wall;
    }
    else if (x == 4) {
        return grass;
    }
    else if (x == 5) {
        return floor_;
    }
    return y;
}

void clear_map(int* v) {
    for (int i = 0; i < row*col; i++)
    {
        if(!check_border(i))
            v[i] = empty;
    }
}