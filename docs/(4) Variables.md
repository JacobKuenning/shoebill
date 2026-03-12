# Variables
## Creating Variables
Variable declaration lines must start with the '-' character, then the name of the variable, then an equal sign, then the value of the variable. Variables in shoebill are more akin to macros then they are variables in any programming language, however, their value can change if they are redefined later in the script. 

`-cmaj=|ch1,c3|ch1,e3|ch1,g3|`

`-cnote="ch1,c7"`

You may also use variables within defined variables.

`-chord=|$cnote|ch1,e5|ch1,g5|`

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
