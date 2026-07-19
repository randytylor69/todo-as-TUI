/* @CLASS that stores all the todos */

#include "todos.h"
#include "dones.h"
#include "tutils.h"
#include <print>
#include <string>
#include <format>
#include <fstream>
#include <iostream>

void Todos::compileDB()
{
    list.clear();
    std::ifstream db_in("database.txt");
    std::string line;
    while (std::getline(db_in, line))
    {
	list.push_back(line);
    }

}
void Todos::add(const std::string &item)
{
    //1. write to databse
    std::ofstream db_out("database.txt", std::ofstream::app);
    db_out << item << '\n';
    db_out.close();
    //2. update current array
    compileDB();
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

    /* modify database */
    std::ofstream db_temp("database.txt");
    db_temp.close(); // open and close a file to erase its content
    
    std::ofstream db_add("database.txt", std::ofstream::app);
    for (std::string &line : list)
    {
	db_add << line << '\n';
    }
    db_add.close();
    

    return currItem;
}

int Todos::getSize()
{
    return list.size();
}

void Todos::setCurrIndexToNewestItem()
{ // quite a mouthful but it just highlights the last entered item
    currIndex = list.size()-1;
}

void Todos::renameCurrItem(const std::string &newname)
{
    list[currIndex] = newname;
}


