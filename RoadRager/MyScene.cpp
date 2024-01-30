
#include "MyScene.h"

MyScene::MyScene() : Scene()
{
    t.start();
    CreatRoad();
    // std::cout << "Size of roadRows: " << roadRows.size() << std::endl;
    // std::cout << "Position of the first row in roadRows: " << roadRows.front()->position << std::endl;
}

MyScene::~MyScene()
{
}
void MyScene::update(float deltaTime)
{
    if (input()->getKey(KeyCode::E))
    {
        RoadBend(100.0f * deltaTime); 
    }
    if (input()->getKey(KeyCode::Q))
    {
        RoadBend(-100.0f * deltaTime); 
    }

    if (input()->getKeyUp(KeyCode::Escape))
    {
        this->stop();
    }
}
void MyScene::CreatRoad()
{
    grass = std::vector<RoadRow *>();
    roadRows = std::vector<RoadRow *>();
    sideRoadL = std::vector<RoadRow *>();
    sideRoadR = std::vector<RoadRow *>();

    // creates the road and grass
    for (int y = 0; y < 21; y++)
    {
        for (int x = 0; x < 1; x++)
        {
            // creates grass
            grassBG = new RoadRow(2);
            grassBG->position = Vector2(initialX, y * 20 + initialY + 20);
            grassBG->scale.x = screenWidth;
            // std::cout << "this roadline position: " << grassBG->position << std::endl;
            this->addChild(grassBG);
            grass.push_back(grassBG);

            // creates road
            row = new RoadRow(0);
            row->position = Vector2(initialX, y * 20 + initialY);
            row->scale.x = 4;
            // std::cout << "this row position: " << row->position << std::endl;
            this->addChild(row);
            roadRows.push_back(row);

            // creates right road side
            RoadRow *rowR = new RoadRow(1);
            this->addChild(rowR);
            sideRoadR.push_back(rowR);

            // creates left road side
            RoadRow *rowL = new RoadRow(1);
            this->addChild(rowL);
            sideRoadL.push_back(rowL);

            for (int i = 0; i < sideRoadL.size(); i++)
            {
                rowL->position = Vector2(initialX - 32 - i * 32, y * 20 + initialY + 20);
            }
            for (int i = 0; i < sideRoadR.size(); i++)
            {
                rowR->position = Vector2(initialX + 32 + i * 32, y * 20 + initialY + 20);
            }
        }
    }
    // scales the road row for perspective.
    for (int i = 0; i < roadRows.size(); i++)
    {
        if (roadRows[i]->getType() == 0)
        {
            roadRows[i]->scale.x = i * 0.5;
            // std::cout << "Updated scale for row at index " << i << ": " << roadRows[i]->scale << std::endl;
        }
    }
}
void MyScene::RoadBend(float distance)
{
    // move onlyeee
   static int moveCount = 0;  // Keep track of the number of elements moved

    // Move the first 'moveCount' elements in roadRows
    for (int i = 0; i <= moveCount && i < roadRows.size(); ++i)
    {
        roadRows[i]->position.x += distance;
    }

    // Move the first 'moveCount' elements in sideRoadR
    for (int i = 0; i <= moveCount && i < sideRoadR.size(); ++i)
    {
        sideRoadR[i]->position.x += distance;
    }

    // Move the first 'moveCount' elements in sideRoadL
    for (int i = 0; i <= moveCount && i < sideRoadL.size(); ++i)
    {
        sideRoadL[i]->position.x += distance;
    }

    // Increment moveCount after moving all elements
    moveCount++;

    // Reset moveCount after moving all elements in the lists
    if (moveCount >= roadRows.size() && moveCount >= sideRoadR.size() && moveCount >= sideRoadL.size())
    {
        moveCount = 0;
    }
}
