#include "game_scene.hpp"

using namespace engine;

GameScene::GameScene(int id) : Scene(id){

}

GameScene::~GameScene(){}

void GameScene::draw(){
    for(auto gameObject : gameObjectsList) {
        (*gameObject).draw();
    }
}

void GameScene::update(double timeElapsed){
    for(auto gameObject : gameObjectsList) {
        (*gameObject).update(timeElapsed);
    }
    verifyWinOrLose();
}

void GameScene::verifyWinOrLose(){
}


void GameScene::load(){

}
void GameScene::unload(){
    CollisionManager::instance.resetLists();
    gameObjectsList.clear();
}
