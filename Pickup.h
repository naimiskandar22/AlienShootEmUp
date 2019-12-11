#include "AllHeaderFiles.h"

class Pickup : public GameObject
{
	public:
		PICKUP_TYPE type;
		bool isAlive;
		
		Pickup(PICKUP_TYPE type);
		
		void Update();
};
