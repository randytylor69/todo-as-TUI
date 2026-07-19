#include "tutils.h"
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include <print>

/* @HELPER -> modify terminal's canonical mode, cmd = "on" or "off" */
void Terminal::setCanonical(const std::string &cmd)
{
    if (cmd != "on" && cmd != "off") 
	throw std::invalid_argument("INVALID ARGS: setCanonical expects 'on' or 'off' as arguments");

    /* get the current terminal settings for stdin */
    tcgetattr(STDIN_FILENO,&tio);

    if (cmd == "off")
    {	/* disable canonical mode (buffered i/o) and local echo */
	tio.c_lflag &=(~ICANON & ~ECHO);
    } else if (cmd == "on")
    {	/* enable canonical mode (buffered i/o) and local echo */
	tio.c_lflag |=(ICANON | ECHO);
    } 
    tcsetattr(STDIN_FILENO,TCSANOW,&tio); // apply changes
}

/* @HELPER -> highlight terminal output */
void Terminal::print(const std::string &str, const std::string &fg, const std::string &bg)
{
    // prints string formatted with fg&bg and a new line.
    std::cout << fg << bg << str << "\033[0m\n";
}

/* @HELPER -> show/hide cursor. ARG = 'on' or 'off' */
void Terminal::setCursor(const std::string &str) 
{
    str == "on" ? printf("\033[?25h") : printf("\033[?25l");
}

void Terminal::setListMode(const int &num)
{
    listMode = num;
}

int Terminal::getListMode()
{
    return listMode;
}

void Terminal::setEditing(const bool &mode)
{
    editing = mode;
}

bool Terminal::isEditing()
{
    return editing;
}

std::string Terminal::getInputItem(const std::string &prompt)
{
    std::string item;
    std::print("\n{} ([ENTER] to save): ", prompt);
    std::getline(std::cin, item);
    return item;
}


// ================= NONE TERMINAL FUNCTIONS
/* print (f)oreground + (b)ackground */
void printfb(const std::string &str, const std::string &fg, const std::string &bg)
{
    // prints string formatted with fg&bg and a new line.
    std::cout << fg << bg << str << "\033[0m";
}

