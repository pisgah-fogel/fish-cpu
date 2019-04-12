#ifndef SPAWN_HPP
#define SPAWN_HPP

#include "Command.hpp"
#include "Log.hpp"

namespace ui {
class Spawn : public ui::Command
{
	public:
	virtual size_t getMinArgc() { return 3;};
	virtual size_t getMaxArgc() { return 3;};
	virtual int run(std::vector<std::string> *args) {
		LOG("Info: Spawn fish at x:%s, y:%s", (*args)[1].c_str(), (*args)[2].c_str());
		return 0;
	}

};
}

#endif // SPAWN_HPP
