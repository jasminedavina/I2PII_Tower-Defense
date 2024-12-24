#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "turret4.hpp"
#include "turret4Bullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ExplosionEffectNew.hpp"
#include "MachineGunBullet.hpp"

const int turret4::Price = 80;
turret4::turret4(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/turret4.png", x, y, 200, Price, 1.5) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
    bulletCount = 0;
}
void turret4::CreateBullet() {}

void turret4::Update(float time) {
    Sprite::Update(time);
    PlayScene* scene = getPlayScene();
    imgBase.Position = Position;
    imgBase.Tint = Tint;
    if (!Enabled == 1) {
        bulletCount = 0;
        return;
    }

    if (!Enabled) {
        return;
    }
    if (bulletCount == 0) {
        bulletCount += 4;
    }
    else {
        return;
    }

    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotate = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    for (int n = 0; n < 4; n++) {
        auto make = new turret4Bullet(Engine::Point(Position.x + cos(ALLEGRO_PI * n / 2) * CollisionRadius, Position.y + sin(ALLEGRO_PI * n / 2) * CollisionRadius), diff, rotate, this);
        getPlayScene()->BulletGroup->AddNewObject(make);
    }
    
    AudioHelper::PlayAudio("gun.wav");
}

int turret4::id() {
    return 2;
}
