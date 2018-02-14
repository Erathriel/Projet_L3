
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
    tileLayer = new gf::TileLayer({NUMBER_OF_TILES_X,NUMBER_OF_TILES_Y});
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
    int x_start = NB_ROOMS_X/2;
    int y_start = NB_ROOMS_Y/2;
    //int x_end, y_end;
    int x = x_start;
    int y = y_start;
    bool direction[4];
    int nb_directions;
    int rand_num;
    
    rooms(gf::Vector2f(x,y)).generated = true;
    rooms(gf::Vector2f(x,y)).number = 0;
    i = 0;
    while(i < nb_rooms){
        //printf("%i  %i\n", x, y);
        
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
            //x_end = x; y_end = y;
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
            rooms(gf::Vector2f(x,y)).next_room = UP;
            y -= 1;
            rooms(gf::Vector2f(x,y)).wall[DOWN] = false;
        }
        if(direction[DOWN]){
            rooms(gf::Vector2f(x,y)).wall[DOWN] = false;
            rooms(gf::Vector2f(x,y)).next_room = DOWN;
            y += 1;
            rooms(gf::Vector2f(x,y)).wall[UP] = false;
        }
        if(direction[RIGHT]){
            rooms(gf::Vector2f(x,y)).wall[RIGHT] = false;
            rooms(gf::Vector2f(x,y)).next_room = RIGHT;
            x += 1;
            rooms(gf::Vector2f(x,y)).wall[LEFT] = false;
        }
        if(direction[LEFT]){
            rooms(gf::Vector2f(x,y)).wall[LEFT] = false;
            rooms(gf::Vector2f(x,y)).next_room = LEFT;
            x -= 1;
            rooms(gf::Vector2f(x,y)).wall[RIGHT] = false;
        }
        
        rooms(gf::Vector2f(x,y)).generated = true;
        rooms(gf::Vector2f(x,y)).number = i+1;
        
        i++;
    }
    tileLayer->clear();
    placeWalls();
    placePlatforms();
    
}


void Level::placeWalls(){
    //mise en place des murs des rooms
    b2PolygonShape box;
    b2FixtureDef fixtureDef;
    tileBodyDef.type = b2_staticBody;
    tileBodyDef.position.Set(0,0);
    unsigned int x, y, i;
    int wall_tile_down = 123;
    int wall_tile_up = 152;
    int wall_tile_right = 152;
    int wall_tile_left = 152;
    tileBody = world->CreateBody(&tileBodyDef);
    

    for(x = 0; x < NB_ROOMS_X; x++){
        for(y = 0; y < NB_ROOMS_Y; y++){
            if(rooms(gf::Vector2f(x,y)).generated){
                if(rooms(gf::Vector2f(x,y)).wall[UP]){
                    //printf("up %i %i\n", x ,y);
                    box.SetAsBox( (SIZE_ROOM_X_px)/2.0f, (SIZE_OF_A_TILE)/2.0f, b2Vec2((x+0.5f)*SIZE_ROOM_X_px, y*SIZE_ROOM_Y_px+ SIZE_OF_A_TILE*0.4), 0);
                    fixtureDef.shape = &box;
                    tileBody->CreateFixture(&fixtureDef);
                    for(i = 0; i < SIZE_ROOM_X; i++)
                        tileLayer->setTile({x*SIZE_ROOM_X + i, y*SIZE_ROOM_Y},wall_tile_up);
                }
                if(rooms(gf::Vector2f(x,y)).wall[DOWN]){
                    box.SetAsBox((SIZE_ROOM_X_px)/2.0f, (SIZE_OF_A_TILE)/2.0f, b2Vec2((x+0.5f)*SIZE_ROOM_X_px, (y+1)*SIZE_ROOM_Y_px - SIZE_OF_A_TILE*0.6f),0);
                    fixtureDef.shape = &box;
                    tileBody->CreateFixture(&fixtureDef);
                    for(i = 0; i < SIZE_ROOM_X; i++)
                        tileLayer->setTile({x*SIZE_ROOM_X + i, (y+1)*SIZE_ROOM_Y-1},wall_tile_down);
                }
                if(rooms(gf::Vector2f(x,y)).wall[RIGHT]){
                    box.SetAsBox((SIZE_OF_A_TILE)/2.0f, (SIZE_ROOM_Y_px)/2.0f, b2Vec2((x+1)*SIZE_ROOM_X_px - SIZE_OF_A_TILE*0.5f, (y+0.5)*SIZE_ROOM_Y_px - SIZE_OF_A_TILE*0.2f), 0);
                    fixtureDef.shape = &box;
                    tileBody->CreateFixture(&fixtureDef);
                    for(i = 0; i < SIZE_ROOM_Y; i++)
                        tileLayer->setTile({(x+1)*SIZE_ROOM_X -1, y*SIZE_ROOM_Y + i},wall_tile_right);
                }
                if(rooms(gf::Vector2f(x,y)).wall[LEFT]){
                    box.SetAsBox((SIZE_OF_A_TILE)/2.0f, (SIZE_ROOM_Y_px)/2.0f, b2Vec2(x*SIZE_ROOM_X_px + SIZE_OF_A_TILE*0.5f, (y+0.5)*SIZE_ROOM_Y_px - SIZE_OF_A_TILE*0.2f), 0);
                    fixtureDef.shape = &box;
                    tileBody->CreateFixture(&fixtureDef);
                    for(i = 0; i < SIZE_ROOM_Y; i++)
                        tileLayer->setTile({x*SIZE_ROOM_X, y*SIZE_ROOM_Y + i},wall_tile_left);
                }
            }
        } 
    }

}

void Level::placePlatforms(){
    unsigned int x_dest, y_dest, x_room, y_room, x_start, y_start;
    bool found = false;
    gf::Vector2f vector;
    
    for(x_room = 0; x_room < NB_ROOMS_X && !found; x_room++){
        for(y_room = 0; y_room < NB_ROOMS_Y && !found; y_room++)
            if(rooms(gf::Vector2f(x_room,y_room)).number == 0)
                found = true;
    }
    
    x_room--;
    y_room--;
    
    while(rooms(gf::Vector2f(x_room,y_room)).next_room != -1){
        //printf("b %i\n", rooms(gf::Vector2f(x_room,y_room)).next_room);
        x_start = x_room*SIZE_ROOM_X + SIZE_ROOM_X/2;
        y_start = y_room*SIZE_ROOM_Y + SIZE_ROOM_Y/2;
        if(rooms(gf::Vector2f(x_room,y_room)).next_room == UP)
            y_room += -1;
        else if(rooms(gf::Vector2f(x_room,y_room)).next_room == DOWN)
            y_room += 1;
        else if(rooms(gf::Vector2f(x_room,y_room)).next_room == RIGHT)
            x_room += 1;
        else if(rooms(gf::Vector2f(x_room,y_room)).next_room == LEFT)
            x_room += -1;
        else break;
        x_dest = x_room*SIZE_ROOM_X + SIZE_ROOM_X/2;
        y_dest = y_room*SIZE_ROOM_Y + SIZE_ROOM_Y/2;
        
        do{
            vector = placePlatform(x_start, y_start, x_dest, y_dest);
            x_start = vector.x;
            y_start = vector.y;
        }while( vector != gf::Vector2f(x_dest, y_dest) );

        
    }
    
}

gf::Vector2f Level::placePlatform(unsigned int x_start, unsigned int y_start, unsigned int x_dest, unsigned int y_dest){
    b2PolygonShape box;
    b2FixtureDef fixtureDef;
    unsigned int modifier_x, modifier_y;
    
    if(x_start < x_dest)
        modifier_x = 1;
    if(x_start > x_dest)
        modifier_x = -1;
    if(y_start < y_dest)
        modifier_y = 1;
    if(y_start > y_dest)
        modifier_y = -1;

    tileLayer->setTile({x_start, y_start},4);
    tileLayer->setTile({x_start + modifier_x, y_start + modifier_y},4);

    x_dest = x_start + modifier_x;
    y_dest = y_start + modifier_y;
    
    
    //printf("lol\n");
    return gf::Vector2f(x_dest, y_dest);
    
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


