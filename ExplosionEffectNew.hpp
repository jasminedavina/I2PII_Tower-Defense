#ifndef EXPLOSIONEFFECTNEW_HPP
#define EXPLOSIONEFFECTNEW_HPP
#include <allegro5/bitmap.h>
#include <memory>
#include <vector>

#include "Sprite.hpp"

class PlayScene;

class ExplosionEffectNew : public Engine::Sprite {
protected:
	PlayScene* getPlayScene();
	float timeTicks;
	std::vector<std::shared_ptr<ALLEGRO_BITMAP>> bmps;
	float timeSpan = 0.5;
public:
	ExplosionEffectNew(float x, float y);
	void Update(float deltaTime) override;
};
#endif
