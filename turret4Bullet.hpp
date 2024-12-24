#ifndef TURRET4BULLET_HPP
#define TURRET4BULLET_HPP
#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
    struct Point;
}  // namespace Engine

class turret4Bullet : public Bullet {
public:
    explicit turret4Bullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
    void OnExplode(Enemy* enemy) override;
    virtual void Update(float time) override;
};
#endif // WOODBULLET_HPP
