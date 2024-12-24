#include <allegro5/base.h>
#include <random>
#include <string>

#include "Collider.hpp"
#include "DirtyEffect.hpp"
#include "Enemy.hpp"
#include "turret4Bullet.hpp"
#include "Turret.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"

class Turret;

turret4Bullet::turret4Bullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent) :
    Bullet("play/turret4-bullet.png", 300, 2, position, forwardDirection, rotation - ALLEGRO_PI / 2, parent) {
    // TODO 3 (2/5): You can imitate the 2 files: 'WoodBullet.hpp', 'WoodBullet.cpp' to create a new bullet.
}
void turret4Bullet::OnExplode(Enemy* enemy) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(2, 5);
    getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-2.png", dist(rng), enemy->Position.x, enemy->Position.y));
    parent->bulletCount--;
}

void turret4Bullet::Update(float time) {
    float radius = parent->CollisionRadius;
    float position_x = Position.x - parent->Position.x;
    float position_y = Position.y - parent->Position.y;
    float temp = atan(position_y / position_x);
    if (position_x < 0) {
        temp += ALLEGRO_PI;
    }
    
    if (parent->Enabled == false) {
        getPlayScene()->BulletGroup->RemoveObject(objectIterator);
        return;
    }

    temp += time;
    Position.x = radius * cos(temp) + parent->Position.x;
    Position.y = radius * sin(temp) + parent->Position.y;

    PlayScene* scene = getPlayScene();
    for (auto& i : scene->EnemyGroup->GetObjects()) {
        Enemy* enemy = dynamic_cast<Enemy*> (i);
        if (!enemy->Visible)
            continue;
        if (Engine::Collider::IsCircleOverlap(Position, CollisionRadius, enemy->Position, enemy->CollisionRadius)) {
            OnExplode(enemy);
            enemy->Hit(damage);
            getPlayScene()->BulletGroup->RemoveObject(objectIterator);
            return;
        }
    }
}