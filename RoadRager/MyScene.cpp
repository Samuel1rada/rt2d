
#include "MyScene.h"

MyScene::MyScene() : Scene()
{

    CreatRoad();
   /*if( y != screenHeight / 2  )
    {
       
    }*/ 
   /*
   while(currenHeight < screenHeight / 2)
    {
        roadRows.emplace_back(spriteHeight);
        currenHeight += spriteHeight;
    }*/ 

    //addChild(&puzzlefield);
  
}

MyScene::~MyScene()
{

}
void MyScene::update(float deltaTime) 
{

    originalXPositions = std::vector<float>();

    if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

    
    // for (int i = 0; i < roadRows.size(); i++) 
    // {
    //     roadRows[i]->position.x = initialX + i * 10;
    //     std::cout << "Updated position for row at index " << i << ": " << roadRows[i]->position << std::endl;
    // }    
}

void MyScene::CreatRoad()
{
    roadRows = std::vector<RoadRow*>();

	for (int y = 0; y < 21; y++) 
    {
        for (int x = 0; x < 1; x++) 
        {
            RoadRow* row = new RoadRow();
            row->position = Vector2(x = initialX, y * 20 + initialY);
            std::cout << "this row position: " << row->position << std::endl;
            this->addChild(row);
            roadRows.push_back(row);
        }
    }

    for(int i = 0; i < roadRows.size(); i++)
    {
        roadRows[i]->scale.x = i * 0.5;
       // roadRows->rotation.y = 180.0f;
        std::cout << "Updated scale for row at index " << i << ": " << roadRows[i]->scale << std::endl;
    }

}

    
    






