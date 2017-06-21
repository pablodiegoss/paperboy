#include "lose_scene.hpp"
#include "button.hpp"

#include <typeinfo>
#include <iostream>

using namespace engine;

LoseScene::LoseScene(int id) : Scene(id){
    selectButton = 1;
    background = new Sprite("assets/sprites/loser_screen.png");
    }

LoseScene::~LoseScene(){
}

void LoseScene::draw(){
    background->draw(0,0);
    hud->draw(400,175);
}

void LoseScene::update(double timeElapsed){
    timeElapsed = timeElapsed;
    selectAction();
}

void LoseScene::load(){
    int points = CollisionManager::instance.getPoints();
    hud = new Text("Score: "+ std::to_string(points), "assets/fonts/font.ttf", 50, false, new Color(100,100,100,255), new Color(0,0,0,0));
}

void LoseScene::selectAction(){
        if(InputManager::instance.isKeyTriggered(InputManager::KeyPress::KEY_PRESS_ENTER)) {
            getSceneManager()->loadScene(1);
        }
}

void LoseScene::unload(){
}
