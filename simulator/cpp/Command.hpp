#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <vector>

namespace ui {
class Command
{
	public:
	virtual size_t getMinArgc() = 0;
	virtual size_t getMaxArgc() = 0;
	virtual int run(std::vector<std::string> *args) = 0;
};
}

#endif // COMMAND_HPP
