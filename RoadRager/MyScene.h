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

	std::vector<RoadRow*> roadRows;

	size_t x;
	size_t y;

	Timer timer;

	float screenHeight = SHEIGHT;
	float screenWidth = SWIDTH;

  /*float currenHeight = startingPositionY;
	float spriteWidth = 128.0f;  
    float spriteHeight = 128.0f;
	
	float startingPositionX = (screenWidth - spriteWidth) / 2.0f;
    float startingPositionY = screenHeight - spriteHeight;*/
	

private:

};



#endif /* MYSCENE_H */