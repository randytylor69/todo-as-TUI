#ifndef TUTILS_H
#define TUTILS_H

#include <termios.h>
#include <string>
class Terminal
{
    private:
	termios tio;
	int listMode {0}; // 0=todo, 1=done
	bool editing {false};
    public:
	void setCanonical(const std::string &cmd);
	void print(const std::string &str, const std::string &fg, const std::string &bg);
	void setCursor(const std::string &str);
	void setListMode(const int &num);
	int getListMode();
	bool isEditing();
	void setEditing(const bool &mode);
	std::string getNewListItem(); // prompts for a new list item

};
// non-class functions
void printfb(const std::string &str, const std::string &fg, const std::string &bg);

#endif
