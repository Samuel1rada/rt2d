#ifndef ROADROWS_H
#define ROADROWS_H

#include <rt2d/scene.h>
#include <rt2d/entity.h>

class RoadRow : public Entity
{
public: 
	RoadRow(int Type);
	virtual ~RoadRow();

	void update(float deltaTime);

	int getType() const;
private:

	int type;
};



#endif /* ROADROWS_H */