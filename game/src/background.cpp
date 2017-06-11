#include "background.hpp"

Background::Background(std::string objectName, double positionX, double positionY,
                                     int width, int height) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){
    animator = new Animation(objectName, 1, 1, 1);
    animator->setTotalTime(0.3);

}

Background::~Background(){}

void Background::update(double timeElapsed){
    // To Do: Use Time Elapsed in inc.
    move(timeElapsed);
    animator->update();
}

void Background::move(double timeElapsed){
    auto inc = 0.05*timeElapsed;
    if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_UP)){
        setPositionY(getPositionY()+inc);
    }
    if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_RIGHT)){
        // animator->setInterval("right");
        inc = inc * (0-1);
        setPositionX(getPositionX()+inc);
    }else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_LEFT)){
        setPositionX(getPositionX()+inc);
    }
}


void Background::draw(){
    INFO("Background DRAW");
    animator->draw_instant(getPositionX(), getPositionY());
}
