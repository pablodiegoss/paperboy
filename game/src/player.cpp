#include "player.hpp"

Player::Player(std::string objectName, double positionX, double positionY,
                                     int width, int height) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){
    animator = new Animation(objectName, 3, 6, 0.5);
    animator->setTotalTime(1);
    animator->setDrawSize(136,120);
    shooting = false;
    dead = false;
    animator->addAction("up",0,3);
    animator->addAction("right",4,7);
    animator->addAction("left",8,11);
    animator->addAction("die",12,16);
    shootingTimer = new Timer();
    deathTimer = new Timer();
    shootingTimer->start();
}

Player::~Player(){}

void Player::update(double timeElapsed){
    // To Do: Use Time Elapsed in inc.
    if(!dead){
        walk(timeElapsed);
        shoot();
    }else{
        if(deathTimer->elapsed_time() > 3000){
            setEnabled(false);
        }
    }
    animator->update();
}

void Player::walk(double timeElapsed){
    auto inc = 0.10*timeElapsed;
    if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_RIGHT)){
        if(getPositionX() < 500){
        setPositionX(getPositionX()+inc);
        }
        animator->setInterval("right");
    }else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_LEFT)){
        if(getPositionX() > 400){
            inc = inc * (0-1);
            setPositionX(getPositionX()+inc);
        }
        animator->setInterval("left");
    }else{
        animator->setInterval("right");
    }
    if(CollisionManager::instance.verifyCollisionWithWalls(this) && isEnabled()){
        deathTimer->start();
        dead = true;
        animator->setTotalTime(1);
        animator->setInterval("die");
    }
}

void Player::shoot(){
    if(shooting){
        shooting = false;
    }
    if(shootingTimer->elapsed_time() > 2000){
        if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_SPACE)){
            shooting = true;
            // animator->setInterval("right");
            shootingTimer->step();
        }
    }
}

bool Player::isShooting(){
    return shooting;
}
bool Player::isDead(){
    return dead;
}
void Player::draw(){
    INFO("Player DRAW");
    animator->draw(getPositionX()-45, getPositionY()-50);
    animator->draw_collider(getPositionX(), getPositionY(), getWidth(), getHeight());
}
