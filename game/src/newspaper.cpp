#include "newspaper.hpp"

Newspaper::Newspaper(std::string objectName, double positionX, double positionY,
                                     int width, int height) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){
    animator = new Animation(objectName, 1, 4, 0.1);
    animator->setTotalTime(0.1);
    animator->addAction("roll", 0,3);
    animator->setInterval("roll");
    lost = false;
    delivered = false;
}

Newspaper::~Newspaper(){}

void Newspaper::update(double timeElapsed){
    // To Do: Use Time Elapsed in inc.
    move(timeElapsed);
    if(getPositionX()< -50 || CollisionManager::instance.verifyNewspaperCollisionWithWalls(this)){
        lost = true;
        setEnabled(false);
        CollisionManager::instance.addPoints(-100);
    }
    if(CollisionManager::instance.verifyCollisionWithDeliveryPoint(this)){
        delivered = true;
        setEnabled(false);
        CollisionManager::instance.addPoints(200);
    }
    animator->update();
}

void Newspaper::move(double timeElapsed){
    auto inc = 0.45*timeElapsed;
    setPositionX(getPositionX()-inc);
}


void Newspaper::draw(){
    INFO("Newspaper DRAW");
    animator->draw(getPositionX(), getPositionY());
}
