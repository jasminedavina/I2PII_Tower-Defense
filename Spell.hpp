#ifndef SPELL_HPP
#define SPELL_HPP
#include "Turret.hpp"

class Spell : public Turret {
public:
    bool spell;
    Turret* temp;
    float save;
    float time = 0;
    static const int Price;
    Spell(float x, float y);
    void CreateBullet() override;
    void spellef(Turret* turret,float timee);
    void Update(float deltaTime)override;
    int id();
};
#endif // MachineGunTurret_HPP
