#ifndef PLAYERENTITY_H
#define PLAYERENTITY_H

#include <rt2d/entity.h>

class PlayerEntity : public Entity
{
public: 
	PlayerEntity(int PlayerType);
	virtual ~PlayerEntity();

	void update(float deltaTime);
	int getType() const;
private:

	int Playertype;
};

#endif /* PLAYER_H */