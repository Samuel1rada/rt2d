
#include "MyScene.h"

MyScene::MyScene() : Scene()
{
    t.start();
    CreatRoad();
    CreatePlayer();
    // std::cout << "Size of roadRows: " << roadRows.size() << std::endl;
    // std::cout << "Position of the first row in roadRows: " << roadRows.front()->position << std::endl;
}

MyScene::~MyScene()
{
    for (auto &row : grass)
        delete row;
    for (auto &row : roadRows)
        delete row;
    for (auto &row : sideRoadL)
        delete row;
    for (auto &row : sideRoadR)
        delete row;

    grass.clear();
    roadRows.clear();
    sideRoadL.clear();
    sideRoadR.clear();
    this->removeChild(player);
}
void MyScene::update(float deltaTime)
{

    PlayerInput(deltaTime);

    if (input()->getKey(KeyCode::E))
    {
        BendRoad(100.0f * deltaTime);
    }
    if (input()->getKey(KeyCode::Q))
    {
        BendRoad(-100.0f * deltaTime);
    }
    if (input()->getKeyUp(KeyCode::Escape))
    {
        this->stop();
    }
}
void MyScene::CreatRoad()
{
    grass = std::vector<RoadEntity *>();
    roadRows = std::vector<RoadEntity *>();
    sideRoadL = std::vector<RoadEntity *>();
    sideRoadR = std::vector<RoadEntity *>();

    // creates the road and grass
    for (int y = 0; y < 21; y++)
    {
        for (int x = 0; x < 1; x++)
        {
            // creates grass
            grassBG = new RoadEntity(2);
            grassBG->position = Vector2(initialX, y * 20 + initialY + 20);
            grassBG->scale.x = screenWidth;
            // std::cout << "this roadline position: " << grassBG->position << std::endl;
            this->addChild(grassBG);
            grass.push_back(grassBG);

            // creates road
            row = new RoadEntity(0);
            row->position = Vector2(initialX, y * 20 + initialY);
            row->scale.x = 4;
            // std::cout << "this row position: " << row->position << std::endl;
            this->addChild(row);
            roadRows.push_back(row);

            // creates right road side
            rowR = new RoadEntity(1);
            this->addChild(rowR);
            sideRoadR.push_back(rowR);

            // creates left road side
            rowL = new RoadEntity(1);
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


// creates the illusion of an bending road
void MyScene::BendRoad(float distance)
{
    // Move the rows in roadRows
    for (auto row : roadRows)
    {
        row->position.x += distance * multiplier;
        multiplier *= 0.9f;
        moveCount++;
    }

    multiplier = 1.0f;

    // Move the rows in sideRoadR
    for (auto row : sideRoadR)
    {
        row->position.x += distance * multiplier;
        multiplier *= 0.85f;
        moveCount++;
    }

    multiplier = 1.0f;

    // Move the rows in sideRoadL
    for (auto row : sideRoadL)
    {
        row->position.x += distance * multiplier;
        multiplier *= 0.85f;
        moveCount++;
    }

    // Reset moveCount and multiplier after moving all rows
    if (moveCount >= roadRows.size() || moveCount >= sideRoadR.size() || moveCount >= sideRoadL.size())
    {
        moveCount = 0;
        multiplier = 1.0f;
    }
}

void MyScene::CreatePlayer()
{
    player = new PlayerEntity(0);
    player->position = Vector2(initialX, 600);
    this->addChild(player);
}

//creates instance off player
void MyScene::PlayerInput(float deltaTime)
{

    if (input()->getKey(KeyCode::A))
    {
        // Move left
        this->player->position.x -= playerSpeed * deltaTime;

        if (this->player->position.x < leftSwitchPoint)
        {
            SwitchPlayerEntity(1);
        }
    }
    else if (input()->getKey(KeyCode::D))
    {
        // Move right
        this->player->position.x += playerSpeed * deltaTime;

        if (this->player->position.x > rightSwitchPoint)
        {
            SwitchPlayerEntity(2);
        }
    }
    ClampPlayerPosition();
}

void MyScene::SwitchPlayerEntity(int entityType)
{
    Vector2 playerPosition = player->position;
    // Remove the current player entity from the scene
    this->removeChild(player);

    if (playerPosition.x < rightSwitchPoint)
        player = new PlayerEntity(0); 
    else if (playerPosition.x < leftSwitchPoint)
    {
        if (entityType == 1)
            player = new PlayerEntity(1);
        else if (entityType == 2)
            player = new PlayerEntity(2);
    }
    else
        player = new PlayerEntity(0); 

    player->position = playerPosition;

    // Add the new player entity to the scene
    this->addChild(player);
}

// so the player doesnt go off screen
void MyScene::ClampPlayerPosition()
{
    playerWidth = player->scale.x;

    leftBoundary = playerWidth / 2.0f;
    rightBoundary = screenWidth - playerWidth / 2.0f;

    player->position.x = std::max(leftBoundary, std::min(player->position.x, rightBoundary));
}