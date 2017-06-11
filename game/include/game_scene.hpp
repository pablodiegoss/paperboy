#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP

#include "collision_manager.hpp"
#include "audio.hpp"

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
    std::vector<GameObject*> gameObjectsList;
};

#endif
