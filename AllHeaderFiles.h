//! include guard (make sure only include/defined once
#ifndef	_ALL_HEADER_FILES_H_
#define	_ALL_HEADER_FILES_H_

//! normal library/header
#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <time.h>

using namespace std;

#define BOUNDARY_LEFT 5
#define BOUNDARY_RIGHT 55
#define BOUNDARY_TOP 2
#define BOUNDARY_BOTTOM 30

#define ENEMY_SPAWN_DURATION 50
#define MAX_BULLET 30
#define MAX_ENEMY 5
#define HIGHEST_SPEED 20
#define LOWEST_SPEED 100

typedef enum{
        NORMAL,
        SWEEPER,
        STORMER,
        TOTAL_ENEMY_TYPE
} ENEMY_TYPE;

typedef enum{
	UPSHOT,
	RIGHTSHOT,
	LEFTSHOT,
	UPRIGHTSHOT,
	UPLEFTSHOT,
	DOWNRIGHTSHOT,
	DOWNLEFTSHOT,
	SSHOT1,
	SSHOT2,
	SSHOT3,
	SSHOT4,
	SSHOT5,
	SSHOT6,
	SSHOT7,
	SSHOT8
}ENEMYBULLET_TYPE;

typedef enum{
        STRAIGHT,
        DUAL,
        SPREAD1,
        SPREAD2,
		SPREAD3,
		SHIELD1,
		SHIELD2,
		SHIELD3,
		SHIELD4,
		CLUSTER1,
		CLUSTER2,
		CLUSTER3,
		CLUSTER4,
		CLUSTER5,
		CLUSTER6,
		CLUSTER7,
		CLUSTER8
} BULLET_TYPE;

typedef enum{
	HEALTH,
	SCORE,
	AMMO,
	TOTAL_PICKUP_TYPE
} PICKUP_TYPE;

//! externally declaring the class Enemy before the actual declaration
extern "C" class Enemy;

//! custom classes
#include "conio_yp.h"
#include "GameObject.h"
#include "Bullet.h"
#include "Player.h"
#include "EnemyBullet.h"
#include "Enemy.h"
#include "Pickup.h"

#endif
