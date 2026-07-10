/* @CLASS that stores all the todos */

#include "todos.h"
#include "dones.h"
#include "tutils.h"
#include <print>
#include <format>

void Todos::add(const std::string &item)
{
    list.push_back(item);
}

void Todos::printList()
{
    /* clear screen & move cursor to top left */
    std::print("\033[2J"); 
    std::print("\033[1;1H");

    /* print list */
    std::print("[TODO] DONE \n");
    std::print("------------\n");
    for (int i=0; i<list.size(); i++)
    {
	if (i == currIndex) 
	    printfb(std::format("- [ ] {}\n", list[i]), "\033[30m", "\033[47m");
	else
	    std::print("- [ ] {}\n", list[i]);
    }
}

void Todos::selectNextItem()
{
    if (currIndex == list.size()-1) currIndex = 0; // end of the list
    else currIndex++;
}

void Todos::selectPrevItem()
{
    if (currIndex == 0) currIndex = list.size()-1; // start of the list
    else currIndex--;
}

std::string Todos::cutCurrItem()
{
    std::string currItem = list[currIndex]; // copy the deleted item
    list.erase(list.begin()+currIndex); 
    /* modify index */
    currIndex -= (currIndex==0) ? 0 : 1;
    return currItem;
}

int Todos::getSize()
{
    return list.size();
}
