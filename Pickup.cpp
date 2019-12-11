#include "AllHeaderFiles.h"

Pickup::Pickup(PICKUP_TYPE type) : GameObject()
{
	if(type == HEALTH)
	{
		row = 1;
		column = 1;
		
		char tempCharArray[1][1] = 
		{
			{'+'}	
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
		
		colour = GREEN;
		x = 20;
		y = 15;
	}
	else if(type == AMMO)
	{
		row = 2;
		column = 1;
		
		char tempCharArray[2][1] = 
		{
			{'^'},
			{'|'}	
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
		y = 15;
	}
	else if(type == SCORE)
	{
		row = 1;
		column = 1;
		
		char tempCharArray[1][1] = 
		{
			{'$'}	
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
		
		colour = CYAN;
		x = 20;
		y = 15;
	}
	this->type = type;
	isAlive = true;
}

void Pickup::Update()
{
	
}
