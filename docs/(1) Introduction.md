# Introduction
shoebill is a real time, scriptable MIDI sequencer, ideal for making unique, generative music.
It's important to note that shoebill is only capable of MIDI sequencing, that is, sending control change and note information. You will need another program, like a synthesizer or DAW, in order to catch these MIDI messages and interpret them into sound.

To use shoebill, write a script in a text file, then run shoebill and pass the name of the file in as an argument. If you'd like to quit the program, press 'q' while it's running.

shoebill reads a script one line at a time. Lines can either be MIDI messages, variable declarations, or function calls. If the program encounters a MIDI message, it will play it in-time, according to a user-set BPM which defaults to 100. Function calls and variable declarations happen still in sequence, but out of time, meaning they happen "instantly" as the program finds them.
