#include "RoadRow.h"


RoadRow::RoadRow(int Type) : Entity(), type(Type)
{
    if(type == 0)
    {
        this->addSprite("assets/road.tga");
    }
    else if(type == 1)
    {
        this->addSprite("assets/road.tga");
        this->sprite()->color = RED;
        
    }
    else if(type == 2)
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
int RoadRow::getType() const
{
    return type;
}
