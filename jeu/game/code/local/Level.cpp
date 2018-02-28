
#include "Level.h"

GameObject* createProtag();

Level::Level(Graphics* ngraphicsG){
    nb_objects = 0;
    graphicsG = ngraphicsG;
    
    // Define the gravity vector.
    gravity = b2Vec2(0.0f, GRAVITY);
    // Construct a world object, which will hold and simulate the rigid bodies.
    world = new b2World(gravity);
    contactListener = new ContactListener;
    world->SetContactListener(contactListener);
    
    //initialisation tileset
    tileLayer = new gf::TileLayer({NUMBER_OF_TILES_X,NUMBER_OF_TILES_Y});
    tileLayer->setTexture( *graphicsG->getTileTexture() );
    tileLayer->setTileSize({SIZE_OF_A_TILE,SIZE_OF_A_TILE});
    tileLayer->setMargin(TILESET_MARGIN);
    tileLayer->setSpacing(TILESET_SPACING);
    
    //fond du niveau
    background.setTexture(*graphicsG->getBGTexture());
    background.setTextureRect({ 0.0f, 0.0f, 1.0f, 0.333f });
    background.scale(8);
    background.setAnchor(gf::Anchor::Center);
    gf::Vector2f position(0,0);
    background.setPosition(position);
    
//     bgRenderState = new gf::RenderStates();
//     gf::Matrix3f matrice = gf::identityTransform();
//     gf::scale(matrice, {8,8});                      //8 fois plus grand
//     bgRenderState->transform = matrice;

    newLevel();
    
}

Level::~Level(){
    printf("0\n");
    emptyLevel();
    printf("1\n");
    delete tileLayer;
    printf("1.5\n");
    delete world;
    printf("2\n");
    delete contactListener;
    printf("3\n");
}

void Level::newLevel(){
    protag = createProtag();
    addGameObject(protag);
    
    generateLevel(9);
}

void Level::endLevel(){
    emptyLevel();
    newLevel();
    printf("0\n");
}

void Level::emptyLevel(){
    tileLayer->clear();;
    world->DestroyBody(tileBody);
    int i;
    for(i = 0; i < nb_objects; i++)
        //delete listGameObjects[i];
    nb_objects = 0;
    //if(listGameObjects.size() > 0)
    //    listGameObjects.erase(listGameObjects.begin(), listGameObjects.end()-1);
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
    i = 0;;
    while(i < nb_rooms){
        //printf("%i  %i\n", x, y);
        
        for(j = 0; j < 4; j++)
            direction[j] = true;
        
        if(x-1 < 0 || rooms(gf::Vector2f(x-1,y)).generated)
            direction[LEFT] = false;
        if(x+1 > NB_ROOMS_X-1 || rooms(gf::Vector2f(x+1,y)).generated)
            direction[RIGHT] = false;
        if(y-1 < 0 || rooms(gf::Vector2f(x,y-1)).generated)
            direction[UP] = false;
        if(y+1 > NB_ROOMS_Y-1 || rooms(gf::Vector2f(x,y+1)).generated)
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
    tileBodyDef.type = b2_staticBody;
    tileBodyDef.position.Set(0,0);
    tileBody = world->CreateBody(&tileBodyDef);
    placeWalls();
    placePlatforms();
}


void Level::placeWalls(){
    //mise en place des murs des rooms
    b2PolygonShape box;
    b2FixtureDef fixtureDef;
    fixtureDef.filter.categoryBits = TILE;
    fixtureDef.filter.maskBits = DEFAULT | PROTAG;
    fixtureDef.density = 0.0f;
    unsigned int x, y, i;
    int wall_tile_down = 123;
    int wall_tile_up = 152;
    int wall_tile_right = 152;
    int wall_tile_left = 152;
    

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
    b2PolygonShape box;
    b2FixtureDef fixtureDef;
    fixtureDef.filter.categoryBits = TILE;
    fixtureDef.filter.maskBits = PROTAG;
    fixtureDef.density = 0.0f;
    b2Fixture* fixture;
    unsigned int x_dest = 1;
    unsigned int y_dest = 1;
    unsigned int x_room, y_room, x_start, y_start, rand_num;
    bool found = false;
    bool ladder = false;
    gf::Vector2f vector;
    
    for(x_room = 0; x_room < NB_ROOMS_X && !found; x_room++){
        for(y_room = 0; y_room < NB_ROOMS_Y && !found; y_room++)
            if(rooms(gf::Vector2f(x_room,y_room)).number == 0)
                found = true;
    }
    
    x_room--;
    y_room--;
    
    x_start = x_room*SIZE_ROOM_X + SIZE_ROOM_X/2;
    y_start = y_room*SIZE_ROOM_Y + SIZE_ROOM_Y/2 +3;
    while(rooms(gf::Vector2f(x_room,y_room)).next_room != -1){
        //printf("b %i\n", rooms(gf::Vector2f(x_room,y_room)).next_room);
        if(rooms(gf::Vector2f(x_room,y_room)).next_room != DOWN)
            ladder = true;
        if(rooms(gf::Vector2f(x_room,y_room)).next_room == UP)
            y_room += -1;
        else if(rooms(gf::Vector2f(x_room,y_room)).next_room == DOWN)
            y_room += 1;
        else if(rooms(gf::Vector2f(x_room,y_room)).next_room == RIGHT)
            x_room += 1;
        else if(rooms(gf::Vector2f(x_room,y_room)).next_room == LEFT)
            x_room += -1;
        else break;
        rand_num = (rand() % (SIZE_ROOM_X-4)) +2 ;
        x_dest = x_room*SIZE_ROOM_X + rand_num;
        rand_num = (rand() % (SIZE_ROOM_Y-4)) +2 ;
        y_dest = y_room*SIZE_ROOM_Y + rand_num;
        do{
            vector = placePlatform(x_start, y_start, x_dest, y_dest, x_room*SIZE_ROOM_X, y_room*SIZE_ROOM_Y, ladder);
            x_start = vector.x;
            y_start = vector.y;
            ladder = false;
            //printf("%i lol\n", y_start);
        }while( vector != gf::Vector2f(x_dest, y_dest) );
    }
    
    tileLayer->setTile({x_dest, y_dest-1},168);
    
    box.SetAsBox( (SIZE_OF_A_TILE)/1.5f, (SIZE_OF_A_TILE)/1.5f, b2Vec2((x_dest)*SIZE_OF_A_TILE + SIZE_OF_A_TILE/2.0f, y_dest*SIZE_OF_A_TILE- SIZE_OF_A_TILE/2.0f), 0);
    fixtureDef.shape = &box;
    fixture = tileBody->CreateFixture(&fixtureDef);
    fixture->SetUserData( (void*)UD_EXIT );
    
}

gf::Vector2f Level::placePlatform(unsigned int x_start, unsigned int y_start, unsigned int x_dest, unsigned int y_dest, int room_x, int room_y, bool ladder){
    b2PolygonShape box;
    b2FixtureDef fixtureDef;
    fixtureDef.filter.categoryBits = TILE;
    fixtureDef.filter.maskBits = DEFAULT | PROTAG;
    fixtureDef.density = 0.0f;
    b2Fixture* fixture;
    unsigned int nx_dest, ny_dest;
    int modifier_x = 0; int modifier_y = 0;
    int space_x = 0; int space_y = 0;
    int i = 0;
    int tile_left = 129;
    int tile_right = 159;
    int tile_middle = 158;
    int tile_ladder = 102;
    int tile_ladder_up = 103;
    //bool horizontal = false;
    
    //if( abs(x_start - x_dest) >= abs(y_start - y_dest) )
    //    horizontal = true;
        
    
    if(x_start < x_dest)
        modifier_x = (rand() % (SIZE_ROOM_X/2 -2) ) +2;
    if(x_start >= x_dest)
        modifier_x = -(rand() % (SIZE_ROOM_X/2 -2) ) -2;
    //if(y_start < y_dest)
    //    modifier_y = (rand() % (JUMP_HEIGHT_MAX-3) ) +2;;
    //if(y_start > y_dest)
    //    modifier_y = -(rand() % (JUMP_HEIGHT_MAX-3) ) -2;;

    if(modifier_x >= 0){
        tileLayer->setTile({x_start, y_start},tile_left);
        for(i = 1; i < modifier_x && i + x_start < room_x+SIZE_ROOM_X-2; i++)
            tileLayer->setTile({i + x_start, y_start},tile_middle);
        tileLayer->setTile({i-1 + x_start, y_start},tile_right);
        modifier_x = i;
        box.SetAsBox( (modifier_x*SIZE_OF_A_TILE)/2.0f, (SIZE_OF_A_TILE)/2.0f, b2Vec2((x_start)*SIZE_OF_A_TILE + (modifier_x/2.0f)*SIZE_OF_A_TILE, y_start*SIZE_OF_A_TILE+ SIZE_OF_A_TILE*0.4), 0);
    }
    else{
        tileLayer->setTile({x_start, y_start},tile_right);
        for(i = -1; i > modifier_x && i + x_start > room_x+2; i--)
            tileLayer->setTile({i + x_start, y_start},tile_middle);
        tileLayer->setTile({i+1 + x_start, y_start},tile_left);
        modifier_x = i;
        box.SetAsBox( (-modifier_x*SIZE_OF_A_TILE)/2.0f, (SIZE_OF_A_TILE)/2.0f, b2Vec2((x_start+1)*SIZE_OF_A_TILE + (modifier_x/2.0f)*SIZE_OF_A_TILE, y_start*SIZE_OF_A_TILE+ SIZE_OF_A_TILE*0.4), 0);
    }
    fixtureDef.shape = &box;
    fixture = tileBody->CreateFixture(&fixtureDef);
    fixture->SetUserData( (void*)UD_ONE_WAY_PLATFORM );
    
    if(ladder){
        tileLayer->setTile({x_start+modifier_x, y_start},tile_ladder_up);
        i = 1;
        while( tileLayer->getTile({x_start+modifier_x, y_start+i}) == -1
                && y_start+i < NUMBER_OF_TILES_Y ){
            tileLayer->setTile({x_start+modifier_x, y_start+i},tile_ladder);
            i++;
        }
        box.SetAsBox( (SIZE_OF_A_TILE)/2.0f, (SIZE_OF_A_TILE*(i-1))/2.0f,
                      b2Vec2((x_start+modifier_x)*SIZE_OF_A_TILE + SIZE_OF_A_TILE/2.0f, y_start*SIZE_OF_A_TILE+ ((i-1)/2.0f)*SIZE_OF_A_TILE), 0);
        
        fixtureDef.filter.categoryBits = LADDER;
        fixtureDef.isSensor = true;
        fixtureDef.shape = &box;
        fixture = tileBody->CreateFixture(&fixtureDef);
        fixture->SetUserData( (void*)UD_LADDER );
    }
    

    nx_dest = x_start + modifier_x;
    ny_dest = y_start + modifier_y;
    
    //printf("%i\n", abs(nx_dest-x_dest)*abs(ny_dest-y_dest));
    if( abs(nx_dest-x_dest)+abs(ny_dest-y_dest) < JUMP_DISTANCE_MAX &&
        abs(nx_dest-x_dest) < JUMP_WIDTH_MAX && abs(ny_dest-y_dest) < JUMP_HEIGHT_MAX )
            return gf::Vector2f(x_dest, y_dest);
    
    if(nx_dest <= x_dest)
        space_x = (rand() % (JUMP_WIDTH_MAX-2)) +2;
    if(nx_dest > x_dest)
        space_x = - (rand() % (JUMP_WIDTH_MAX-2)) -2;
    if(ny_dest <= y_dest)
        space_y = (rand() % (JUMP_HEIGHT_MAX-3))+3;
    if(ny_dest > y_dest)
        space_y = - (rand() % (JUMP_HEIGHT_MAX-3))-3;
    
    while( abs(space_x)+abs(space_y) > JUMP_DISTANCE_MAX){
        if(space_x>1)
            space_x--;
        else if(space_x<-1)
            space_x++;
        if(space_y>3)
            space_y--;
        else if(space_y<-3)
            space_y++;
        if( space_x <= 1 && space_x >= -1 && space_y <=3 && space_y >= -3 )
            break;
    }
    

    nx_dest += space_x;
    ny_dest += space_y;
    
    //printf("%i %i space: %i %i \n", modifier_x, modifier_y, space_x, space_y);
    if( (x_start >= x_dest && x_dest >= nx_dest) || (x_start <= x_dest && x_dest <= nx_dest) )
        if( (y_start >= y_dest && y_dest >= ny_dest) || (y_start <= y_dest && y_dest <= ny_dest) )
            return gf::Vector2f(x_dest, y_dest);
    
    return gf::Vector2f(nx_dest, ny_dest);
    
    //71
}

float Level::getdt(){
    return dt;
}

void Level::update(GameObject& obj){
    obj.update();
}

void Level::updateGameObjects(float ndt){
    dt = ndt;
    gf::Vector2f position;
    background.setPosition(graphicsG->getViewCenter());
    graphicsG->draw(&background); //rendu du fond en 1er pour qu'il soit au fond
    graphicsG->draw(tileLayer);                 //puis des tuiles
    unsigned int i;
    for(i = 0; i < nb_objects /*listGameObjects.size()*/; i++)
        //update( listGameObjects.at(i) );            //mise à jour des GameObjects
        update( *listGameObjects[i] );
}

void Level::addGameObject(GameObject *obj){
    obj->initialize(*this, *graphicsG);
    listGameObjects[nb_objects] = obj;
    //listGameObjects.push_back(*obj);
    nb_objects++;
}

gf::Window* Level::getWindow(){
    return graphicsG->m_window;
}


