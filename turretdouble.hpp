#ifndef TURRETDOUBLE_HPP
#define TURRETDOUBLE_HPP
#include "Turret.hpp"

class turretdouble : public Turret {
public:
    static const int Price;
    turretdouble(float x, float y);
    void CreateBullet() override;
    int id();
};
#endif // MachineGunTurret_HPP
