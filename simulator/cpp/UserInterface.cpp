#include "UserInterface.hpp"

#include <map>
#include "Utils.hpp"
#include "Module.hpp"
#include "MFish.hpp"

ui::UserInterface::UserInterface()
{
	mModules = std::map<std::string, std::shared_ptr<ui::Module>>();
	loadModule("Mr.Fish", std::make_shared<ui::MFish>());
}

void ui::UserInterface::loadModule(std::string name, std::shared_ptr<ui::Module> mod)
{
	mModules[name] = mod;
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
