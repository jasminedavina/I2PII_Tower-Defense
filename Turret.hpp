#ifndef TURRET_HPP
#define TURRET_HPP
#include <allegro5/base.h>
#include <list>
#include <string>

#include "Sprite.hpp"

class Enemy;
class PlayScene;

class Turret: public Engine::Sprite {
protected:
    int price;
    
    
    float reload = 0;
    float rotateRadian = 2 * ALLEGRO_PI;
    Sprite imgBase;
    std::list<Turret*>::iterator lockedTurretIterator;
    PlayScene* getPlayScene();
    // Reference: Design Patterns - Factory Method.
    virtual void CreateBullet() = 0;

public:
    float coolDown;

    bool Enabled = true;
    bool Preview = false;
    Enemy* Target = nullptr;
    Turret(std::string imgBase, std::string imgTurret, float x, float y, float radius, int price, float coolDown);
    virtual void Update(float deltaTime) override;
    void Draw() const override;
	int GetPrice() const;
    virtual void spellef(Turret* turret, float timee);

    virtual int id() = 0; 
    //pure virtual supaya base class nya ga usah bikin function di 
    //cpp nya soalnya di anaknya baru bikin jd tiap ada class baru ga usah override tp tetep harus declare di hpp nya
    int bulletCount;
};
#endif // TURRET_HPP
