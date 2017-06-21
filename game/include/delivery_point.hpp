#ifndef DELIVERY_POINT_HPP
#define DELIVERY_POINT_HPP

#include "engine.hpp"
#include "animation.hpp"
#include "game_object.hpp"

using namespace engine;

class DeliveryPoint: public GameObject{
public:
    DeliveryPoint(std::string objectName, double positionX, double positionY, int width, int height);
    ~DeliveryPoint();
    void update(double timeElapsed);
    void draw();
    void init();
    Animation * getAnimation();
private:
    Animation* animator;
};
#endif
