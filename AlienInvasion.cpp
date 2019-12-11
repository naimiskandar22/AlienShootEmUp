#include "AllHeaderFiles.h"

int enemySpawnTimer = 0;
int sleepTime = LOWEST_SPEED;
int sweeperSpawn = 0;
bool GameOver = true;
vector<Pickup> pickupList;

void DrawBoundary()
{
    textcolor(WHITE);
    for(int i=BOUNDARY_LEFT; i<=BOUNDARY_RIGHT; i++)
    {
        gotoxy(i,BOUNDARY_TOP);
        cout <<"=";
        gotoxy(i,BOUNDARY_BOTTOM);
        cout <<"=";
    }
    for(int i=BOUNDARY_TOP + 1; i<BOUNDARY_BOTTOM; i++)
    {
        gotoxy(BOUNDARY_LEFT,i);
        cout <<"|";
        gotoxy(BOUNDARY_RIGHT,i);
        cout <<"|";
    }      
}

void DrawWeaponsMenu(Player& player)
{
	gotoxy((BOUNDARY_LEFT+BOUNDARY_RIGHT)*0.5, BOUNDARY_BOTTOM + 2);
	textcolor(LIGHTGREEN);
	cout << "PRESS [1] : STRAIGHT BULLET";
	gotoxy((BOUNDARY_LEFT+BOUNDARY_RIGHT)*0.5, BOUNDARY_BOTTOM + 3);
	if(player.score < 200)
	{
		textcolor(LIGHTRED);
	}
	else
	{
		textcolor(LIGHTGREEN);
	}
	cout << "PRESS [2] : DUAL SHOT";
	gotoxy((BOUNDARY_LEFT+BOUNDARY_RIGHT)*0.5, BOUNDARY_BOTTOM + 4);
	if(player.score < 450)
	{
		textcolor(LIGHTRED);
	}
	else
	{
		textcolor(LIGHTGREEN);
	}
	cout << "PRESS [3] : SPREAD SHOT";
	gotoxy((BOUNDARY_LEFT+BOUNDARY_RIGHT)*0.5, BOUNDARY_BOTTOM + 5);
	if(player.score < 750)
	{
		textcolor(LIGHTRED);
	}
	else
	{
		textcolor(LIGHTGREEN);
	}
	cout << "PRESS [4] : SHIELD";
	gotoxy((BOUNDARY_LEFT+BOUNDARY_RIGHT)*0.5, BOUNDARY_BOTTOM + 6);
	if(player.score < 1200)
	{
		textcolor(LIGHTRED);
	}
	else
	{
		textcolor(LIGHTGREEN);
	}
	cout << "PRESS [5] : CLUSTER SHOT";
}

void DrawHUD(Player& player)
{
	gotoxy(BOUNDARY_LEFT, BOUNDARY_BOTTOM + 2);
	textcolor(GREEN);
	cout << "Health :     " ;
	gotoxy(BOUNDARY_LEFT, BOUNDARY_BOTTOM + 2);
	cout << "Health : " << player.health;
	gotoxy(BOUNDARY_LEFT, BOUNDARY_BOTTOM + 3);
	textcolor(LIGHTGREEN);
	cout << "Ammo :      ";
	gotoxy(BOUNDARY_LEFT, BOUNDARY_BOTTOM + 3);
	cout << "Ammo : " << player.ammo;
	gotoxy(BOUNDARY_LEFT, BOUNDARY_BOTTOM + 4);
	textcolor(LIGHTBLUE);
	cout << "Score : " << player.score;
}

bool RectangleIntersect(int obj1_x, int obj1_y, int obj1_height, int obj1_width, int obj2_x, int obj2_y, int obj2_height, int obj2_width)
{
	if(obj1_x > obj2_x + obj2_width || 
		obj1_x + obj1_width < obj2_x || 
		obj1_y > obj2_y + obj2_height || 
		obj1_y + obj1_height < obj2_y)
	{
		return false;
	}
	return true;
}

void EnemyOverlappingCheck(Enemy& enemy, vector<Enemy>& enemyList)
{
	bool isOverlapping;
	do
	{
		isOverlapping = false;
		if(enemy.enemyType == STORMER)
		{
			enemy.x = rand()%(BOUNDARY_RIGHT - BOUNDARY_LEFT - enemy.column) + BOUNDARY_LEFT + 1;
			enemy.y = BOUNDARY_BOTTOM + 1 * rand()%10;
		}
		else
		{
			enemy.x = rand()%(BOUNDARY_RIGHT - BOUNDARY_LEFT - enemy.column) + BOUNDARY_LEFT + 1;
			enemy.y = -1 * rand()%10;
		}
		
		for(int i = 0; i < enemyList.size(); i++)
		{
			if(RectangleIntersect(enemy.x, enemy.y, 
			enemy.row, enemy.column, 
			enemyList[i].x, enemyList[i].y, 
			enemyList[i].row, enemyList[i].column))
			{
				isOverlapping = true;
				break;
			}
		}
		
	}while(isOverlapping);
}

void SpawnPickup(vector<Pickup>& pickupList, int PosX, int PosY)
{
	int randPickup = rand()%TOTAL_PICKUP_TYPE;
	Pickup newPickup((PICKUP_TYPE)randPickup);
	newPickup.x = PosX;
	newPickup.y = PosY;
	pickupList.push_back(newPickup);
}

void SpawnEnemy(vector<Enemy>& enemyList)
{
	enemySpawnTimer++;
	if(enemySpawnTimer > ENEMY_SPAWN_DURATION)
	{
		int numberOfEnemyToSpawn = rand()%MAX_ENEMY;
		
		for(int i=0; i<numberOfEnemyToSpawn; i++)
		{
			int randEnemyType = rand()%TOTAL_ENEMY_TYPE;
			if((ENEMY_TYPE)randEnemyType != SWEEPER)
			{
				Enemy newEnemy((ENEMY_TYPE)randEnemyType);
				EnemyOverlappingCheck(newEnemy, enemyList);
				enemyList.push_back(newEnemy);
			}
		}
		if(sweeperSpawn >= 60)
		{
			Enemy newEnemy(SWEEPER);
			EnemyOverlappingCheck(newEnemy,enemyList);
			enemyList.push_back(newEnemy);
			sweeperSpawn = 0;
		}
		enemySpawnTimer = 0;
	}
}

void CollisionCheck(Player& player, vector<Enemy>& enemyList, vector<Pickup>& pickupList)
{
	//! player vs enemy
	for(int i = 0; i < enemyList.size(); i++)
	{
		if(RectangleIntersect(player.x, player.y,
		 player.row, player.column, 
		 enemyList[i].x, enemyList[i].y, 
		 enemyList[i].row, enemyList[i].column))
		 {
		 	player.health -= 50;
		 	player.score += 10;
		 	enemyList[i].isAlive = false;
		 }
	}
	
	//!player and pickups
	for(int i = 0; i < pickupList.size(); i++)
	{
		if(RectangleIntersect(player.x, player.y,
		 player.row, player.column, 
		 pickupList[i].x, pickupList[i].y, 
		 pickupList[i].row, pickupList[i].column))
		 {
		 	if(pickupList[i].type == HEALTH)
		 	{
		 		player.health += 10;
			}
			else if(pickupList[i].type == AMMO)
			{
				player.ammo++;
			}
			else if(pickupList[i].type == SCORE)
			{
				player.score += 100;
			}
			
			pickupList[i].isAlive = false;
		 }
	}
}

void BulletCollisionCheck(Player& player, vector<Enemy>& enemyList)
{
	for(int i = 0; i < player.bulletList.size(); i++)
	{
		for(int j = 0; j < enemyList.size(); j++)
		{
			if(RectangleIntersect(player.bulletList[i].x, player.bulletList[i].y,
			 player.bulletList[i].row, player.bulletList[i].column, 
			 enemyList[j].x, enemyList[j].y, 
			 enemyList[j].row, enemyList[j].column))
			 {
			 	if(enemyList[j].enemyType == SWEEPER)
			 	{
			 		if(player.InvertXControl == false)
			 		{
			 			player.InvertXControl = true;
					}
					else
					{
						player.InvertXControl = false;
					}
				}
			 	if(player.bulletList[i].type == CLUSTER1)
			 	{
			 		player.BulletCluster();
				}
			 	player.score += 20;
			 	enemyList[j].health -= player.bulletList[i].damage;
			 	if(enemyList[j].health <= 0)
			 	{
			 		SpawnPickup(pickupList, enemyList[j].x, enemyList[j].y);
				}
			 	player.bulletList[i].isAlive = false;
			 }
		}
	}
	
	for(int i = 0; i < enemyList.size(); i++)
	{
		for(int j = 0; j < enemyList[i].bulletList.size(); j++)
		{
			if(RectangleIntersect(player.x, player.y,
		 	player.row, player.column, 
		 	enemyList[i].bulletList[j].x, enemyList[i].bulletList[j].y, 
		 	enemyList[i].bulletList[j].row, enemyList[i].bulletList[j].column))
		 	{
		 		if(enemyList[i].bulletList[j].type == SSHOT1 || enemyList[i].bulletList[j].type == SSHOT2 || enemyList[i].bulletList[j].type == SSHOT3 || 
				 enemyList[i].bulletList[j].type == SSHOT4 || enemyList[i].bulletList[j].type == SSHOT5 || enemyList[i].bulletList[j].type == SSHOT6 || 
				 enemyList[i].bulletList[j].type == SSHOT7 || enemyList[i].bulletList[j].type == SSHOT8)
				 {
				 	player.health += 10;
				 }
				 else
				 {
				 	player.health -= 10;
				 }
		 		enemyList[i].bulletList[j].isAlive = false;
			}
		}
	}
}

bool GameCheck(Player& player)
{
	if(player.health <= 0)
	{
		return false;
	}
	
	return true;
}

int main()
{
    //! it all begins here!!!    
    
    //! console window size    
    system("mode con: cols=58 lines=40");
    
    //! seed the random function with current system time
    srand( time(NULL) );
    
    DrawBoundary();
    
    hideCursor();

    char button;
    
    Player player;
    vector<Enemy> enemyList;
    
    do
	{
		player.Update();
		
		for(int i=0; i<enemyList.size(); i++)
		{
			enemyList[i].Update();
			if(enemyList[i].isAlive == false)
			{
				for(int j = 0; j < enemyList[i].bulletList.size(); j++)
				{
					enemyList[i].bulletList[j].isAlive = false;
					enemyList[i].bulletList[j].DrawTrail();
				}
				enemyList[i].DrawTrail();
				enemyList.erase(enemyList.begin() + i);
			}
			else
			{
				enemyList[i].Draw();
				enemyList[i].ShootFollow(player.x, player.y);
			}
		}
		
		for(int i = 0; i < pickupList.size(); i++)
		{
			if(pickupList[i].isAlive == false)
			{
				pickupList[i].DrawTrail();
				pickupList.erase(pickupList.begin() + i);
			}
			else
			{
				pickupList[i].Draw();
			}
		}
	    
		CollisionCheck(player, enemyList, pickupList);
		BulletCollisionCheck(player, enemyList); 
	    SpawnEnemy(enemyList);
	    DrawHUD(player);
	    DrawWeaponsMenu(player);
	    
		GameOver = GameCheck(player);
		     
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            button = 27;
        }
        
        Sleep(20);
        sweeperSpawn++;
    }while(button != 27 && GameOver);
    
    cout<<endl;
    gotoxy(1, BOUNDARY_BOTTOM + 8);
    system("PAUSE");
    return 0;
}
