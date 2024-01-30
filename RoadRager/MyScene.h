#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>

#include "RoadRow.h"

class MyScene : public Scene
{
public: 
	MyScene();
	virtual~MyScene();

	void update(float deltaTime);

	void CreatRoad();
	void RoadBend(float distance);

	std::vector<RoadRow*> grass;
	std::vector<RoadRow*> roadRows;
	std::vector<RoadRow*> sideRoadL;
	std::vector<RoadRow*> sideRoadR;

	RoadRow* grassBG;
	RoadRow* row;
	RoadRow* leftRoadSide;
	RoadRow* rightRoadSide;

	size_t x;
	size_t y;
	Timer t;

	float screenHeight = SHEIGHT;
	float screenWidth = SWIDTH;

	int initialX = screenWidth / 2;
	int initialY = screenHeight / 2;

  /*
	std::vector<float> originalXPositions;

  	float currenHeight = startingPositionY;
	float spriteWidth = 128.0f;  
    float spriteHeight = 128.0f;
	
	float startingPositionX = (screenWidth - spriteWidth) / 2.0f;
    float startingPositionY = screenHeight - spriteHeight;*/
	

private:

};




#endif /* MYSCENE_H */