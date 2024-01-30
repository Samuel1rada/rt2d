#include "RoadEntity.h"


RoadEntity::RoadEntity(int Type) : Entity(), type(Type)
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
         this->sprite()->color = GREEN;
    }
}
RoadEntity::~RoadEntity()
{

}

void RoadEntity::update(float deltaTime)
{
    
}
int RoadEntity::getType() const
{
    return type;
}
