#ifndef TODOS_H
#define TODOS_H

#include <vector>
#include <string>

class Todos
{
    private:
	std::vector<std::string> list {};
	int currIndex {0}; // current selected item's index in the list
    public:
	void add(const std::string &item); // append items to list
	void printList(); // print the todos list, current item highlighted
	void selectNextItem();
	void selectPrevItem();
};

#endif
