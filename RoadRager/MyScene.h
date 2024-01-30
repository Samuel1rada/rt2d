#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>

#include "RoadEntity.h"
#include "PlayerEntity.h"

class MyScene : public Scene
{
public:
	MyScene();
	virtual ~MyScene();

	void update(float deltaTime);

	void CreatRoad();
	void BendRoad(float distance);
	void CreatePlayer();
	void PlayerInput(float deltaTime);
	void SwitchPlayerEntity(int entityType);
	void ClampPlayerPosition();

	std::vector<RoadEntity *> grass;
	std::vector<RoadEntity *> roadRows;
	std::vector<RoadEntity *> sideRoadL;
	std::vector<RoadEntity *> sideRoadR;

	RoadEntity *grassBG;
	RoadEntity *row;
	RoadEntity *rowL;
	RoadEntity *rowR;
	RoadEntity *leftRoadSide;
	RoadEntity *rightRoadSide;

	PlayerEntity *player;

	size_t x;
	size_t y;
	Timer t;

	float screenHeight = SHEIGHT;
	float screenWidth = SWIDTH;
	float leftSwitchPoint = screenWidth / 4.0f;
	float rightSwitchPoint = 3.0f * screenWidth / 4.0f;
	float multiplier;
	float playerWidth;
	float leftBoundary;
	float rightBoundary;
	int moveCount = 0;

	const int initialX = screenWidth / 2;
	const int initialY = screenHeight / 2;
	const int numRows = 21;
	const float scaleIncrement = 0.07f;
	const float playerSpeed = 300.0f;

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