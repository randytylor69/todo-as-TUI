## The Thing

An unsophisticated [TUI](https://en.wikipedia.org/wiki/Text-based_user_interface) written in *see-plus-plus*, taking the form of a todo list. Note its inherent difference from a [CLI](https://en.wikipedia.org/wiki/Command-line_interface), for this interface supports immediate updates rendering (one might call it "Immediate TUI") upon any input without the presence of an input buffer.

This project is inspired entirely by [@tsoding's program](https://github.com/tsoding/todo-rs) written in Rust. It's an excellent beginner project to be re-written in C++! So many new concepts learned. 

<div align="center">
  
| <img style="width:300px" src="https://github.com/randytylor69/todo-as-TUI/blob/main/screenshots/newscreenshot_009.jpg"/> | <img style="width:300px" src="https://github.com/randytylor69/todo-as-TUI/blob/main/screenshots/newscreenshot_010.jpg"/> |
|:--:|:--:|
| *Viewing pending tasks* | *Viewing completed tasks*|

</div>

&nbsp;

## Man Page

<div align="center">

| **Command** | **Function** |
| --- | --- |
| `k`/`j` | Select item above / below |
| `r` | Rename current item |
| `i` | Insert new item|
| `q` | Quit program |
| `TAB` | Toggle between todos-list and dones-list |
| `ENTER` | Toggle currently selected item (i.e. if it's a **todo** then send it to **done**) |

</div>

Yes, it's mostly Vim Motions.

&nbsp;

## How To Run

```
make && ./main.out
```

You can also alias it inside `.bashrc`:

```
alias todo='cd ~/todo-as-TUI && make && ./main.out'
```
