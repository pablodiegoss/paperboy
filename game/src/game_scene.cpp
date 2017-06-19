#include "game_scene.hpp"

using namespace engine;

GameScene::GameScene(int id) : Scene(id){

}

GameScene::~GameScene(){}

void GameScene::draw(){
    for(auto gameObject : gameObjectsList) {
        (*gameObject).draw();
    }
    hud->draw(100,10);
}

void GameScene::update(double timeElapsed){
    for(auto gameObject : gameObjectsList) {
        (*gameObject).update(timeElapsed);
    }

    for(auto gameObject : gameObjectsList) {
        if(typeid(*gameObject) == typeid(Player)){
            Player* player = ((Player*)(gameObject));
            if(player->isShooting()){
                Newspaper* newspaper = new Newspaper("assets/sprites/newspaper.png", player->getPositionX(),player->getPositionY(), 10,10);
                gameObjectsList.push_back(newspaper);
            }
        }
    }

    cleanObjects();
    verifyWinOrLose();
}

void GameScene::cleanObjects(){
    int i = 0;
    for(auto gameObject : gameObjectsList) {
        if(!gameObject->isEnabled()){
            gameObjectsList.erase(gameObjectsList.begin()+i);
        }
        i++;
    }
}
void GameScene::verifyWinOrLose(){
}


void GameScene::load(){
    Player* player = new Player("assets/sprites/paperboy2.png", 400, 500, 40,60);
    Background* background = new Background("assets/sprites/background.png", 0,-4200, 4000,5000);
    hud = new Text("Score", "assets/fonts/font.ttf", 30, false, new Color(100,100,100,255), new Color(0,0,0,0));

    gameObjectsList.push_back(player);
    gameObjectsList.push_back(background);

}
void GameScene::unload(){
    CollisionManager::instance.resetLists();
    gameObjectsList.clear();
}
