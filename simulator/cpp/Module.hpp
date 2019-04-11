#ifndef MODULE_HPP
#define MODULE_HPP

namespace ui {
class Module
{
	public:
	virtual int run(size_t argc, void* args) = 0;	
	protected:
};
}

#endif // MODULE_HPP
