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
	    case 'k':
		if (terminal.getListMode()==0){
		    todos.selectPrevItem();
		    todos.printList();}
		else {
		    dones.selectPrevItem();
		    dones.printList();}
		break;
		
	    case 'j':
		if (terminal.getListMode()==0){
		    todos.selectNextItem();
		    todos.printList();}
		else {
		    dones.selectNextItem();
		    dones.printList();}
		break;
	    
	    case '\t':
		if (terminal.getListMode()==0)
		{
		    terminal.setListMode(1);
		    dones.printList();
		} else {
		    terminal.setListMode(0);
		    todos.printList();
		} break;
	}
    } 

    terminal.setCursor("on");
    terminal.setCanonical("on");


    return 0;
}

