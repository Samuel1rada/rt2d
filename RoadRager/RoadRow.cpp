#include "RoadRow.h"


RoadRow::RoadRow() : Entity()
{
    this->addSprite("assets/road.tga");
    this->sprite()->color = RED;
    
}
RoadRow::~RoadRow()
{

}

void RoadRow::update(float deltaTime)
{
    
}
