
#include "MyScene.h"

MyScene::MyScene() : Scene()
{
     //timer.start();

    roadRows = std::vector<RoadRow*>();

	for (int y = 0; y < 5; y++) 
    {
        for (int x = 0; x < 1; x++) 
        {
            RoadRow* row = new RoadRow();
            row->position = Vector2(x = initialX, y * -128 + screenHeight);
            std::cout << "this row position: " << row->position << std::endl;
            this->addChild(row);
            roadRows.push_back(row);
        }
    }

    

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
	//std::cout<< timer.seconds() << " seconds passed"<<std::endl;

    if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

    // Run the loop for ten seconds
    while (glfwGetTime() - startTime < 16.0) 
    {
        glfwPollEvents();

        if (glfwGetTime() >= 15.0) 
        {

            for (int i = 0; i < roadRows.size(); i++) 
            {
                roadRows[i]->position.x = initialX + i * 10;
                std::cout << "Updated position for row at index " << i << ": " << roadRows[i]->position << std::endl;
            }

            //std::cout << "Action at 15 seconds!" << std::endl;
            glfwSetTime(0.0);
            std::cout << "Timer reset" << std::endl;

            break;
        }
        
    }

    /*for (int i = 0; i < roadRows.size(); i++) {
    roadRows[i]->position.x = originalXPositions[i];
    std::cout << "Reverted position for row at index " << i << ": " << roadRows[i]->position << std::endl;
    }*/
    
    
}





