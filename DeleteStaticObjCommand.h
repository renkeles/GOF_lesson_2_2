#pragma once

#include "Command.h"
#include "GameObject.h"
#include <vector>

class DeleteStaticObjCommand : public Command
{
public:
	virtual ~DeleteStaticObjCommand() {}
	DeleteStaticObjCommand(const GameObject* obj, std::vector<GameObject*>& vec)
		: _obj(obj), _vec(vec) {}

	void Execute() override
	{
		auto iter = _vec.begin();
		for (; iter != _vec.end(); ++iter) {
			if (*iter == _obj) {
				delete* iter;
				_vec.erase(iter);
				return;
			}
		}
	}

private:
	const GameObject* _obj;
	std::vector<GameObject*>& _vec;
};
