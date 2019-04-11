/**
 * This file file describe a shell-like user interface
 *
 * \author Phileas Fogg
 * \file UserInterface.hpp
 */

#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include <map>
#include <memory>
#include "Module.hpp"

namespace ui {
class UserInterface
{
public:
	UserInterface();
	int mainLoop();
	~UserInterface();
	bool isModuleLoaded(std::string modName);
	void loadModule(std::string name, std::shared_ptr<ui::Module> mod);
private:
	std::map<std::string, std::shared_ptr<ui::Module>> mModules;
};
}

#endif // USERINTERFACE_HPP
