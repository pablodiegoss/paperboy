#ifndef NEWSPAPER_HPP
#define NEWSPAPER_HPP

#include "game_object.hpp"
#include "animation.hpp"
#include "game_object.hpp"
#include "collision_manager.hpp"

using namespace engine;

class Newspaper : public GameObject{
public:
    Newspaper(std::string objectName, double positionX, double positionY, int width, int height);
    ~Newspaper();
    void update(double timeElapsed);
    void draw();
    void init();
    bool isLost();
    bool isDelivered();
private:
    void move(double timeElapsed);
    Animation* animator;
    bool lost;
    bool delivered;
};
#endif
