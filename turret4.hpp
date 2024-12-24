#ifndef TURRET4_HPP
#define TURRET4_HPP
#include "Turret.hpp"
#include "turret4bullet.hpp"

class turret4 : public Turret {
public:
    static const int Price;
    turret4(float x, float y);
    void CreateBullet() override;
    int id();
    virtual void Update(float time) override;
};
#endif // MachineGunTurret_HPP
