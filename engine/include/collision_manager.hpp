#ifndef COLLISION_MANAGER_HPP
#define COLLISION_MANAGER_HPP

#include <vector>
#include "engine.hpp"
#include "game_object.hpp"

using namespace engine;

class CollisionManager{
public:
    bool verifyCollisionWithWalls(GameObject* g);
    bool verifyCollision(GameObject* g1, GameObject* g2);
    bool verifyNewspaperCollisionWithWalls(GameObject* g);
    bool verifyCollisionWithDeliveryPoint(GameObject* g);
    void addWall(GameObject* g);
    void addDeliveryPoint(GameObject* g);
    void resetLists();
    static CollisionManager instance;
    int getPoints();
    void addPoints(int inc);
    void resetPoints();
private:
    std::vector<GameObject*> wallList;
    std::vector<GameObject*> deliveryPoints;
    int points;
};

#endif
