#include "PlayerEntity.h"

PlayerEntity::PlayerEntity(int PlayerType /* = 0 */) : Entity(), Playertype(PlayerType)
{
    if(Playertype == 0)
    {
        this->addSprite("assets/road.tga");
        this->sprite()->color = BLUE;
    }
    else if(Playertype == 1)
    {
        this->addSprite("assets/road.tga");
        this->sprite()->color = CYAN;
    }
    else if(Playertype == 2)
    {
         this->addSprite("assets/road.tga");
         this->sprite()->color = MAGENTA;
         
    }
}

PlayerEntity::~PlayerEntity()
{

}
void PlayerEntity::update(float deltaTime)
{
    
}
int PlayerEntity::getType() const
{
    return Playertype;
}