#ifndef ROADROWS_H
#define ROADROWS_H

#include <rt2d/scene.h>
#include <rt2d/entity.h>

class RoadRow : public Entity
{
public: 
	RoadRow();
	virtual ~RoadRow();

	void update(float deltaTime);
private:
};



#endif /* ROADROWS_H */