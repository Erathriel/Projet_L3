
#include "Level.h"
#include <gf/Rect.h>

Level::Level(Graphics* ngraphicsG){
    nb_objects = 0;
    graphicsG = ngraphicsG;
    
    tileLayer = new gf::TileLayer({NUMBER_OF_TILES_ROWS,NUMBER_OF_TILES_ROWS});
    tileLayer->setTexture( *graphicsG->getTileTexture() );
    tileLayer->setTileSize({SIZE_OF_A_TILE,SIZE_OF_A_TILE});
    tileLayer->setMargin(TILESET_MARGIN);
    tileLayer->setSpacing(TILESET_SPACING);
    
    tileLayer->setTile({1,1},4);    //TODO

    sprite = new gf::Sprite();
    sprite->setTexture(*graphicsG->getTileTexture());
    gf::Vector2f position(0,0);
    sprite->setPosition(position);
    sprite->setTextureRect({ 0.635f, 0.0f, 0.035f, 0.035f });
   // sprite->setAnchor(gf::Anchor::TopLeft);
}

float Level::getdt(){
    return dt;
}

void Level::update(GameObject& obj){
    obj.update(*this, *graphicsG);
}

void Level::updateGameObjects(float ndt){
    dt = ndt;
    graphicsG->draw(tileLayer);
    graphicsG->draw(sprite);
    unsigned int i;
    for(i = 0; i < nb_objects && i < MAX_GAMEOBJECTS; i++)
        update(*listGameObjects[i]);
}

void Level::addGameObject(GameObject *obj){
    listGameObjects[nb_objects] = obj;
    nb_objects++;
}

gf::Window* Level::getWindow(){
    return graphicsG->m_window;
}