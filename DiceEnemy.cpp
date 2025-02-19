#include <string>

#include "DiceEnemy.hpp"
#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <cmath>
#include <random>
#include <string>
#include <vector>

#include "AudioHelper.hpp"
#include "Bullet.hpp"
#include "DirtyEffect.hpp"
#include "Enemy.hpp"
#include "ExplosionEffect.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IScene.hpp"
#include "LOG.hpp"
#include "PlayScene.hpp"
#include "Turret.hpp"

DiceEnemy::DiceEnemy(int x, int y, int flag) : Enemy("play/dice-"+std::to_string(flag)+".png", x, y, 25, 30, 10, 10) {
    this->flag = flag;
}

void DiceEnemy::OnExplode() {
	
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> distId(1, 3);
	std::uniform_int_distribution<std::mt19937::result_type> dist(1, 20);
	for (int i = 0; i < 10; i++) {
		// Random add 10 dirty effects.
		getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-" + std::to_string(distId(rng)) + ".png", dist(rng), Position.x, Position.y));
	}

	if (this->flag > 1) {
		flag--;
		Enemy* enemy = (new DiceEnemy(Position.x, Position.y, flag));
		getPlayScene()->EnemyGroup->AddNewObject(enemy);
		auto MapDistance = getPlayScene()->CalculateBFSDistance();
		enemy->UpdatePath(MapDistance);
	}
	else{
		getPlayScene()->EarnMoney(money);
	}


}


