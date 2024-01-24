
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

    // creates background grass.
    for (int y = 0; y < 21; y++)
    {
        for (int x = 0; x < 1; x++)
        {
            grassBG = new RoadRow(2);
            grassBG->position = Vector2(x = initialX, y * 20 + initialY + 20);
            grassBG->scale.x = screenWidth;
            std::cout << "this roadline position: " << grassBG->position << std::endl;
            this->addChild(grassBG);
            grass.push_back(grassBG);
        }
    }

    // creates the red sides nest to the road.
    for (int y = 0; y < 21; y++)
    {
        for (int x = 0; x < 1; x++)
        {
            RoadRow *row3 = new RoadRow(1);
            this->addChild(row3);
            sideRoadR.push_back(row3);

            RoadRow *row2 = new RoadRow(1);
            this->addChild(row2);
            sideRoadL.push_back(row2);

            for (int i = 0; i < sideRoadL.size(); i++)
            {
                row2->position = Vector2(initialX - 32 - i * 32, y * 20 + initialY + 20);
            }
            for (int i = 0; i < sideRoadR.size(); i++)
            {
                row3->position = Vector2(initialX + 32 + i * 32, y * 20 + initialY + 20);
            }
        }
    }
    // creats the roadrows and positions them.
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
    // scales the road for perspective.
    for (int i = 0; i < roadRows.size(); i++)
    {
        if (roadRows[i]->getType() == 0)
        {
            roadRows[i]->scale.x = i * 0.5;
            std::cout << "Updated scale for row at index " << i << ": " << roadRows[i]->scale << std::endl;
        }
    }
}
