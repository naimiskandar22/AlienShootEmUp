#include "AllHeaderFiles.h"

class EnemyBullet : public GameObject
{
	public:
		ENEMYBULLET_TYPE type;
		bool isAlive;
		int MovementPause;
		int MovementCount;
		
		EnemyBullet(ENEMYBULLET_TYPE type);
		
		void Update();
};
