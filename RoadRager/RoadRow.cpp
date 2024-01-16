#include "RoadRow.h"


RoadRow::RoadRow(int Type) : Entity()
{
    if(Type == 0)
    {
        this->addSprite("assets/road.tga");
    }
    if(Type == 1)
    {
        this->addSprite("assets/road.tga");
        this->sprite()->color = RED;
        
    }
    if(Type == 2)
    {
         this->addSprite("assets/road.tga");
         this->sprite()->color = GRAY;
    }
}
RoadRow::~RoadRow()
{

}

void RoadRow::update(float deltaTime)
{
    
}
