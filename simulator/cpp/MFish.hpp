#ifndef MFISH_HPP
#define MFISH_HPP

#include <iostream>

namespace ui
{
class MFish: public Module
{
	public:
	virtual int run(size_t argc, void* args) {
		std::cout<<"Mr. Fish is here"<<std::endl;
		return 0;
	}
	private:
};
}

#endif // MFISH_HPP
