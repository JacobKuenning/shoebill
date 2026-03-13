# Functions
Function calls must start with the '#' character followed by the name of the function and the correct number of arguments within closed parenthesis

## Timing and Traversal
**set_bpm(bpm)**
**set_steps_per_beat(steps)**
**wait_ms(ms)**
**set_inc(inc)**
**reverse(times)**
**go_to(line)**
**play(section)**

## Variable Editing
**v_find_n_rep(variable, find, replace, exclude)**
**v_set_inc(variable, inc)**
**v_set_counter(variable, counter)**
**v_insert_element(variable, element, position)**
**v_remove_element(variable, position)**
**v_remove_elements_by_value(variable, value)**

## Sequencer Creation and Control
**new_seq(name, line)**
**end_seq() or end_seq(name)**
**pause_seq() or pause_seq(name)**
**resume_seq(name)**

## Control Changes
**start_cc(cc, start, end, time)
