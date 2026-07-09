#ifndef TUTILS_H
#define TUTILS_H

#include <termios.h>
#include <string>
class Terminal
{
    private:
	termios tio;
	int listMode {0}; // 0=todo, 1=done
    public:
	void setCanonical(const std::string &cmd);
	void print(const std::string &str, const std::string &fg, const std::string &bg);
	void setCursor(const std::string &str);
	void setListMode(const int &num);
	int getListMode();
};

// non-class functions
void printfb(const std::string &str, const std::string &fg, const std::string &bg);

#endif
