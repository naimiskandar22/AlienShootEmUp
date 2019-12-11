#include "AllHeaderFiles.h"

Bullet::Bullet(BULLET_TYPE type) : GameObject()
{
	if(type == STRAIGHT)
	{
		row = 1;
		column = 1;
		speedX = 2;
		speedY = 2;
		this->type = STRAIGHT;
		damage = 10;
		
		char tempCharArray[1][1] = 
		{
			{'X'}	
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
		
		colour = LIGHTCYAN;
		x = 20;
		y = 15;
	}
	else if(type == DUAL)
	{
		row = 1;
		column = 3;
		speedX = 2;
		speedY = 2;
		this->type = DUAL;
		damage = 20;
		
		char tempCharArray[1][3] = 
		{
			{'X', ' ', 'X'}	
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
		
		colour = LIGHTCYAN;
		x = 20;
		y = 15;
	}
	else if(type == SPREAD1)
	{
			row = 1;
			column = 2;
			this->type = SPREAD1;
			damage = 10;
			
			char tempCharArray[1][2] = 
			{
				{'*','*'}
			};
			
			charArray = new char*[row];
			for(int i = 0; i < row; i++)
			{
				charArray[i] = new char[column];
				for(int j = 0; j < column; j++)
				{
					charArray[i][j] = tempCharArray[i][j];
				}
			}
			
			colour = LIGHTCYAN;
			x = 20;
			y = 15;
	}
	else if(type == SPREAD2)
	{
			row = 1;
			column = 2;
			this->type = SPREAD2;
			damage = 10;
			
			char tempCharArray[1][2] = 
			{
				{'*','*'}
			};
			
			charArray = new char*[row];
			for(int i = 0; i < row; i++)
			{
				charArray[i] = new char[column];
				for(int j = 0; j < column; j++)
				{
					charArray[i][j] = tempCharArray[i][j];
				}
			}
			
			colour = LIGHTCYAN;
			x = 20;
			y = 15;
	}
	else if(type == SPREAD3)
	{
			row = 1;
			column = 2;
			this->type = SPREAD3;
			damage = 10;
			
			char tempCharArray[1][2] = 
			{
				{'*','*'}
			};
			
			charArray = new char*[row];
			for(int i = 0; i < row; i++)
			{
				charArray[i] = new char[column];
				for(int j = 0; j < column; j++)
				{
					charArray[i][j] = tempCharArray[i][j];
				}
			}
			
			colour = LIGHTCYAN;
			x = 20;
			y = 15;
	}
	else if(type == SHIELD1)
	{
			row = 1;
			column = 1;
			this->type = SHIELD1;
			damage = 100;
			
			char tempCharArray[1][1] = 
			{
				{'@'}
			};
			
			charArray = new char*[row];
			for(int i = 0; i < row; i++)
			{
				charArray[i] = new char[column];
				for(int j = 0; j < column; j++)
				{
					charArray[i][j] = tempCharArray[i][j];
				}
			}
			
			colour = LIGHTCYAN;
			x = 20;
			y = 15;
	}
	else if(type == SHIELD2)
	{
			row = 1;
			column = 1;
			this->type = SHIELD2;
			damage = 100;
			
			char tempCharArray[1][1] = 
			{
				{'@'}
			};
			
			charArray = new char*[row];
			for(int i = 0; i < row; i++)
			{
				charArray[i] = new char[column];
				for(int j = 0; j < column; j++)
				{
					charArray[i][j] = tempCharArray[i][j];
				}
			}
			
			colour = LIGHTCYAN;
			x = 20;
			y = 15;
	}
	else if(type == SHIELD3)
	{
			row = 1;
			column = 1;
			this->type = SHIELD3;
			damage = 100;
			
			char tempCharArray[1][1] = 
			{
				{'@'}
			};
			
			charArray = new char*[row];
			for(int i = 0; i < row; i++)
			{
				charArray[i] = new char[column];
				for(int j = 0; j < column; j++)
				{
					charArray[i][j] = tempCharArray[i][j];
				}
			}
			
			colour = LIGHTCYAN;
			x = 20;
			y = 15;
	}
	else if(type == SHIELD4)
	{
			row = 1;
			column = 1;
			this->type = SHIELD4;
			damage = 100;
			
			char tempCharArray[1][1] = 
			{
				{'@'}
			};
			
			charArray = new char*[row];
			for(int i = 0; i < row; i++)
			{
				charArray[i] = new char[column];
				for(int j = 0; j < column; j++)
				{
					charArray[i][j] = tempCharArray[i][j];
				}
			}
			
			colour = LIGHTCYAN;
			x = 20;
			y = 15;
	}
	else if(type == CLUSTER1)
	{
			row = 1;
			column = 1;
			this->type = CLUSTER1;
			
			char tempCharArray[1][1] = 
			{
				{'&'}
			};
			
			charArray = new char*[row];
			for(int i = 0; i < row; i++)
			{
				charArray[i] = new char[column];
				for(int j = 0; j < column; j++)
				{
					charArray[i][j] = tempCharArray[i][j];
				}
			}
			
			colour = LIGHTCYAN;
			x = 20;
			y = 15;
			damage = 10;
	}
	else if(type == CLUSTER2)
	{
			row = 1;
			column = 1;
			this->type = CLUSTER2;
			
			char tempCharArray[1][1] = 
			{
				{'&'}
			};
			
			charArray = new char*[row];
			for(int i = 0; i < row; i++)
			{
				charArray[i] = new char[column];
				for(int j = 0; j < column; j++)
				{
					charArray[i][j] = tempCharArray[i][j];
				}
			}
			
			colour = LIGHTCYAN;
			x = 20;
			y = 15;
			damage = 10;
	}
	else if(type == CLUSTER3)
	{
			row = 1;
			column = 1;
			this->type = CLUSTER3;
			
			char tempCharArray[1][1] = 
			{
				{'&'}
			};
			
			charArray = new char*[row];
			for(int i = 0; i < row; i++)
			{
				charArray[i] = new char[column];
				for(int j = 0; j < column; j++)
				{
					charArray[i][j] = tempCharArray[i][j];
				}
			}
			
			colour = LIGHTCYAN;
			x = 20;
			y = 15;
			damage = 10;
	}
	else if(type == CLUSTER4)
	{
			row = 1;
			column = 1;
			this->type = CLUSTER4;
			
			char tempCharArray[1][1] = 
			{
				{'&'}
			};
			
			charArray = new char*[row];
			for(int i = 0; i < row; i++)
			{
				charArray[i] = new char[column];
				for(int j = 0; j < column; j++)
				{
					charArray[i][j] = tempCharArray[i][j];
				}
			}
			
			colour = LIGHTCYAN;
			x = 20;
			y = 15;
			damage = 10;
	}
	else if(type == CLUSTER5)
	{
			row = 1;
			column = 1;
			this->type = CLUSTER5;
			
			char tempCharArray[1][1] = 
			{
				{'&'}
			};
			
			charArray = new char*[row];
			for(int i = 0; i < row; i++)
			{
				charArray[i] = new char[column];
				for(int j = 0; j < column; j++)
				{
					charArray[i][j] = tempCharArray[i][j];
				}
			}
			
			colour = LIGHTCYAN;
			x = 20;
			y = 15;
			damage = 10;
	}
	else if(type == CLUSTER6)
	{
			row = 1;
			column = 1;
			this->type = CLUSTER6;
			
			char tempCharArray[1][1] = 
			{
				{'&'}
			};
			
			charArray = new char*[row];
			for(int i = 0; i < row; i++)
			{
				charArray[i] = new char[column];
				for(int j = 0; j < column; j++)
				{
					charArray[i][j] = tempCharArray[i][j];
				}
			}
			
			colour = LIGHTCYAN;
			x = 20;
			y = 15;
			damage = 10;
	}
	else if(type == CLUSTER7)
	{
			row = 1;
			column = 1;
			this->type = CLUSTER7;
			
			char tempCharArray[1][1] = 
			{
				{'&'}
			};
			
			charArray = new char*[row];
			for(int i = 0; i < row; i++)
			{
				charArray[i] = new char[column];
				for(int j = 0; j < column; j++)
				{
					charArray[i][j] = tempCharArray[i][j];
				}
			}
			
			colour = LIGHTCYAN;
			x = 20;
			y = 15;
			damage = 10;
	}
	else if(type == CLUSTER8)
	{
			row = 1;
			column = 1;
			this->type = CLUSTER8;
			
			char tempCharArray[1][1] = 
			{
				{'&'}
			};
			
			charArray = new char*[row];
			for(int i = 0; i < row; i++)
			{
				charArray[i] = new char[column];
				for(int j = 0; j < column; j++)
				{
					charArray[i][j] = tempCharArray[i][j];
				}
			}
			
			colour = LIGHTCYAN;
			x = 20;
			y = 15;
			damage = 10;
	}
	isAlive = true;
}
             
void Bullet::Update()
{
	if(type == SPREAD1)
	{
		if(CheckTopBoundary() == false && CheckLeftBoundary() == false)
		{
			MoveUp();
			MoveLeft();
		}
		else
		{
			isAlive = false;
		}
	}
	else if(type == SPREAD3)
	{
		if(CheckTopBoundary() == false && CheckRightBoundary() == false)
		{
			MoveUp();
			MoveRight();
		}
		else
		{
			isAlive = false;
		}
	}
	else if(type == CLUSTER2)
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
	else if(type == CLUSTER3)
	{
		if(CheckLeftBoundary() == false)
		{
			MoveLeft();
		}
		else
		{
			isAlive = false;
		}
	}
	else if(type == CLUSTER4)
	{
		if(CheckRightBoundary() == false)
		{
			MoveRight();
		}
		else
		{
			isAlive = false;
		}
	}
	else if(type == CLUSTER5)
	{
		if(CheckBottomBoundary() == false && CheckRightBoundary() == false)
		{
			MoveDown();
			MoveRight();
		}
		else
		{
			isAlive = false;
		}
	}
	else if(type == CLUSTER6)
	{
		if(CheckTopBoundary() == false && CheckRightBoundary() == false)
		{
			MoveUp();
			MoveRight();
		}
		else
		{
			isAlive = false;
		}
	}
	else if(type == CLUSTER7)
	{
		if(CheckTopBoundary() == false && CheckLeftBoundary() == false)
		{
			MoveUp();
			MoveLeft();
		}
		else
		{
			isAlive = false;
		}
	}
	else if(type == CLUSTER8)
	{
		if(CheckBottomBoundary() == false && CheckLeftBoundary() == false)
		{
			MoveDown();
			MoveLeft();
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
