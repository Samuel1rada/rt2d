#ifndef PLAYER_H
#define PLAYER_H

#include <rt2d/entity.h>

class Player : public Entity
{
public: 
	Player();
	virtual ~Player();

	void update(float deltaTime);
private:
};

#endif /* PLAYER_H */