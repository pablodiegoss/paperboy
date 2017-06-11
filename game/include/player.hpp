#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "input_manager.hpp"
#include "animation.hpp"
#include "game_object.hpp"
#include "collision_manager.hpp"
#include "timer.hpp"

using namespace engine;

class Player: public GameObject{
public:
    Player(std::string objectName, double positionX, double positionY, int width, int height);
    ~Player();
    void update(double timeElapsed);
    void draw();
    void init();
    bool isShooting();
private:
    void walk(double timeElapsed);
    void shoot();
    Animation* animator;
    bool shooting;
    Timer* shootingTimer;
};
#endif