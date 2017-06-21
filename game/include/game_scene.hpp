#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP

#include "collision_manager.hpp"
#include "audio.hpp"
#include "player.hpp"
#include "background.hpp"
#include "newspaper.hpp"
#include "text.hpp"
#include "log.h"
#include <typeinfo>
#include <vector>
using namespace engine;

class GameScene: public Scene{
public:
    GameScene(int id);
    ~GameScene();
    void load();
    void draw();
    void update(double timeElapsed);
    void unload();
    void verifyWinOrLose();
private:
    void cleanObjects();
    std::vector<GameObject*> gameObjectsList;
    Player* player;
    Text* hud;
};

#endif
