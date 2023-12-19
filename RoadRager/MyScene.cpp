
#include "MyScene.h"

MyScene::MyScene() : Scene()
{
     //timer.start();

    roadRows = std::vector<RoadRow*>();

	for (int y = 0; y < 10; y++) 
    {
        for (int x = 0; x < 1; x++) 
        {
            RoadRow* row = new RoadRow();
            row->position = Vector2(x = screenWidth / 2, y *128 + screenHeight);
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

	//std::cout<< timer.seconds() << " seconds passed"<<std::endl;

    if (input()->getKeyDown(KeyCode::Escape)) {
		this->stop();
	}

     while (!glfwWindowShouldClose(window)) {
        // Record the start time
        double startTime = glfwGetTime();

        // Run the loop for ten seconds
        while (glfwGetTime() - startTime < 10.0) {
            // Update the window, handle input, etc.

            // You may also use glfwWaitEvents to avoid unnecessary CPU usage
            glfwPollEvents();
        }

        // Print a message when the timer is done
        std::cout << "Timer finished!" << std::endl;

        // Reset the timer for the next interval
        glfwSetTime(0.0);

        // You may add a delay here if needed before starting the next interval
        // For example, std::this_thread::sleep_for(std::chrono::seconds(1));
    }

}




