#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>
#include "RoadRow.h"
#include <windows.h>


class MyScene : public Scene
{
public: 
	MyScene();
	virtual~MyScene();

	void update(float deltaTime);


private: 

	int x; 
	int y;

	int leftGrass;
	int leftCLip;
	int rightGrass;
	int rightClip;
	int nRow;

	float middlePoint;
	float roadWidth;
	float clipWidth;

protected:

	CHAR_INFO *m_bufScreen;


	enum COLOR
	{
		FG_GREEN = 0x000A,
		FG_RED	= 0x000C,
		FG_GREY	= 0x0007,
	};

	enum Pixel_Type 
	{
		PIXEL_SOLID = 0x2588,
	};

	

	void Draw(int x, int y, short c = 0x2588, short col = 0x000F)
	{
    	if (x >= 0 && x < SWIDTH && y >= 0 && y < SHEIGHT)
    	{
        	m_bufScreen[y * SWIDTH + x].Char.UnicodeChar = c;
       		m_bufScreen[y * SWIDTH + x].Attributes = col;
    	}
	}

	void Fill(int x1, int y1, int x2, int y2, short c = 0x2588, short col = 0x000F)
	{
		Clip(x1, y1);
		Clip(x2, y2);
		for (int x = x1; x < x2; x++)
			for (int y = y1; y < y2; y++)
				Draw(x, y, c, col);
	};


	void Clip(int &x, int &y)
{
    if (x < 0) x = 0;
    if (x >= SWIDTH) x = SWIDTH - 1;
    if (y < 0) y = 0;
    if (y >= SHEIGHT) y = SHEIGHT - 1;
}
};



#endif /* MYSCENE_H */