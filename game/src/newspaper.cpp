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

}

Newspaper::~Newspaper(){}

void Newspaper::update(double timeElapsed){
    // To Do: Use Time Elapsed in inc.
    move(timeElapsed);
    if(getPositionX()< -50){
        setEnabled(false);
    }
    animator->update();
}

void Newspaper::move(double timeElapsed){
    auto inc = 0.25*timeElapsed;
    setPositionX(getPositionX()-inc);
}


void Newspaper::draw(){
    INFO("Newspaper DRAW");
    animator->draw(getPositionX(), getPositionY());
}
