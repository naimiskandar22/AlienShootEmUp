#include "AllHeaderFiles.h"

Enemy::Enemy(ENEMY_TYPE enemyType) : GameObject()
{
	if(enemyType == NORMAL)
	{
		row = 3;
		column = 3;
		
		char tempCharArray[3][3] = 
		{
			{'.', '!', '.'},
			{'=', '*', '='},
			{' ', '|', ' '}	
		};
		
		charArray = new char*[row];
		for(int i=0; i<row; i++)
		{
			charArray[i] = new char[column];
			for(int j=0; j<column; j++)
			{
				charArray[i][j] = tempCharArray[i][j];
			}
		}
		
		colour = LIGHTRED;
		x = 20;
		y = 10;
		health = 30;
		updateDelayDuration = 0;
	}
	else if(enemyType == SWEEPER)
	{
		row = 3;
		column = 3;
		shootDelayTimer = 0;
		shootDelayDuration = 5;
		shootDirection = 1;
		
		char tempCharArray[5][5] = 
		{
			{'.', ' ', '.'},
			{'\\', '_', '/'},
			{' ', '|', ' '}
		};
		
		charArray = new char*[row];
		for(int i=0; i<row; i++)
		{
			charArray[i] = new char[column];
			for(int j=0; j<column; j++)
			{
				charArray[i][j] = tempCharArray[i][j];
			}
		}
		
		colour = LIGHTMAGENTA;
		x = 20;
		y = 10;
		health = 10;
		updateDelayDuration = 5;
	}
	else if(enemyType == STORMER)
	{
		row = 5;
		column = 5;
		shootDelayTimer = 0;
		shootDelayDuration = 20;
		
		char tempCharArray[5][5] = 
		{
			{' ', '/', '-', '\\',' '},
			{'[', '|', '*', '|', ']'},
			{' ', '|', 'Y', '|', ' '},
			{'[', '|', '!', '|', ']'},
			{' ', '*', '_', '*', ' '}
		};
		
		charArray = new char*[row];
		for(int i=0; i<row; i++)
		{
			charArray[i] = new char[column];
			for(int j=0; j<column; j++)
			{
				charArray[i][j] = tempCharArray[i][j];
			}
		}
		
		colour = WHITE;
		x = 20;
		y = 10;
		health = 100;
		updateDelayDuration = 3;
	}
	
	updateDelayTimer = 0;
	this->enemyType = enemyType;
	isAlive = true;
}

void Enemy::Shoot()
{
	EnemyBullet newBullet(UPSHOT);
	newBullet.x = x+2;
	newBullet.y = y;
	bulletList.push_back(newBullet);
}

void Enemy::ShootFollow(int PosX, int PosY)
{
	if(enemyType == STORMER)
	{
		if(shootDelayTimer > shootDelayDuration)
		{
			Shoot();
			if(PosX > x && PosY > y)
			{
				EnemyBullet newBullet(DOWNRIGHTSHOT);
				newBullet.x = x;
				newBullet.y = y;
				bulletList.push_back(newBullet);
			}
			else if(PosX > x && PosY == y)
			{
				EnemyBullet newBullet(RIGHTSHOT);
				newBullet.x = x;
				newBullet.y = y;
				bulletList.push_back(newBullet);
			}
			else if(PosX > x && PosY < y)
			{
				EnemyBullet newBullet(UPRIGHTSHOT);
				newBullet.x = x;
				newBullet.y = y;
				bulletList.push_back(newBullet);
			}
			else if(PosX < x && PosY > y)
			{
				EnemyBullet newBullet(DOWNLEFTSHOT);
				newBullet.x = x;
				newBullet.y = y;
				bulletList.push_back(newBullet);
			}
			else if(PosX < x && PosY == y)
			{
				EnemyBullet newBullet(LEFTSHOT);
				newBullet.x = x;
				newBullet.y = y;
				bulletList.push_back(newBullet);
			}
			else if(PosX < x && PosY < y)
			{
				EnemyBullet newBullet(UPLEFTSHOT);
				newBullet.x = x;
				newBullet.y = y;
				bulletList.push_back(newBullet);
			}
			shootDelayTimer = 0;
		}
	}
	else if(enemyType == SWEEPER)
	{
		if(shootDelayTimer > shootDelayDuration)
		{
			if(shootDirection == 1)
			{
				EnemyBullet newBullet(SSHOT1);
				newBullet.x = x;
				newBullet.y = y;
				bulletList.push_back(newBullet);
			}
			else if(shootDirection == 2)
			{
				EnemyBullet newBullet(SSHOT2);
				newBullet.x = x;
				newBullet.y = y;
				bulletList.push_back(newBullet);
			}
			else if(shootDirection == 3)
			{
				EnemyBullet newBullet(SSHOT3);
				newBullet.x = x;
				newBullet.y = y;
				bulletList.push_back(newBullet);
			}
			else if(shootDirection == 4)
			{
				EnemyBullet newBullet(SSHOT4);
				newBullet.x = x;
				newBullet.y = y;
				bulletList.push_back(newBullet);
			}
			else if(shootDirection == 5)
			{
				EnemyBullet newBullet(SSHOT5);
				newBullet.x = x;
				newBullet.y = y;
				bulletList.push_back(newBullet);
			}
			else if(shootDirection == 6)
			{
				EnemyBullet newBullet(SSHOT6);
				newBullet.x = x;
				newBullet.y = y;
				bulletList.push_back(newBullet);
			}
			else if(shootDirection == 7)
			{
				EnemyBullet newBullet(SSHOT7);
				newBullet.x = x;
				newBullet.y = y;
				bulletList.push_back(newBullet);
			}
			else if(shootDirection == 8)
			{
				EnemyBullet newBullet(SSHOT8);
				newBullet.x = x;
				newBullet.y = y;
				bulletList.push_back(newBullet);
				shootDirection = 0;
			}
			shootDirection++;
			shootDelayTimer = 0;
		}
	}
}

void Enemy::Update()
{
	updateDelayTimer++;
	shootDelayTimer++;
	
	if(health <= 0)
	{
		isAlive = false;
	}
	
	if(updateDelayTimer < updateDelayDuration)
	{
		return;
	}
	updateDelayTimer = 0;
	
	if(enemyType == STORMER)
	{
		if(CheckTopBoundary() == false)
		{
			MoveUp();
		}
		else
		{
			isAlive = false;
		}
	}
	else
	{
		if(CheckBottomBoundary() == false)
		{
			MoveDown();
		}
		else
		{
			isAlive = false;
		}
	}
	
	for(int i=0; i<bulletList.size(); i++)
    {
    	bulletList[i].Update();
    	
		if(bulletList[i].isAlive == false)
		{
			bulletList[i].DrawTrail();
			bulletList.erase(bulletList.begin() + i);			
		}
		else
		{
			bulletList[i].Draw();
		}
	}
}
