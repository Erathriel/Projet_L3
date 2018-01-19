
#include "Level.h"

Level::Level(Graphics* ngraphicsG){
    nb_objects = 0;
    graphicsG = ngraphicsG;
    
    // Define the gravity vector.
    gravity = new b2Vec2(0.0f, GRAVITY);
    // Construct a world object, which will hold and simulate the rigid bodies.
    world = new b2World(*gravity);
    contactListener = new ContactListener;
    world->SetContactListener(contactListener);
    
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
    background->scale(8);
    gf::Vector2f position(0,0);
    background->setPosition(position);
    
//     bgRenderState = new gf::RenderStates();
//     gf::Matrix3f matrice = gf::identityTransform();
//     gf::scale(matrice, {8,8});                      //8 fois plus grand
//     bgRenderState->transform = matrice;

    generateLevel(9);
    
}

void Level::generateLevel(int nb_rooms){
    
    rooms = gf::Array2D<roomstruct>(gf::Vector2f(NB_ROOMS_X,NB_ROOMS_Y));
    srand (time(NULL));
    int i, j;
    int x_start = 0;
    int y_start = 0;
    int x_end, y_end;
    int x = x_start;
    int y = y_start;
    bool direction[4];
    int nb_directions;
    int rand_num;
    
    rooms(gf::Vector2f(x,y)).generated = true;
    i = 0;
    while(i < nb_rooms){
        printf("%i  %i\n", x, y);
        
        for(j = 0; j < 4; j++)
            direction[j] = true;
        
        if(x-1 < 0 || rooms(gf::Vector2f(x-1,y)).generated)
            direction[LEFT] = false;
        if(x+1 > NB_ROOMS_X || rooms(gf::Vector2f(x+1,y)).generated)
            direction[RIGHT] = false;
        if(y-1 < 0 || rooms(gf::Vector2f(x,y-1)).generated)
            direction[UP] = false;
        if(y+1 > NB_ROOMS_Y || rooms(gf::Vector2f(x,y+1)).generated)
            direction[DOWN] = false;
        if(!direction[LEFT] && !direction[RIGHT] && !direction[UP] && !direction[DOWN]){
            x_end = x; y_end = y;
            break;
        }
        
        do{
            rand_num = rand() % 4;
            direction[rand_num] = false;
            
            nb_directions = 0;
            for(j = 0; j < 4; j++)
                nb_directions += (int)direction[j];
        }while( nb_directions > 1);
        
        if(direction[UP]){
            rooms(gf::Vector2f(x,y)).wall[UP] = false;
            y -= 1;
            rooms(gf::Vector2f(x,y)).wall[DOWN] = false;
        }
        if(direction[DOWN]){
            rooms(gf::Vector2f(x,y)).wall[DOWN] = false;
            y += 1;
            rooms(gf::Vector2f(x,y)).wall[UP] = false;
        }
        if(direction[RIGHT]){
            rooms(gf::Vector2f(x,y)).wall[RIGHT] = false;
            x += 1;
            rooms(gf::Vector2f(x,y)).wall[LEFT] = false;
        }
        if(direction[LEFT]){
            rooms(gf::Vector2f(x,y)).wall[LEFT] = false;
            x -= 1;
            rooms(gf::Vector2f(x,y)).wall[RIGHT] = false;
        }
        
        rooms(gf::Vector2f(x,y)).generated = true;
        
        i++;
    }
    
    placeTiles();
}


void Level::placeTiles(){
    //mise en place des tuiles
    tileLayer->clear();
    unsigned int x, y, i;
    int wall_tile = 4;
    for(x = 0; x < NB_ROOMS_X; x++){
        for(y = 0; y < NB_ROOMS_Y; y++){
            if(rooms(gf::Vector2f(x,y)).generated){
                if(rooms(gf::Vector2f(x,y)).wall[UP]){
                    printf("up\n");
                    for(i = 0; i < SIZE_ROOM_X; i++)
                        tileLayer->setTile({x*SIZE_ROOM_X + i, y*SIZE_ROOM_Y},wall_tile);
                }
                if(rooms(gf::Vector2f(x,y)).wall[DOWN]){
                    printf("down\n");
                    for(i = 0; i < SIZE_ROOM_X; i++)
                        tileLayer->setTile({x*SIZE_ROOM_X + i, (y+1)*SIZE_ROOM_Y-1},wall_tile);
                }
                if(rooms(gf::Vector2f(x,y)).wall[RIGHT]){
                    printf("right\n");
                    for(i = 0; i < SIZE_ROOM_Y; i++)
                        tileLayer->setTile({(x+1)*SIZE_ROOM_X -1, y*SIZE_ROOM_Y + i},wall_tile);
                }
                if(rooms(gf::Vector2f(x,y)).wall[LEFT]){
                    printf("left\n");
                    for(i = 0; i < SIZE_ROOM_Y; i++)
                        tileLayer->setTile({x*SIZE_ROOM_X, y*SIZE_ROOM_Y + i},wall_tile);
                }
            }
        } 
    }
    
     
    //physique pour les tuiles
    // Define the ground body.
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, 20.0f*(SIZE_OF_A_TILE+1));
    // Call the body factory which allocates memory for the ground body
    // from a pool and creates the ground box shape (also from a pool).
    // The body is also added to the world.
    tilePhysicBody = world->CreateBody(&groundBodyDef);
    // Define the ground box shape.
    b2PolygonShape groundBox;
    // The extents are the half-widths of the box.
    groundBox.SetAsBox(1000.0f, SIZE_OF_A_TILE);
    // Add the ground fixture to the ground body.
    tilePhysicBody->CreateFixture(&groundBox, 0.0f);
    
}

float Level::getdt(){
    return dt;
}

void Level::update(GameObject& obj){
    obj.update(*this, *graphicsG);
}

void Level::updateGameObjects(float ndt){
    dt = ndt;
    graphicsG->draw(background); //rendu du fond en 1er pour qu'il soit au fond
    graphicsG->draw(tileLayer);                 //puis des tuiles
    unsigned int i;
    for(i = 0; i < nb_objects && i < MAX_GAMEOBJECTS; i++)
        update(*listGameObjects[i]);            //mise à jour des GameObjects
}

void Level::addGameObject(GameObject *obj){
    obj->initialize(*this, *graphicsG);
    listGameObjects[nb_objects] = obj;
    nb_objects++;
}

gf::Window* Level::getWindow(){
    return graphicsG->m_window;
}

