# Introduction
shoebill is a real time, scriptable MIDI sequencer, ideal for making unique, generative music.
It's important to note that shoebill is only capable of MIDI sequencing, that is, sending control change and note information. You will need another program, like a synthesizer or DAW, in order to catch these MIDI messages and interpret them into sound.

To use shoebill, write a script in a text file, then run shoebill and pass the name of the file in as an argument. If you'd like to quit the program, press 'q' while it's running.

# Documentation
## Basics
shoebill interprets your script one line at a time. Lines can either be MIDI messages, variable declarations, or function calls. If the program encounters a MIDI message, it will play it in-time, according to a user-set BPM which defaults to 100. Function calls and variable declarations happen still in sequence, but out of time, meaning they happen "instantly" as the program finds them.

## Messages
Messages are encapsulation by the "|" character. There are two kinds of messages, note messages and cc messages. Many messages can be chained together on the same line, which all play at the same time. The following example will play a c5 and an e5 through channel 1 and set cc80 to 0.

`|ch1,c5|ch1,e5|ch1,cc80,0|`

### Sending Note Messages
Note messages have 3 fields, a MIDI Channel, a note, and a velocity. The following will make MIDI channel 2 play a C3, with a velocity of 80.

`|ch2,c3,80|`

If you do not include a velocity, it will default to 127, which is the maximum.

`|ch3,c3|`

If you do not include a channel, it will send the message through the default channel, which can be set in the config.

`|c3|`

`|c3,60|`

OFF can be used as a substitute for a velocity of zero, which means the note is no longer being played.

`|ch1,c3,OFF|`

OFF can also be used to turn off all notes that have been played by a particular channel

`|ch4,OFF|`

### Sending CC Messages

Control Change messages have 3 parts, a MIDI channel, a cc number, and a value. The following line tells ch1 to set cc60 to 40.

`|ch1,cc60,40|`

Just like sending note messages, you can leave out the channel to send the message through the default channel, and use OFF as a replacement for a value of 0.

## Functions
Function lines must start with the '#' character, then the name of the function, then open and closed parenthesis.

## Variables
# Creating Variables
Variable declaration lines must start with the '-' character, then the name of the variable, then an equal sign, then the value of the variable. Variables in shoebill are more akin to macros then they are variables in any programming language, however, their value can change if they are redefined later in the script. 

`-cmaj=|ch1,c3|ch1,e3|ch1,g3|`

`-cnote="ch1,c7"`

You may also use variables within defined variables.

`-chord=|$cnote|ch1,e5|ch1,g5|`

# Using Variables
To use a variable, type '$' then the name of the variable. shoebill replaces any variables in a line with the associated value before the line is evaluated. 
For example, the line

`$cmaj`

will be replaced with it's value defined in the previous section

`|ch1,c3|ch1,e3|ch1,g3|`

Simlarly,

`|$cnote|` 

will be replaced with
`|ch1,c7|`

You can have multiple variables within a line

`|$cnote|$dnote|`

## Sections

## Randomization
