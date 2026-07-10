/* @CLASS that stores all the finished todos */

#include "dones.h"
#include "tutils.h"
#include <print>
#include <format>

void Dones::add(const std::string &item)
{
    list.push_back(item);
}

void Dones::printList()
{
    /* clear screen & move cursor to top left */
    std::print("\033[2J"); 
    std::print("\033[1;1H");

    /* print list */
    std::print(" TODO [DONE]\n");
    std::print("------------\n");
    for (int i=0; i<list.size(); i++)
    {
	if (i == currIndex) 
	    printfb(std::format("- [x] {}\n", list[i]), "\033[30m", "\033[47m");
	else
	    std::print("- [x] {}\n", list[i]);
    }
}

void Dones::selectNextItem()
{
    if (currIndex == list.size()-1) currIndex = 0; // end of the list
    else currIndex++;
}

void Dones::selectPrevItem()
{
    if (currIndex == 0) currIndex = list.size()-1; // start of the list
    else currIndex--;
}

std::string Dones::cutCurrItem()
{
    std::string currItem = list[currIndex]; // copy the deleted item
    list.erase(list.begin()+currIndex); 
    /* modify index */
    currIndex -= (currIndex==0) ? 0 : 1;
    return currItem;
}

int Dones::getSize()
{
    return list.size();
}
