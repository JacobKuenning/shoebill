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

`|c3||e3|g3||ch3,d5,OFF|` empty messages can also be chained, for ease of using variables.

### The x Character

The `x` instruction is used to wait for a step. The following will play C3 through channel 1, and then wait for 3 steps.

`|ch1,c3|`

`x`

`x`

`x`

## Functions

Functions are used to change the behavior of something, and are executed when a sequencer encounters them. 
They are run "out of time" which means the sequencer does not wait a step before continuing after executing the function.

### Control Changes

`#start_cc(ch, cc, start, end, t)`

Interpolate a MIDI Control Change (*cc*) message on channel (*ch*) from *start* value to *end* value smoothly over the course of *t* seconds.

### Sequencer Creation and Control

`#end_seq()` or `#end_seq(name)`

Kill the sequencer with the name *name*. Otherwise, kill the sequencer that called this function.

`#new_seq(name, line)` or `#new_seq(line)`

Create a new sequencer with an optional name (*name*), starting at a specific line number or section label (*line*).

`#pause_seq()` or `#pause_seq(name)`

Pause the calling sequencer or another sequencer specified by *name*.

`#resume_seq(name)`

Resume a paused sequencer by its *name*.

### Timing and Traversal

`#go_to(line)`

Change the calling sequencer's current line to the specified line number or section label (*line*).

`#play(section)`

Jump to and play a specific labeled section (*section*) of the sequence, returning afterwards.

`#reverse(times)`

Reverse the sequence playback direction for a given number of *times*.

`#set_bpm(bpm)`

Set the sequencer tempo to *bpm* beats per minute.

`#set_steps_per_beat(steps)`

Set the timeline resolution subdivisions to *steps* steps per beat.

`#set_inc(inc)`

Change the line-traversal step increment to *inc*.

`#wait_ms(ms)`

Pause script execution for *ms* milliseconds.

### Variable Editing

`#v_add_element(variable, element)`

Add a new *element* to the end of a given *variable* list.

`#v_find_n_rep(variable, find, replace, exclude)`

Find and replace values within a *variable*, skipping any specified in *exclude*.

`#v_insert_element(variable, element, position)`

Insert an *element* into a *variable* at the specified index *position*.

`#v_remove_element(variable, position)`

Remove an element from a *variable* at the given index *position*.

`#v_remove_elements_by_value(variable, value)`

Remove all elements matching a specific *value* from a *variable*.

`#v_set_counter(variable, counter)`

Set the internal index tracking counter for a *variable* to *counter*.

`#v_set_inc(variable, inc)`

Set the vector iteration step increment for a *variable* to *inc*.

## Variables

Variables Declarations are the third kind of instruction. They tell the sequencer to associate a name with a value or a list of values. These variables are global, meaning that if a sequencer executes a variable declaration,
all other sequencers can use that variable, and if one sequencer changes a variable's value, it changes it for every other sequencer.

### Single Value Variables

Single value variables are declared with the following syntax: `-name="value"`. This says to create a variables called `name` and set it's value to `value`.
To use this stored text later, use the `$` character. Variables can be used in all instructions except sections.

#### In a Message

`-cmajor_chord="c3|e3|g3"`

`|c2|$cmajor_chord|d5|` will be evaluated to `|c2|c3|e3|g3|d5|` before it is ran.

#### In a Function

`-beats_per_minute="80"`

`#set_bpm($beats_per_minute)` will be evaluated to `#set_bpm(80)` before it is ran.

#### In another Variable Declaration

`-chord="|c3|e3|g3|"`

`-expanded_scale="$scale|b3|"` will be evaluated to `-expanded_scale="|c3|e3|g3||b3|"` before it is ran.

### Multi Value Variables


