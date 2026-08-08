# Shoebill Documentation

Shoebill is a scriptable MIDI Sequencer. To use it, clone the repository into a directory and run make. Run the executable and pass it the name of your script.

`./shoebill script.txt`

## Control Flow

A shoebill script is a sequence of instructions, which are read and interpreted by sequencers. Using certain commands, you can create more sequencers that run asynchronously, thus having more than one control flow.
Think of them like threads all using the common resource of the script file.

There are 4 kinds of instructions. Each line of the script file can only include 1 instruction.
1. Messages: These start with a `|` character and send MIDI messages to your computer.
2. Functions: These start with a `#` character and are used to change the behavior of sequencers.
3. Variable Declaration: These start with a `-` character and are used to create variables. Variables are akin to macros, they are just text replacement.
4. Sections: These start with a `@` character, and are used to mark certain parts of the script that you may want a sequencer to jump to. Unlike the other 3, these are read in a "preprocessing" stage, and are skipped by the sequencers during execution.

