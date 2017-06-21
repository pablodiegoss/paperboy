#include "win_scene.hpp"
#include "button.hpp"

#include <typeinfo>
#include <iostream>

using namespace engine;

WinScene::WinScene(int id) : Scene(id){
    selectButton = 1;
    background = new Sprite("assets/sprites/winner_screen.png");
    background->setDrawSize(960,600);
}

WinScene::~WinScene(){
}

void WinScene::draw(){
    background->draw(0,0);
    hud->draw(30,170);
}

void WinScene::update(double timeElapsed){
    timeElapsed = timeElapsed;
    selectAction();
}

void WinScene::load(){
    int points = CollisionManager::instance.getPoints();
    hud = new Text("Score: "+ std::to_string(points), "assets/fonts/font.ttf", 50, false, new Color(100,100,100,255), new Color(0,0,0,0));
}

void WinScene::selectAction(){
        if(InputManager::instance.isKeyTriggered(InputManager::KeyPress::KEY_PRESS_ENTER)) {
            getSceneManager()->loadScene(1);
        }
}

void WinScene::unload(){
        CollisionManager::instance.resetPoints();
}
