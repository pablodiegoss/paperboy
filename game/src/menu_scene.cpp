#include "menu_scene.hpp"
#include "button.hpp"

#include <typeinfo>
#include <iostream>

using namespace engine;

MenuScene::MenuScene(int id) : Scene(id){
        background = new Sprite("assets/sprites/menu.png");
}

MenuScene::~MenuScene(){
}

void MenuScene::draw(){
        background->draw(0,0);
        for(auto gameObject : gameObjectsList) {
                (*gameObject.second).draw();
        }
}

void MenuScene::update(double timeElapsed){
        timeElapsed = timeElapsed;
        selectAction();
}

void MenuScene::selectAction(){
        if(InputManager::instance.isKeyTriggered(InputManager::KeyPress::KEY_PRESS_ENTER)) {
                getSceneManager()->loadScene(1);
        }
}

void MenuScene::load(){
}

void MenuScene::unload(){
}
