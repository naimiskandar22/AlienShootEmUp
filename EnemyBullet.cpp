#include "AllHeaderFiles.h"

EnemyBullet::EnemyBullet(ENEMYBULLET_TYPE type) : GameObject()
{
	if(type == UPSHOT)
	{
		row = 1;
		column = 1;
		speedX = 3;
		speedY = 3;
		
		char tempCharArray[1][1] = 
		{
			{'^'}	
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
		y = 15;
	}
	else if(type == LEFTSHOT)
	{
		row = 1;
		column = 1;
		speedX = 3;
		speedY = 3;
		
		char tempCharArray[1][1] = 
		{
			{'<'}	
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
		y = 15;
	}
	else if(type == RIGHTSHOT)
	{
		row = 1;
		column = 1;
		speedX = 3;
		speedY = 3;
		
		char tempCharArray[1][1] = 
		{
			{'>'}	
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
		y = 15;
	}
	else if(type == UPRIGHTSHOT)
	{
		row = 1;
		column = 1;
		speedX = 3;
		speedY = 3;
		
		char tempCharArray[1][1] = 
		{
			{'/'}	
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
		y = 15;
	}
	else if(type == DOWNRIGHTSHOT)
	{
		row = 1;
		column = 1;
		speedX = 3;
		speedY = 3;
		
		char tempCharArray[1][1] = 
		{
			{'\\'}	
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
		y = 15;
	}
	else if(type == UPLEFTSHOT)
	{
		row = 1;
		column = 1;
		speedX = 3;
		speedY = 3;
		
		char tempCharArray[1][1] = 
		{
			{'\\'}	
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
		y = 15;
	}
	else if(type == DOWNLEFTSHOT)
	{
		row = 1;
		column = 1;
		speedX = 3;
		speedY = 3;
		
		char tempCharArray[1][1] = 
		{
			{'/'}	
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
		y = 15;
	}
	else if(type == SSHOT1)
	{
		row = 1;
		column = 1;
		speedX = 3;
		speedY = 3;
		MovementPause = rand() % 10;
		MovementCount = 0;
		
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
	else if(type == SSHOT2)
	{
		row = 1;
		column = 1;
		speedX = 3;
		speedY = 3;
		MovementPause = rand() % 10;
		MovementCount = 0;
		
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
	else if(type == SSHOT3)
	{
		row = 1;
		column = 1;
		speedX = 3;
		speedY = 3;
		MovementPause = rand() % 10;
		MovementCount = 0;
		
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
	else if(type == SSHOT4)
	{
		row = 1;
		column = 1;
		speedX = 3;
		speedY = 3;
		MovementPause = rand() % 10;
		MovementCount = 0;
		
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
	else if(type == SSHOT5)
	{
		row = 1;
		column = 1;
		speedX = 3;
		speedY = 3;
		MovementPause = rand() % 10;
		MovementCount = 0;
		
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
	else if(type == SSHOT6)
	{
		row = 1;
		column = 1;
		speedX = 3;
		speedY = 3;
		MovementPause = rand() % 10;
		MovementCount = 0;
		
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
	else if(type == SSHOT7)
	{
		row = 1;
		column = 1;
		speedX = 3;
		speedY = 3;
		MovementPause = rand() % 10;
		MovementCount = 0;
		
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
	else if(type == SSHOT8)
	{
		row = 1;
		column = 1;
		speedX = 3;
		speedY = 3;
		MovementPause = rand() % 10;
		MovementCount = 0;
		
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
	this->type = type;
	isAlive = true;
}
             
void EnemyBullet::Update()
{
	if(type == LEFTSHOT || type == SSHOT3)
	{
		if(type == SSHOT3)
		{
			if(MovementCount > MovementPause)
			{
				return;
			}
			else
			{
				MovementCount++;
			}
		}
		
		if(CheckLeftBoundary() == false)
		{
			MoveLeft();
		}
		else
		{
			isAlive = false;
		}
	}
	else if(type == RIGHTSHOT || type == SSHOT7)
	{
		if(type == SSHOT7)
		{
			if(MovementCount > MovementPause)
			{
				return;
			}
			else
			{
				MovementCount++;
			}
		}
		
		if(CheckRightBoundary() == false)
		{
			MoveRight();
		}
		else
		{
			isAlive = false;
		}
	}
	else if(type == UPRIGHTSHOT || type == SSHOT8)
	{
		if(type == SSHOT8)
		{
			if(MovementCount > MovementPause)
			{
				return;
			}
			else
			{
				MovementCount++;
			}
		}
		
		if(CheckRightBoundary() == false && CheckTopBoundary() == false)
		{
			MoveRight();
			MoveUp();
		}
		else
		{
			isAlive = false;
		}
	}
	else if(type == DOWNRIGHTSHOT || type == SSHOT6)
	{
		if(type == SSHOT6)
		{
			if(MovementCount > MovementPause)
			{
				return;
			}
			else
			{
				MovementCount++;
			}
		}
		
		if(CheckRightBoundary() == false && CheckBottomBoundary() == false)
		{
			MoveRight();
			MoveDown();
		}
		else
		{
			isAlive = false;
		}
	}
	else if(type == UPLEFTSHOT || type == SSHOT2)
	{
		if(type == SSHOT2)
		{
			if(MovementCount > MovementPause)
			{
				return;
			}
			else
			{
				MovementCount++;
			}
		}
		
		if(CheckLeftBoundary() == false && CheckTopBoundary() == false)
		{
			MoveLeft();
			MoveUp();
		}
		else
		{
			isAlive = false;
		}
	}
	else if(type == DOWNLEFTSHOT || type == SSHOT4)
	{
		if(type == SSHOT4)
		{
			if(MovementCount > MovementPause)
			{
				return;
			}
			else
			{
				MovementCount++;
			}
		}
		
		if(CheckLeftBoundary() == false && CheckBottomBoundary() == false)
		{
			MoveLeft();
			MoveDown();
		}
		else
		{
			isAlive = false;
		}
	}
	else if(type == SSHOT5)
	{
		if(type == SSHOT5)
		{
			if(MovementCount > MovementPause)
			{
				return;
			}
			else
			{
				MovementCount++;
			}
		}
		
		if(CheckBottomBoundary() == false)
		{
			MoveDown();
		}
		else
		{
			isAlive = false;
		}
	}
	else
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
}
