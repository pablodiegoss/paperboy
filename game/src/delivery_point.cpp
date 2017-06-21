#include "delivery_point.hpp"
#include "log.h"

DeliveryPoint::DeliveryPoint(std::string objectName, double positionX, double positionY,
                                     int width, int height) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){
animator = new Animation(objectName, 1, 1, 0.5);
animator->setDrawSize(0,0);
}

DeliveryPoint::~DeliveryPoint(){}
void DeliveryPoint::update(double timeElapsed){
    timeElapsed = timeElapsed;
    animator->update();
}

void DeliveryPoint::draw(){
    animator->draw(getPositionX(), getPositionY());
    animator->draw_collider(getPositionX(), getPositionY(), getWidth(), getHeight());
}
