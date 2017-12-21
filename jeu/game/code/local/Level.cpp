
#include "Level.h"

Level::Level(Graphics* ngraphicsG){
    nb_objects = 0;
    graphicsG = ngraphicsG;
    
    tileLayer = new gf::TileLayer({NUMBER_OF_TILES_ROWS,NUMBER_OF_TILES_ROWS});
    tileLayer->setTexture( *graphicsG->getTileTexture() );
    tileLayer->setTileSize({SIZE_OF_A_TILE,SIZE_OF_A_TILE});
    tileLayer->setMargin(TILESET_MARGIN);
    tileLayer->setSpacing(TILESET_SPACING);
    
    tileLayer->setTile({1,1},4);    //TODO
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