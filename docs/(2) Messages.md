# Messages
Messages are the way that the sequencer sends MIDI signals. Messages are encapsulation by the "|" character. There are two kinds of messages, note messages and cc messages. Many messages can be chained together on the same line, which all play at the same time. The following example will play a c5 and an e5 through channel 1 and set cc80 to 0.

`|ch1,c5|ch1,e5|ch1,cc80,0|`

## Sending Note Messages
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

## Sending CC Messages

Control Change messages have 3 parts, a MIDI channel, a cc number, and a value. The following line tells ch1 to set cc60 to 40.

`|ch1,cc60,40|`

Just like sending note messages, you can leave out the channel to send the message through the default channel, and use OFF as a replacement for a value of 0.
