/**
 * This file contains the welcome print (ascii art ?)
 *
 * \author Phileas Fogg
 * \file welcome.cpp
 */

#include <iostream>

#include "Welcome.hpp"

/**
 * \brief print welcome on standard output
 */
void print_welcome()
{
	std::cout<<"! Open source Fish processor simulator !"<<std::endl;
	std::cout<<"*Based on a true stupid idea"<<std::endl<<std::endl;
	std::cout<<"Created by 'Phileas Fogg'"<<std::endl;
#ifdef DEBUG
	std::cout<<"This version was compiled with DEBUG mode enabled"<<std::endl;
#endif
}
