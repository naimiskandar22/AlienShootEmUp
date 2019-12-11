#include "AllHeaderFiles.h"

class Bullet : public GameObject
{
public :
	
	BULLET_TYPE type;
	bool isAlive;
	
	Bullet(BULLET_TYPE type);
	int damage;
	
	void Update();
};
