
#include "Level.h"

Level::Level(Graphics* ngraphicsG){
    nb_objects = 0;
    graphicsG = ngraphicsG;
    
    //initialisation tileset
    tileLayer = new gf::TileLayer({NUMBER_OF_TILES_ROWS,NUMBER_OF_TILES_ROWS});
    tileLayer->setTexture( *graphicsG->getTileTexture() );
    tileLayer->setTileSize({SIZE_OF_A_TILE,SIZE_OF_A_TILE});
    tileLayer->setMargin(TILESET_MARGIN);
    tileLayer->setSpacing(TILESET_SPACING);
    
    //fond du niveau
    background = new gf::Sprite();
    background->setTexture(*graphicsG->getBGTexture());
    background->setTextureRect({ 0.0f, 0.0f, 1.0f, 0.333f });
    gf::Vector2f position(0,0);
    background->setPosition(position);
    
    bgRenderState = new gf::RenderStates();
    gf::Matrix3f matrice = gf::identityTransform();
    gf::scale(matrice, {8,8});                      //8 fois plus grand
    bgRenderState->transform = matrice;

    //mise en place des tuiles
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
    graphicsG->draw(background, bgRenderState); //rendu du fond en 1er pour qu'il soit au fond
    graphicsG->draw(tileLayer);                 //puis des tuiles
    unsigned int i;
    for(i = 0; i < nb_objects && i < MAX_GAMEOBJECTS; i++)
        update(*listGameObjects[i]);            //mise à jour des GameObjects
}

void Level::addGameObject(GameObject *obj){
    listGameObjects[nb_objects] = obj;
    nb_objects++;
}

gf::Window* Level::getWindow(){
    return graphicsG->m_window;
}