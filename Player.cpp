#include "AllHeaderFiles.h"

Player::Player() : GameObject()
{
	row = 3;
	column = 3;
	
	char tempCharArray[3][3] = 
	{
		{' ', '|', ' '},
		{'+', '#', '+'},
		{'*', ' ', '*'}	
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
	
	colour = YELLOW;
	x = 20;
	y = 20;
	
	health = 100;
	score = 0;
	ammo = 500;
	shootDelayTimer = 0;
	shootDelayDuration = 10;
	InvertXControl = false;
}
             
void Player::Update()
{
	shootDelayTimer++;
	
	if(GetAsyncKeyState('A'))
    {
    	if(InvertXControl == false)
    	{
			if(CheckLeftBoundary() == false)
	    	{
	    		MoveLeft();
			}
		}
		else
		{
			if(CheckRightBoundary() == false)
	    	{
	    		MoveRight();
			}
		}
    }
	if(GetAsyncKeyState('D'))
    {
    	if(InvertXControl == false)
    	{
			if(CheckRightBoundary() == false)
	    	{
	    		MoveRight();
			}
		}
		else
		{
			if(CheckLeftBoundary() == false)
	    	{
	    		MoveLeft();
			}
		}
    }
	if(GetAsyncKeyState('W'))
    {
    	if(CheckTopBoundary() == false)
    	{
    		MoveUp();
    		addSleep -= 0.1;
		}
    }
	if(GetAsyncKeyState('S'))
    {
    	if(CheckBottomBoundary() == false)
    	{
    		MoveDown();
    		addSleep += 0.2;
		}
    }
    
    if(GetAsyncKeyState(VK_SPACE))
    {
    	if(shootDelayTimer > shootDelayDuration)
    	{
    		Shoot();
			shootDelayTimer = 0;    		
		}
    }
    
    if(GetAsyncKeyState('1'))
    {
    	shootMode = 0;  		
    }
    
    if(GetAsyncKeyState('2'))
    {
    	if(score >= 200)
    	{
    		shootMode = 1; 
		} 		
    }
    
    if(GetAsyncKeyState('3'))
    {
    	if(score >= 450)
    	{
    		shootMode = 2; 
		} 		
    }
    
    if(GetAsyncKeyState('4'))
    {
    	if(score >= 750)
    	{
    		shootMode = 3; 
		} 		
    }
    
    if(GetAsyncKeyState('5'))
    {
    	if(score >= 1200)
    	{
    		shootMode = 4; 
		} 		
    }
    
    addSleep += 0.05;
    if(addSleep > lowestSpeed)
    {
    	addSleep = lowestSpeed;
	}
	else if(addSleep < highestSpeed)
	{
		addSleep = highestSpeed;
	}
    Draw();
    
    for(int i=0; i<bulletList.size(); i++)
    {
    	bulletList[i].Update();
    	
    	if(bulletList[i].type == SHIELD1)
		{
				bulletList[i].x = x-2;
				bulletList[i].y = y;
		}
		else if(bulletList[i].type == SHIELD2)
		{
				bulletList[i].x = x+4;
				bulletList[i].y = y;
		}
		else if(bulletList[i].type == SHIELD3)
		{
				bulletList[i].x = x;
				bulletList[i].y = y-1;
		}
		else if(bulletList[i].type == SHIELD4)
		{
				bulletList[i].x = x+2;
				bulletList[i].y = y-1;
		}
    	
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

void Player::Shoot()
{
	if(ammo > 0)
	{
		if(shootMode%5 == 0)
		{
			Bullet newBullet(STRAIGHT);
			newBullet.x = x;
			newBullet.y = y;
			ammo -= 1;
			bulletList.push_back(newBullet);
		}
		if(shootMode%5 == 1)
		{
			Bullet newBullet(DUAL);
			newBullet.x = x;
			newBullet.y = y;
			ammo -= 2;
			bulletList.push_back(newBullet);
		}
		if(shootMode%5 == 2)
		{
			Bullet newBullet1(SPREAD1);
			newBullet1.x = x;
			newBullet1.y = y;
			bulletList.push_back(newBullet1);
			
			Bullet newBullet2(SPREAD2);
			newBullet2.x = x;
			newBullet2.y = y;
			bulletList.push_back(newBullet2);
			
			Bullet newBullet3(SPREAD3);
			newBullet3.x = x;
			newBullet3.y = y;
			bulletList.push_back(newBullet3);
			
			ammo -= 3;
		}
		if(shootMode%5 == 3)
		{
			Bullet newBullet1(SHIELD1);
			newBullet1.x = x+1;
			newBullet1.y = y-1;
			bulletList.push_back(newBullet1);
			
			Bullet newBullet2(SHIELD2);
			newBullet2.x = x-1;
			newBullet2.y = y+1;
			bulletList.push_back(newBullet2);
			
			Bullet newBullet3(SHIELD3);
			newBullet3.x = x+column;
			newBullet3.y = y+1;
			bulletList.push_back(newBullet3);
			
			Bullet newBullet4(SHIELD4);
			newBullet4.x = x;
			newBullet4.y = y+1;
			bulletList.push_back(newBullet4);
			
			ammo -= 4;
		}
		if(shootMode%5 == 4)
		{
			Bullet newBullet(CLUSTER1);
			newBullet.x = x;
			newBullet.y = y;
			bulletList.push_back(newBullet);
			
			ammo -= 1;
		}
		
	}
}

void Player::BulletCluster()
{
	Bullet newBullet1(CLUSTER1);
	newBullet1.x = x;
	newBullet1.y = y;
	bulletList.push_back(newBullet1);
	
	Bullet newBullet2(CLUSTER2);
	newBullet2.x = x;
	newBullet2.y = y;
	bulletList.push_back(newBullet2);
	
	Bullet newBullet3(CLUSTER3);
	newBullet3.x = x;
	newBullet3.y = y;
	bulletList.push_back(newBullet3);
	
	Bullet newBullet4(CLUSTER4);
	newBullet4.x = x;
	newBullet4.y = y;
	bulletList.push_back(newBullet4);
	
	Bullet newBullet5(CLUSTER5);
	newBullet5.x = x;
	newBullet5.y = y;
	bulletList.push_back(newBullet5);
	
	Bullet newBullet6(CLUSTER6);
	newBullet6.x = x;
	newBullet6.y = y;
	bulletList.push_back(newBullet6);
	
	Bullet newBullet7(CLUSTER7);
	newBullet7.x = x;
	newBullet7.y = y;
	bulletList.push_back(newBullet7);
	
	Bullet newBullet8(CLUSTER8);
	newBullet8.x = x;
	newBullet8.y = y;
	bulletList.push_back(newBullet8);
}
