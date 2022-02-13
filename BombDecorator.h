#pragma once

#include "DynamicObject.h"
#include "Bomb.h"
#include <iostream>

class BombDecorator : public Bomb 
{
public:
	~BombDecorator() 
	{
		delete _bomb;
	}

	BombDecorator(Bomb* bomb, const double speed, const char* image) : _bomb(bomb), _image(image) 
	{
		if (_bomb) 
		{
			_bomb->SetSpeed(speed);
		}
	}

	void Move(uint16_t time) override
	{
		_bomb->Move(time * 1.6);
	}

	void Draw() const override
	{
		
		_bomb->Draw();
		MyTools::ScreenSingleton::getInstance().GotoXY(_bomb->GetX(), _bomb->GetY() - 1);
		std::cout << _image;
		
	}

	virtual void SetPos(double nx, double ny) 
	{
		_bomb->SetPos(nx, ny);
	}

	virtual double GetY() const 
	{
		return _bomb->GetY();
	}

	virtual double GetX() const
	{
		return _bomb->GetX();
	}

	virtual void SetWidth(uint16_t widthN) 
	{
		_bomb->SetWidth(widthN);
	}

	uint16_t GetWidth() const 
	{ 
		return _bomb->GetWidth();
	}

private:
	Bomb* _bomb;
	const char* _image;
};