# Functions

Function calls must start with the '#' character followed by the name of the function and the correct number of arguments within closed parenthesis

## Control Changes

`#start_cc(num, start, end, t)`

Change CC *cc*'s value from *start* to *end* over the course of *t* seconds

## Sequencer Creation and Control

`#end_seq()` or `#end_seq(name)`

Kill the sequencer with the name *name*. Otherwise, kill the sequencer that called this function.

`#new_seq(name, line)`

Create a new sequencer with the name *name*, starting at line number *line*.

`#pause_seq()` or `#pause_seq(name)`

Pause the calling sequencer or another by name.

`#resume_seq(name)`

Resume a sequencer by name.

## Timing and Traversal

`#go_to(line)`

Change the calling sequencer's current line to *line*.

`#play(section)`

Play a specific section of the sequence.

`#reverse(times)`

Reverse the sequence playback for a given number of *times*.

`#set_bpm(bpm)`

Set the sequencer tempo to *bpm* beats per minute.

`#set_inc(inc)`

Set the increment value to *inc*.

`#set_steps_per_beat(steps)`

Set the resolution to *steps* steps per beat.

`#wait_ms(ms)`

Pause execution for *ms* milliseconds.

## Variable Editing

`#v_find_n_rep(variable, find, replace, exclude)`

Find and replace values within a *variable*, skipping any specified in *exclude*.

`#v_insert_element(variable, element, position)`

Insert an *element* into a *variable* at the specified *position*. Used to insert variables into arrays or to turn a variable into an array.

`#v_remove_element(variable, position)`

Remove an element from a *variable* at the specified *position*.

`#v_remove_elements_by_value(variable, value)`

Remove all elements matching a specific *value* from a *variable*.

`#v_set_counter(variable, counter)`

Set the counter for a *variable* to *counter*.

`#v_set_inc(variable, inc)`

Set the increment value for a *variable* to *inc*.
