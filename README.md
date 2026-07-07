A simple & beginner-friendly [TUI](https://en.wikipedia.org/wiki/Text-based_user_interface) written in *see-plus-plus*, taking the form of a todo list. Figured I'll code it myself since there's no online guides covering this subject. Note that this is not a [CLI](https://en.wikipedia.org/wiki/Command-line_interface), but an interface with immediate updates rendering (one might call it "Immediate TUI"), which makes it unique and fun to develop. 

## Screenshots

Coming soon

## Used Concepts 

List of programming concepts that made this project possible:
- [ANSI Escape Codes](https://en.wikipedia.org/wiki/ANSI_escape_code): used to render elements anywhere on the terminal
- [Canonical Mode](https://en.wikipedia.org/wiki/POSIX_terminal_interface#Canonical_mode_processing) Toggler: the bread and butter of a *smooth* TUI (all it does is removing the `io` buffer)
- [Terminal Syntax Highlighting](https://en.wikipedia.org/wiki/ANSI_escape_code#Colors): UX tool
