#ifndef ENEMYBOSS_HPP
#define ENEMYBOSS_HPP
#include "Enemy.hpp"

class EnemyBoss : public Enemy {
public:
    EnemyBoss(int x, int y, int flag);
    int flag;
    void OnExplode() override;
};
#endif
