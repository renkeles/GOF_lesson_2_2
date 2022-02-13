#pragma once

#include "DynamicObject.h"
#include "Bomb.h"

class BombDecorator : public Bomb 
{
public:
	~BombDecorator() {}
	BombDecorator(Bomb* bomb) : _bomb(bomb) {}

	void Move(uint16_t time) override 
	{
		
	}

	void Draw() const override
	{
		
	}
private:
	Bomb* _bomb;
};