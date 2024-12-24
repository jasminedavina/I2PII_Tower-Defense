#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "MachineGunBullet.hpp"
#include "Group.hpp"
#include "Spell.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ExplosionEffectNew.hpp"
#include <iostream>
const int Spell::Price = 50;
Spell::Spell(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/dirty-1.png","play/spell.png", x, y, 0, Price, 1.5) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
    save = 0;
    temp = nullptr;
    this->spell = false;
    time = 0;
}

void Spell::CreateBullet(){}
void Spell::Update(float timer) {

    if (this->spell==true) {

        time -= timer;

        if (this->time <= 0 && spell) {
            spell = false;
            temp->coolDown = save;
            getPlayScene()->TowerGroup->RemoveObject(objectIterator);

        }
    }
}
void Spell::spellef(Turret* turret,float timer) {

    this->time = timer;
    temp = turret;
    this->save = turret->coolDown;
    turret->coolDown = 0.1;
    this->spell = true;
}
int Spell::id() {
    return 5;
}
