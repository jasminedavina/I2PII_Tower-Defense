#include <string>

#include "EnemyBoss.hpp"
#include "EnemyChild.hpp"
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

EnemyBoss::EnemyBoss(int x, int y, int flag) : Enemy("play/enemy-6.png", x, y, 25, 50, 12, 15) {
    this->flag = flag;
}

void EnemyBoss::OnExplode() {
	
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> distId(1, 3);
	std::uniform_int_distribution<std::mt19937::result_type> dist(1, 20);
	for (int i = 0; i < 10; i++) {
		// Random add 10 dirty effects.
		getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-" + std::to_string(distId(rng)) + ".png", dist(rng), Position.x, Position.y));
	}

	for (int i = 0; i < 5; i++) {
		Enemy* enemy = (new EnemyChild(Position.x + (i+1)*64, Position.y));
		getPlayScene()->EnemyGroup->AddNewObject(enemy);
		auto MapDistance = getPlayScene()->CalculateBFSDistance();
		enemy->UpdatePath(MapDistance);
		getPlayScene()->EarnMoney(money);
	}
}


