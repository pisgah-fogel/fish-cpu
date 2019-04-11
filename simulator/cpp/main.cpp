/**
 * This file is the simulator entry point
 *
 * \author Phileas Fogg
 * \file main.cpp
 */

#include <iostream>
#include "Log.hpp"
#include "Welcome.hpp"
#include "UserInterface.hpp"

/**
 * \brief Simulator entry point
 * \arg argc, number of arguments
 * \arg argv, array of arguments
 * \return 0 if success, else returns 1 ou 2 
 */
int main(int argc, char** argv)
{
	print_welcome();
	LOG("Ok Logging system works");
	ui::UserInterface shell = ui::UserInterface();
	shell.mainLoop();
	return 0; // Exit Success
}
