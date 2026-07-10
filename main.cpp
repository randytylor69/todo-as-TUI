#include "tutils.h"
#include "todos.h"
#include "dones.h"
#include <cstdio>
#include <print>
using namespace std;

/* @TODO
 *
 * 1. Add a loading state when the app starts (currently takes 1 sec to load all the todos) 
 *
 *
 */

/* RUN SCRIPT: 
 * clear && g++ main.cpp tutils.cpp todos.cpp dones.cpp -o main && ./main
 * */

int main()
{

    Terminal terminal;
    
    terminal.setCursor("off");
    terminal.setCanonical("off");

    Todos todos;
    Dones dones;

    todos.add("get on the bus");
    todos.add("read a book");
    todos.add("contemplate about her");

    dones.add("get off the bus");
    dones.add("take off the cloth");
    dones.add("jump into the river");

    todos.printList();
    
    char c {};
    while (c!='q') {
	c=getchar();
	switch (c)
	{
	    case 'k': /* move up */
		if (terminal.getListMode()==0){
		    todos.selectPrevItem();
		    todos.printList();}
		else {
		    dones.selectPrevItem();
		    dones.printList();}
		break;
		
	    case 'j': /* move down */
		if (terminal.getListMode()==0){
		    todos.selectNextItem();
		    todos.printList();}
		else {
		    dones.selectNextItem();
		    dones.printList();}
		break;
	    
	    case '\t': /* toggle between todo and done */
		if (terminal.getListMode()==0)
		{
		    terminal.setListMode(1);
		    dones.printList();
		} else {
		    terminal.setListMode(0);
		    todos.printList();
		} break;

	    case '\n': /* toggle highlighted UI element */
		if (terminal.getListMode()==0)
		{
		    if (todos.getSize()==0) break;
		    std::string item = todos.cutCurrItem();
		    dones.add(item);
		    todos.printList();
		} else {
		    if (dones.getSize()==0) break;
		    std::string item = dones.cutCurrItem();
		    todos.add(item);
		    dones.printList();
		} 
		break;
	}
    } 

    terminal.setCursor("on");
    terminal.setCanonical("on");


    return 0;
}

