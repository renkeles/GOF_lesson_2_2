#pragma once

#include "Command.h"
#include "DynamicObject.h"
#include <vector>

class DeleteDynamicObjCommand : public Command 
{
public:
	virtual ~DeleteDynamicObjCommand() {}
	DeleteDynamicObjCommand(const DynamicObject* obj, std::vector<DynamicObject*>& vec) 
		: _obj(obj), _vec(vec) {}

	void Execute() override 
	{
		auto iter = _vec.begin();
		for (;  iter != _vec.end(); ++iter) {
			if (*iter == _obj) {
				delete* iter;
				_vec.erase(iter);
				return;
			}
		}
	}

private:
	const DynamicObject* _obj;
	std::vector<DynamicObject*>& _vec;
};