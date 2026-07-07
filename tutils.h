#ifndef TUTILS_H
#define TUTILS_H

#include <termios.h>
#include <string>
class Terminal
{
    private:
	termios tio;
    public:
	void setCanonical(const std::string &cmd);
	void print(const std::string &str, const std::string &fg, const std::string &bg);
	void setCursor(const std::string &str);
};

#endif
