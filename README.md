# Shoebill Documentation

Shoebill is a scriptable MIDI Sequencer. To use it, clone the repository into a directory and run make. Run the executable and pass it the name of your script.

`make`

`./shoebill script.txt`

## Control Flow

A shoebill script is a sequence of instructions, which are read and interpreted by sequencers. Using certain commands, you can create more sequencers that run asynchronously, thus having more than one control flow.
Think of them like threads all using the common resource of the script file.

There are 4 kinds of instructions. Each line of the script file can only include 1 instruction.
1. Messages: These start with a `|` character and send MIDI messages to your computer.
2. Functions: These start with a `#` character and are used to change the behavior of sequencers.
3. Variable Declaration: These start with a `-` character and are used to create variables. Variables are akin to macros, they are just text replacement.
4. Sections: These start with a `@` character, and are used to mark certain parts of the script that you may want a sequencer to jump to. Unlike the other 3, these are read in a "preprocessing" stage, and are skipped by the sequencers during execution.

Before running an instruction, the sequencer performs two text replacement operations. First it checks for any variables used, and replaces it.
Then it checks for any randomization used, and resolves it. Then, the instruction is read and ran. 

## Messages

Messages are encapsulated by `|` characters, and are used to send MIDI messages to your computer.
There are two kinds, a Note Message and a CC Message.
Messages are read "in time," which means that after they are interpreted, the interpreting sequencer waits for one "step" before continuing.

### Note Messages

A note message contains up to 3 arguments, which include a channel, a note, and a velocity, but it needs at minimum just a note.
If you leave out the channel, it sends the message through the default channel (set to 1 by default). If you leave out the velocity, then it sends the message with a velocity of 127.
The `OFF` keyword can be used in either (1) the velocity field, which will send a note off message, telling the computer to stop playing the given note, or (2) in the note field, which will send a note off message
for all notes played through the given channel.

`|ch1,c3,50|` Sends a C3 note with velocity 50 through channel 1.

`|ch1,e3|` Sends an E3 note with velocity 127 through channel 1.

`|g5|` Sends a G3 note with velocity 127 through the default channel.

`|ch1,gb2|` Sends a G flat 2 note.

`|ch1,f#4|` Sends an F Sharp 4 note.

`|ch1,OFF|` Stop playing notes from channel 1.

`|ch1,a6,OFF|` Stop playing A6 through channel 1. 

### CC Messages

CC messages work similarly. They can have 3 arguments, which include a channel number, a CC number, and a value between 0 and 127. 
If a channel is not provided, the CC message is sent through the default channel, but the other two are necessary. These messages are used to change the value of CC's.

`|ch1,cc40,127|` Set channel 1's CC40 to 127.

`|cc1,0|` Set the default channel's CC1 to 0.

### Chaining

Messages can be chained together in a single line. All messages that are on one line are sent at the same time. 
Messages are the only kind of instruction that can be chained together on a single line.

`|ch1,c3|ch1,e3|ch2,g4|`

`|c3|e3|g3|ch1,cc6,80|`
