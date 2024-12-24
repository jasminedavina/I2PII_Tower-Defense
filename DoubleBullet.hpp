#ifndef DOUBLEBULLET_HPP
#define DOUBLEBULLET_HPP
#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
    struct Point;
}  // namespace Engine

class DoubleBullet : public Bullet {
public:
    explicit DoubleBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
    void OnExplode(Enemy* enemy) override;
};
#endif
