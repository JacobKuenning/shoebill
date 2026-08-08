# Sections

Sections are marked areas in the script that can be easily referenced in functions like `go_to` and `play`. To create a section, type @ followed by the name of the section. 
It can then be referenced within those funcions. `@END` is a special keyword reserved for use with the `play` function. 
When it is encountered, it will move the sequencer to the line underneath the last `play` function that was ran. Upon multiple calls of the play function, it will return to the latest in the stack.
