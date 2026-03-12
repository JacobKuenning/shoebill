# Variables
Variables are a handy way to store strings of text that you find yourself commonly using. While more akin to macros than variables you might use in programming languages, the value of the variable can be reassigned while the program is running, so therefore the name variable makes more sense.

Before each line of script is read and evaluated by the program, it first checks for any variables present, then replaces them with their value. 
## Creating Variables
Variable declaration lines must start with the '-' character, followed by the name of the variable and an equal sign. Everything to the right of the equal sign will be the value of the variable.

`-cmaj=|ch1,c3|ch1,e3|ch1,g3|`

`-cnote="ch1,c7"`

## Using Variables
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
