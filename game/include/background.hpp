#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "animation.hpp"
#include "game_object.hpp"
#include "input_manager.hpp"
#include "collision_manager.hpp"
#include "wall.hpp"

using namespace engine;

class Background: public GameObject{
public:
    Background(std::string objectName, double positionX, double positionY, int width, int height);
    ~Background();
    void update(double timeElapsed);
    void draw();
    void init();
private:
    void move(double timeElapsed);
    void moveEverythingX(double x);
    void moveEverythingY(double y);
    Animation* animator;
    std::vector<GameObject*> gameObjectsList;
};
#endif
