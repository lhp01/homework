#include "icon.h"
#include<iostream>
int ICON::GRID_SIZE = 50;


pair<string,ICON> pairArray[] =
{
    make_pair("player",ICON("player",18,8,2,2)),
    make_pair("stone",ICON("stone",11,4,2,2)),
    make_pair("fruit",ICON("fruit",13,4,2,2)),
};

map<string,ICON> ICON::GAME_ICON_SET(pairArray,pairArray+sizeof(pairArray)/sizeof(pairArray[0]));


ICON::ICON(string name, int x, int y, int w, int h){
    this->typeName = name;
    this->srcX = x;
    this->srcY = y;
    this->width = w;
    this->height = h;
}

ICON ICON::findICON(string type){
    map<string,ICON>::iterator kv;
    kv = ICON::GAME_ICON_SET.find(type);
    if (kv==ICON::GAME_ICON_SET.end()){

       cout<<"Error: cannot find ICON"<<endl;
       return ICON();
    }
    else{
        return kv->second;
    }
}

