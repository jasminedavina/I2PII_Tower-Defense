#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "MachineGunBullet.hpp"
#include "Group.hpp"
#include "MachineGunTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ExplosionEffectNew.hpp"

const int MachineGunTurret::Price = 60;
MachineGunTurret::MachineGunTurret(float x, float y) :
    Turret("play/tower-base.png", "play/turret-1.png", x, y, 400, Price, 0.5) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
void MachineGunTurret::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new MachineGunBullet(Position + normalized * 36, diff, rotation, this));
    
    AudioHelper::PlayAudio("gun.wav"); 
    getPlayScene()->EffectGroup->AddNewObject(new ExplosionEffectNew(Position.x + normalized.x * 36, Position.y + normalized.y * 36));
}

int MachineGunTurret::id() {
    return 1;
}
