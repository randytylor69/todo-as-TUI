#include <termios.h>
#include <unistd.h>
#include <stdio.h>


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
    termios old_tio, new_tio;
    char c {};

    /* get the terminal settings for stdin */
    tcgetattr(STDIN_FILENO,&old_tio);

    /* we want to keep the old setting to restore them a the end */
    new_tio=old_tio;

    /* disable canonical mode (buffered i/o) and local echo */
    new_tio.c_lflag &=(~ICANON & ~ECHO);

    /* set the new settings immediately */
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);

    printf("\033[?25l"); // hide cursor

    while (c!='q') {
	c=getchar();
	if (c == 'a'){
	    printf("\033[37m\033[40mfg&bg change\033[0m\n",c);
	} else if (c=='b') {
	    printf("changed to transparent\n",c);
	} else{ printf("%c\n",c);}
    } 

    printf("\033[?25h\n"); // show cursor

    /* restore the former settings */
    tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);

    return 0;
}

