# Variables
Variables are a handy way to store strings of text that you find yourself commonly using. While more akin to macros than variables you might use in programming languages, the value of the variable can be reassigned while the program is running, so therefore the name variable makes more sense.

Before each line of script is read and evaluated by the program, it first checks for any variables present, then replaces them with their value. 
## Creating Variables
Variable declaration lines must start with the '-' character, followed by the name of the variable and an equal sign. Everything to the right of the equal sign will be the value of the variable.

`-cmaj=|ch1,c3|ch1,e3|ch1,g3|`

`-cnote="ch1,c7"`

## Using Variables
Before it evaluates a line of script, shoebill first checks if there are any variables that need to be resolved. Specifically, it scans the line for a '$' character, followed by one of your variable's names. Then, it replaces that text with the variables value.

For example, using the variables created above:

`$cmaj` will be replaced with `|ch1,c3|ch1,e3|ch1,g3|`

`|ch1,g3|$cnote|` will be `|ch1,g3|ch1,c3|` after the variable is replaced.

## Arrays (Variables with multiple values)
Variables can be assigned multiple values, by placing multiple strings in between brackets, seperated by commas. Note that if you want to include commas within an element, you will have to surround that element with double quotes.

`-cscale=[c3,d3,e3,f3,g3,a3,b3]`

`-var=["|ch1,c3|","|ch1,e3|"|`

The first time the variable is used, it will be replaced with the first value in the array. The second time the variable is used, it will be replaced with the second value in the array. This pattern continues until it reaches the end, where it loops back around to the first element.

For example, using the variables created above:

`|$cscale|` will be `|c3|`

`|$cscale|` will be `|d3|`

`|$cscale|` will be `|e3|`

## Nesting
Since shoebill checks all lines for variables, you can use variables in the declaration of other variables.
For example:

`-cnote=c3`

`-cchord=|$cnote|e3|g3|`

`$cchord` will be replaced with `|c3|e3|g3|`

## Variables Across Multiple Sequencers
Any variable declared by one sequencer is accessible by any sequencer. This also means that if one sequencer changes the value of a variable, it is now changed for all sequencers. Similarly, if one sequencer uses an array, then the next sequencer that uses that variable will then get the next element in that array.
