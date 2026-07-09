An unsophisticated [TUI](https://en.wikipedia.org/wiki/Text-based_user_interface) written in *see-plus-plus*, taking the form of a todo list. Note its inherent difference from a [CLI](https://en.wikipedia.org/wiki/Command-line_interface), for this interface supports immediate updates rendering (one might call it "Immediate TUI") upon any input without the presence of an input buffer.

## Screenshots

<div align="center">
| <img style="width:300px" src="https://github.com/randytylor69/todo-as-TUI/blob/main/screenshots/newscreenshot_009.jpg"/> | <img style="width:300px" src="https://github.com/randytylor69/todo-as-TUI/blob/main/screenshots/newscreenshot_010.jpg"/> |
|:--:|:--:|
| *Viewing pending tasks* | *Viewing completed tasks*|
</div>

## Interesting Concepts 

List of programming concepts that made this project possible:
- [ANSI Escape Codes](https://en.wikipedia.org/wiki/ANSI_escape_code): used to render elements anywhere on the terminal
- [Canonical Mode](https://en.wikipedia.org/wiki/POSIX_terminal_interface#Canonical_mode_processing) Toggler: the bread and butter of a *smooth* TUI (all it does is removing the `io` buffer)
- [Terminal Syntax Highlighting](https://en.wikipedia.org/wiki/ANSI_escape_code#Colors): UX tool
