#include "tutils.h"
#include <cstdio>
using namespace std;

/* @TODO
 *
 * 1. Separate the terminal syntax coloring & canonical mode toggler into another .cpp file
 * 2. Start writing mock todo data; enable toggle between todos with syntax coloring.
 * 
 *
 *
 */

int main()
{

    Terminal terminal;
    
    terminal.setCursor("off");
    terminal.setCanonical("off");

    char c {};
    while (c!='q') {
	c=getchar();
	if (c == 'a'){
	    //printf("\033[37m\033[40mfg&bg change\033[0m\n",c);
	    terminal.print("fg&bg change", "\033[37m", "\033[40m");

	} else{ printf("%c\n",c);}
    } 

    terminal.setCursor("on");
    terminal.setCanonical("on");


    return 0;
}

