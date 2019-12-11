
#ifndef	_PLAYER_H_
#define	_PLAYER_H_

#include "AllHeaderFiles.h"

using namespace std;

class Player : public GameObject
{
public :
	
	int health;
	int score;
	int ammo;
	int shootDelayTimer;
	int shootDelayDuration;
	int shootMode = 0;
	double addSleep = 1;
	double highestSpeed = 0.25;
	double lowestSpeed = 1.25;
	bool InvertXControl;
	
	
	vector<Bullet> bulletList;
	
	Player();
	
	void Update();
	
	void Shoot();
	
	void BulletCluster();
};

#endif
