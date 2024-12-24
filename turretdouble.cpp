#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "turretdouble.hpp"
#include "Group.hpp"
#include "turretdouble.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ExplosionEffectNew.hpp"
#include "DoubleBullet.hpp"

const int turretdouble::Price = 160;
turretdouble::turretdouble(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/turret-2.png", x, y, 200, Price, 1.5) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
void turretdouble::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    Engine::Point dua = Engine::Point(25, 0);
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new DoubleBullet(Position + normalized * 36, diff, rotation, this));
    getPlayScene()->EffectGroup->AddNewObject(new ExplosionEffectNew(Position.x + normalized.x * 36, Position.y + normalized.y * 36));

    getPlayScene()->BulletGroup->AddNewObject(new DoubleBullet(Position + dua + normalized * 36 , diff, rotation, this));
    getPlayScene()->EffectGroup->AddNewObject(new ExplosionEffectNew(Position.x + normalized.x * 36, Position.y + normalized.y * 36));

    AudioHelper::PlayAudio("gun.wav");
}

int turretdouble::id() {
    return -1;
}