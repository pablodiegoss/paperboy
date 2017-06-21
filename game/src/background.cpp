#include "background.hpp"

Background::Background(std::string objectName, double positionX, double positionY,
                                     int width, int height) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){
    animator = new Animation(objectName, 1, 1, 1);
    animator->setTotalTime(0.3);
    complete = false;
    int xArvore = 680;
    int yArvore = -610;

    Wall* arvore = new Wall("assets/sprites/parede2.png", xArvore, yArvore, 70, 115);
    Wall* lixeira = new Wall("assets/sprites/parede2.png", xArvore+150, yArvore+15, 50, 70);
    Wall* metadeConstrucao = new Wall("assets/sprites/parede2.png", xArvore-450, yArvore-155, 130, 420);
    Wall* metadeConstrucao2 = new Wall("assets/sprites/parede2.png", xArvore-280, yArvore-155, 168, 260);
    Wall* metadeConstrucao3 = new Wall("assets/sprites/parede2.png", xArvore-720, yArvore-30, 160, 370);
    Wall* metadeConstrucao4 = new Wall("assets/sprites/parede2.png", xArvore-720, yArvore-30, 100, 490);
    Wall* metadeConstrucao5 = new Wall("assets/sprites/parede2.png", xArvore-720, yArvore-30, 450, 150);

    Wall* casa1_1 = new Wall("assets/sprites/parede2.png", xArvore-226, yArvore-920, 570, 580);
    Wall* casa1_2 = new Wall("assets/sprites/parede2.png", xArvore-226, yArvore-920, 570+150, 580-30);
    Wall* casa1_3 = new Wall("assets/sprites/parede2.png", xArvore-226, yArvore-920, 570+200, 580-130);
    Wall* casa1_4 = new Wall("assets/sprites/parede2.png", xArvore-226, yArvore-920, 570+400, 580-280);
    Wall* casa1_5 = new Wall("assets/sprites/parede2.png", xArvore-226, yArvore-920, 570+550, 580-400);
    Wall* mulher = new Wall("assets/sprites/parede2.png", xArvore+492, yArvore-462, 120, 75);
    Wall* cortador = new Wall("assets/sprites/parede2.png", xArvore+1050, yArvore-1048, 85, 90);
    Wall* casa2_1 = new Wall("assets/sprites/parede2.png", xArvore+340, yArvore-1700, 760, 680);
    Wall* casa2_2 = new Wall("assets/sprites/parede2.png", xArvore+340, yArvore-1700, 830, 680-220);
    Wall* casa3_1 = new Wall("assets/sprites/parede2.png", xArvore+1150, yArvore-2560, 430, 830);
    Wall* casa3_2 = new Wall("assets/sprites/parede2.png", xArvore+1150, yArvore-2560, 430+200, 830-160);
    Wall* casa3_3 = new Wall("assets/sprites/parede2.png", xArvore+1150, yArvore-2560, 430+550, 830-260);
    Wall* casa3_4 = new Wall("assets/sprites/parede2.png", xArvore+1150, yArvore-2360, 430+789, 830-670);

    DeliveryPoint* tapeteCasa1 = new DeliveryPoint("assets/sprites/parede2.png", xArvore+476, yArvore-568, 110, 64);
    Wall* correioCasa1Wall = new Wall("assets/sprites/parede2.png", xArvore+774, yArvore-628, 44, 74);
    Wall* correioCasa3Wall = new Wall("assets/sprites/parede2.png", xArvore+2234, yArvore-2146, 44, 74);
    DeliveryPoint* correioCasa1Point = new DeliveryPoint("assets/sprites/parede2.png", xArvore+774, yArvore-628, 54, 74);
    DeliveryPoint* correioCasa3Point = new DeliveryPoint("assets/sprites/parede2.png", xArvore+2234, yArvore-2146, 54, 74);
    DeliveryPoint* tapeteCasa3 = new DeliveryPoint("assets/sprites/parede2.png", xArvore+2324, yArvore-2250, 110, 64);

    pointsList.push_back(tapeteCasa1);
    pointsList.push_back(tapeteCasa3);
    pointsList.push_back(correioCasa3Point);
    pointsList.push_back(correioCasa1Point);

    gameObjectsList.push_back(correioCasa3Wall);
    gameObjectsList.push_back(correioCasa1Wall);

    gameObjectsList.push_back(arvore);
    gameObjectsList.push_back(lixeira);
    gameObjectsList.push_back(mulher);
    gameObjectsList.push_back(metadeConstrucao);gameObjectsList.push_back(metadeConstrucao2);gameObjectsList.push_back(metadeConstrucao3);gameObjectsList.push_back(metadeConstrucao4);gameObjectsList.push_back(metadeConstrucao5);
    gameObjectsList.push_back(casa1_1);gameObjectsList.push_back(casa1_2);gameObjectsList.push_back(casa1_3);gameObjectsList.push_back(casa1_4);gameObjectsList.push_back(casa1_5);
    gameObjectsList.push_back(casa2_1);gameObjectsList.push_back(casa2_2);
    gameObjectsList.push_back(casa3_1);gameObjectsList.push_back(casa3_2);gameObjectsList.push_back(casa3_3);gameObjectsList.push_back(casa3_4);

    gameObjectsList.push_back(cortador);


    for(auto gameObject : pointsList) {
        CollisionManager::instance.addDeliveryPoint(gameObject);
    }

    for(auto gameObject : gameObjectsList) {
        CollisionManager::instance.addWall(gameObject);
    }
}

Background::~Background(){}

void Background::update(double timeElapsed){
    // To Do: Use Time Elapsed in inc.
    move(timeElapsed);
    animator->update();
    for(auto gameObject : gameObjectsList) {
        (*gameObject).update(timeElapsed);
    }

    for(auto gameObject : pointsList) {
        (*gameObject).update(timeElapsed);
    }
}

void Background::move(double timeElapsed){
    //auto inc = 0.09*timeElapsed;
    auto inc = 0.13*timeElapsed;
    moveEverythingY(inc);
    moveEverythingX(-inc);

    if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_RIGHT)){
        // animator->setInterval("right");
        inc = inc * (0-1);
        moveEverythingX(inc);
    }else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_LEFT)){
        moveEverythingX(inc*2);
    }

    if(complete == false && getPositionX()< -3130 && getPositionY() > -840){
        complete = true;
    }
}

void Background::moveEverythingX(double inc){
    setPositionX(getPositionX()+inc);
    for(auto gameObject : gameObjectsList) {
        (*gameObject).setPositionX((*gameObject).getPositionX()+inc);
    }
    for(auto gameObject : pointsList) {
        (*gameObject).setPositionX((*gameObject).getPositionX()+inc);
    }
}

void Background::moveEverythingY(double inc){
    setPositionY(getPositionY()+inc);
    for(auto gameObject : gameObjectsList) {
        (*gameObject).setPositionY((*gameObject).getPositionY()+inc);
    }
    for(auto gameObject : pointsList) {
        (*gameObject).setPositionY((*gameObject).getPositionY()+inc);
    }
}
void Background::draw(){
    INFO("Background DRAW");
    animator->draw_instant(getPositionX(), getPositionY());
    for(auto gameObject : gameObjectsList) {
        (*gameObject).draw();
    }
    for(auto gameObject : pointsList) {
        (*gameObject).draw();
    }
}

bool Background::isComplete(){
    return complete;
}
