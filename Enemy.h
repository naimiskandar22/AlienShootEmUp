
#ifndef	_ENEMY_H_
#define	_ENEMY_H_

#include "AllHeaderFiles.h"

using namespace std;

class Enemy : public GameObject
{
public :
	
	ENEMY_TYPE enemyType;
	bool isAlive;
	int updateDelayTimer;
	int updateDelayDuration;
	int shootDelayTimer;
	int shootDelayDuration;
	int shootDirection;
	int health;
	
	Enemy(ENEMY_TYPE enemyType);
	
	vector<EnemyBullet> bulletList;
	
	void Update();
	
	void Shoot();
	void ShootFollow(int PosX, int PosY);
};

#endif
