#ifndef ROADENTITY_H
#define ROADENTITY_H

#include <rt2d/scene.h>
#include <rt2d/entity.h>

class RoadEntity : public Entity
{
public: 
	RoadEntity(int Type);
	virtual ~RoadEntity();

	void update(float deltaTime);
	int getType() const;
private:

	int type;
};



#endif /* ROADENTITY_H */