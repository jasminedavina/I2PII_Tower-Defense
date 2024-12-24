#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "MachineGunBullet.hpp"
#include "Group.hpp"
#include "Shifter.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ExplosionEffectNew.hpp"

const int Shifter::Price = 0;
Shifter::Shifter(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/dirty-1.png","play/shifter.png", x, y, 0, Price, 1.5) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}

void Shifter::CreateBullet(){}

int Shifter::id() {
    return 4;
}
