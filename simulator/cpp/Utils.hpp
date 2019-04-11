#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <vector>
#include <stdlib.h> // strtoul

std::vector<std::string> splitCmd(std::string str)
{
	std::vector<std::string> splitted;
	bool escapeNext = false;
	bool inStr = false;
	std::string current;
	for(std::string::iterator it = str.begin(); it != str.end(); it++) {
		if (inStr) {
			if (!escapeNext && *it == '"') {
				inStr = false;
				splitted.push_back(current);
				current.clear();
			}
			else
				current.push_back(*it);
		} else {
			if (!escapeNext && *it == '"')
				inStr = true;
			else if (*it == ' ' || *it == '\t') {
				if (current.size() != 0) {
					splitted.push_back(current);
					current.clear();
				}
			}
			else
				current.push_back(*it);
		}
		escapeNext = (*it == '\\');
	}
	if (current.size() != 0) {
		splitted.push_back(current);
	}

#ifdef DEBUG
	for (std::vector<std::string>::iterator it = splitted.begin(); it != splitted.end(); it++)
		std::cout<<" ["<<*it<<"] ";
	std::cout<<std::endl;
#endif

	return splitted;
}

#endif // UTILS_HPP
