
#include <rt2d/core.h>
#include "MyScene.h"
#include "RoadEntity.h"
#include "PlayerEntity.h"

int main( void ) 
{
	// Core instance
	Core core;
	// Roadrager Scene
	MyScene* myscene = new MyScene();
	while (myscene->isRunning()) 
	{
		core.run(myscene);
		core.showFrameRate(5);
	}
	delete myscene;

	return 0;
}