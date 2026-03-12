# Introduction
shoebill is a real time, scriptable MIDI sequencer, ideal for making unique, generative music.
It's important to note that shoebill is only capable of MIDI sequencing, that is, sending control change and note information. You will need another program, like a synthesizer or DAW, in order to catch these MIDI messages and interpret them into sound.

To use shoebill, write a script in a text file, then run shoebill and pass the name of the file in as an argument. If you'd like to quit the program, press 'q' while it's running.

# Documentation
## Basics
shoebill interprets your script one line at a time. Lines can either be MIDI messages, variable declarations, and function calls. If the program encounters a MIDI message, it will play it in-time, according to a user-set BPM which defaults to 100. Function calls and variable declarations happen out of time.

## Messages
Messages are the backbone of shoebill. When 

## Functions
Function lines must start with the '#' character, then the name of the function, then open and closed parenthesis.

## Variables
# Creating Variables
Variable declaration lines must start with the '-' character, then the name of the variable, then an equal sign, then the value of the variable. Variables in shoebill are more akin to macros then they are variables in any programming language, however, their value can change if they are redefined later in the script. 

`-cmaj=|ch1,c3|ch1,e3|ch1,g3|`
`-cnote="ch1,c7"`

# Using Variables
To use a variable, type '$' then the name of the variable. shoebill replaces any variables in a line with the associated value before the line is evaluated. For example, the line
`$cmaj`
will be replaced with it's value defined in the previous section
`|ch1,c3|ch1,e3|ch1,g3|`

Simlarly,
`|$cnote|` 
will be replaced with
|ch1,c7|

## Sections

## Randomization