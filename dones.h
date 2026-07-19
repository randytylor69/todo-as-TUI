
#ifndef DONES_H
#define DONES_H

#include <vector>
#include <string>

class Dones
{
    private:
	std::vector<std::string> list {};
	int currIndex {0}; // current selected item's index in the list
    public:
	void compileDB();
	void add(const std::string &item); // append items to list
	void printList(); // print the todos list, current item highlighted
	void selectNextItem();
	void selectPrevItem();
	std::string cutCurrItem();
	int getSize();
};

#endif
