
#include "MyScene.h"

MyScene::MyScene() : Scene()
{

    t.start();
    CreatRoad();
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

    //std::cout << " seconds passed " << t.seconds() << std::endl;
    
    // for (int i = 0; i < roadRows.size(); i++) 
    // {
    //     roadRows[i]->position.x = initialX + i * 10;
    //     std::cout << "Updated position for row at index " << i << ": " << roadRows[i]->position << std::endl;
    // }    
}
void MyScene::CreatRoad()
{
    roadRows = std::vector<RoadRow*>();
    sideRoad = std::vector<RoadRow*>();
    grass = std::vector<RoadRow*>();

    // creates background grass
    for (int y = 0; y < 21; y++)
    {
        for (int x = 0; x < 1; x++)
        {
            grassBG = new RoadRow(2);
            grassBG->position = Vector2(x = initialX, y * 20 + initialY);
            grassBG->scale.x = screenWidth;
            std::cout << "this roadline position: " << grassBG->position << std::endl;
            this->addChild(grassBG);
            grass.push_back(grassBG);
        }
    }
    //creats the roadrows and positions them.
	for (int y = 0; y < 21; y++) 
    {
        for (int x = 0; x < 1; x++) 
        {
            row = new RoadRow(0);
            row->position = Vector2(x = initialX, y * 20 + initialY);
            row->scale.x = 4;
            std::cout << "this row position: " << row->position << std::endl;
            this->addChild(row);
            roadRows.push_back(row);
        }    
    }
    //creates the sides of the road
    for (int y = 0; y < 21; y++)
    {
        for (int x = 0; x < 1; x++)
        {
            for(int i = 0; i < roadRows.size(); i++)
            {
                    leftRoadSide = new RoadRow(1);
                    leftRoadSide->position = Vector2(500 - i * 21, y * 20 + initialY);
                    std::cout << "this roadline position: " << leftRoadSide->position << std::endl;
                    this->addChild(leftRoadSide);
                    sideRoad.push_back(leftRoadSide);

                    // rightRoadSide = new RoadRow(1);
                    // std::cout << "this roadline position: " << rightRoadSide->position << std::endl;
                    // rightRoadSide->position = Vector2(initialX + i *21, y * 20 + initialY);
                    // this->addChild(rightRoadSide);
                    // sideRoad.push_back(rightRoadSide);
            }
        }
    }
    //scales the road for perspective
    for(int i = 0; i < roadRows.size(); i++)
    {
        if(roadRows[i]->getType() == 0)
        {
            roadRows[i]->scale.x = i * 0.5;
            std::cout << "Updated scale for row at index " << i << ": " << roadRows[i]->scale << std::endl;
        }
    }
}
void MyScene::ColorSwitch()
{

    if (t.seconds() > 1.0f)
    {
        for (int i = 0; i < roadRows.size(); i++)
        {
            RGBAColor color = roadRows[i]->sprite()->color;
            roadRows[i]->sprite()->color = GRAY; 
            if(t.seconds() > 2.0f)
            {
                roadRows[i]->sprite()->color = RED; 
            }
        }  
        t.start();      
    }
    // if (t.seconds() > 0.0333f)
    // {
    //     for(int i = 0; i < roadRows.size(); i++)
    //     {
    //         RGBAColor color = roadRows[i]->sprite()->color;
	// 	    roadRows[i]->sprite()->color = Color::rotate(color, 0.01f);
	// 	    t.start();  
    //     }
	// }
}

    
    






