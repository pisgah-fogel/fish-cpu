#include "UserInterface.hpp"

#include <map>
#include "Utils.hpp"
#include "Module.hpp"
#include "MFish.hpp"
#include "Command.hpp"
#include "Spawn.hpp"

ui::UserInterface::UserInterface()
{
	mModules = std::map<std::string, std::shared_ptr<ui::Module>>();
	mCommands = std::map<std::string, std::shared_ptr<ui::Command>>();
	loadModule("Mr.Fish", std::make_shared<ui::MFish>());
	loadCommand("spawn", std::make_shared<ui::Spawn>());
}

void ui::UserInterface::loadModule(std::string name, std::shared_ptr<ui::Module> mod)
{
	mModules[name] = mod;
}

void ui::UserInterface::loadCommand(std::string name, std::shared_ptr<ui::Command> cmd)
{
	mCommands[name] = cmd;
}

int ui::UserInterface::mainLoop()
{
	std::string cmd;
	std::vector<std::string> splitted;

	while (1)
	{
		std::cout<<"$ ";
		std::getline(std::cin, cmd);
		splitted = splitCmd(cmd);
		if (splitted.size()==0) {
			continue;
		}
		else if (splitted[0] == "quit" || splitted[0] == "exit" || splitted[0]
== "q") {
			break;
		}
		else if (isModuleLoaded(splitted[0])) {
			mModules[splitted[0]]->run(0, (void*)0);
		}
		else if (isCommandLoaded(splitted[0])) {
			if (splitted.size() < mCommands[splitted[0]]->getMinArgc())
				LOG("Error: Not enough arguments");
			else if (splitted.size() > mCommands[splitted[0]]->getMaxArgc())
				LOG("Error: Too much arguments");
			else
				mCommands[splitted[0]]->run(&splitted);
		}
		else {
			std::cout<<splitted[0]<<" not found"<<std::endl;
		}
	}
	return 0;
}
ui::UserInterface::~UserInterface()
{
}

bool ui::UserInterface::isModuleLoaded(std::string modName)
{
	return mModules.find(modName) != mModules.end();
}

bool ui::UserInterface::isCommandLoaded(std::string cmdName)
{
	return mCommands.find(cmdName) != mCommands.end();
}
