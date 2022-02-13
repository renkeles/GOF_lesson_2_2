#pragma once

#include "Command.h"
#include "Plane.h"
#include <vector>
#include "DynamicObject.h"
#include "Bomb.h"
#include "Ground.h"
#include "MyTools.h"
#include "BombDecorator.h"


class DropBombDecoratorCommand : public Command
{
public:
	~DropBombDecoratorCommand() {}
	DropBombDecoratorCommand
	(
		const Plane* plane,
		std::vector<DynamicObject*>& vec,
		uint16_t& bombsNumber,
		uint16_t& score,
		const double speed,
		const CraterSize craterSize
	) :
		_plane(plane),
		_vec(vec),
		_bombsNumber(bombsNumber),
		_score(score),
		_speed(speed),
		_craterSize(craterSize) {}

	void Execute() override
	{
		if (_bombsNumber > 0)
		{
			MyTools::LoggerProxy::getInstance().WriteToLog(std::string(__FUNCTION__) + " was invoked");

			double x = _plane->GetX() + 4;
			double y = _plane->GetY() + 2;

			Bomb* pBomb = new Bomb;
			pBomb->SetDirection(0.3, 1);
			pBomb->SetPos(x, y);
			pBomb->SetWidth(_craterSize);

			BombDecorator* bombDecorator = new BombDecorator(pBomb, _speed, "=");

			_vec.push_back(pBomb);
			_bombsNumber--;
			_score -= Bomb::BombCost;
		}
	}

private:
	const Plane* _plane;
	std::vector<DynamicObject*>& _vec;
	uint16_t& _bombsNumber;
	uint16_t& _score;
	const double _speed;
	const CraterSize _craterSize;
};