#ifndef DiceEnemy_HPP
#define DiceEnemy_HPP
#include "Enemy.hpp"

class DiceEnemy : public Enemy {
public:
    DiceEnemy(int x, int y, int flag);
    int flag;
    void OnExplode() override;
};
#endif
