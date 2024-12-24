#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "MachineGunBullet.hpp"
#include "Group.hpp"
#include "Shovel.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ExplosionEffectNew.hpp"

const int Shovel::Price = 0;
Shovel::Shovel(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/dirty-1.png","play/shovel.png", x, y, 0, Price, 1.5) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}

void Shovel::CreateBullet(){}

int Shovel::id() {
    return 3;
}
