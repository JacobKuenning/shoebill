# Functions

Function calls must start with the '#' character followed by the name of the function and the correct number of arguments within closed parenthesis

## Control Changes

**#start_cc**(*cc, start, end, time*)

Change CC *cc* from *start* to *end* over the course of *time* seconds

## Sequencer Creation and Control

**#end_seq**() or **#end_seq**(*name*)

Kill the sequencer with the name *name*. Otherwise, kill the sequencer that called this function.

**#new_seq**(*name, line*)

Create a new sequencer with the name *name*, starting at line number *line*.

**#pause_seq**() or **#pause_seq**(*name*)

Pause the calling sequencer or another by name.

**#resume_seq**(*name*)

Resume a sequencer by name.

## Timing and Traversal

**#go_to**(*line*)

Change the calling sequencers current line to *line*

**#play**(*section*)

**#reverse**(*times*)

**#set_bpm**(*bpm*)

**#set_inc**(*inc*)

**#set_steps_per_beat**(*steps*)

**#wait_ms**(*ms*)

## Variable Editing

**#v_find_n_rep**(*variable, find, replace, exclude*)

**#v_insert_element**(*variable, element, position*)

**#v_remove_element**(*variable, position*)

**#v_remove_elements_by_value**(*variable, value*)

**#v_set_counter**(*variable, counter*)

**#v_set_inc**(*variable, inc*)
