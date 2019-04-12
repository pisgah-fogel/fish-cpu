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
#include "Command.hpp"

namespace ui {
class UserInterface
{
public:
	UserInterface();
	int mainLoop();
	~UserInterface();
	bool isModuleLoaded(std::string modName);
	bool isCommandLoaded(std::string cmdName);
	void loadModule(std::string name, std::shared_ptr<ui::Module> mod);
	void loadCommand(std::string name, std::shared_ptr<ui::Command> cmd);
private:
	std::map<std::string, std::shared_ptr<ui::Module>> mModules;
	std::map<std::string, std::shared_ptr<ui::Command>> mCommands;
};
}

#endif // USERINTERFACE_HPP
