#include "background.hpp"

Background::Background(std::string objectName, double positionX, double positionY,
                                     int width, int height) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){
    animator = new Animation(objectName, 1, 1, 1);
    animator->setTotalTime(0.3);

    Wall* teste = new Wall("assets/sprites/parede2.png", 100, 50, 60, 60);
    gameObjectsList.push_back(teste);

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
}

void Background::move(double timeElapsed){
    auto inc = 0.09*timeElapsed;
    moveEverythingY(inc);
    moveEverythingX(-inc);

    if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_RIGHT)){
        // animator->setInterval("right");
        inc = inc * (0-1);
        moveEverythingX(inc);
    }else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_LEFT)){
        moveEverythingX(inc*2);
    }
}

void Background::moveEverythingX(double inc){
    setPositionX(getPositionX()+inc);
    for(auto gameObject : gameObjectsList) {
        (*gameObject).setPositionX((*gameObject).getPositionX()+inc);
    }
}

void Background::moveEverythingY(double inc){
    setPositionY(getPositionY()+inc);
    for(auto gameObject : gameObjectsList) {
        (*gameObject).setPositionY((*gameObject).getPositionY()+inc);
    }
}
void Background::draw(){
    INFO("Background DRAW");
    animator->draw_instant(getPositionX(), getPositionY());
    for(auto gameObject : gameObjectsList) {
        (*gameObject).draw();
    }
}
