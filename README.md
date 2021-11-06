# Game of life but Formula 1 version :checkered_flag: #

### Overview ###
This is a zero-player game - the grid evolves from given initial state

### Initial configuration ###
In order to start the game there is provided a file with initial 
configuration - config.txt, which syntax is as follows:

*fist line* configures whether to use console or QT version of game:
   ` [CONSOLE | QT]`
*second line* consists of 2 digits - pixels respectively widthways and lengthways of the grid
where 
- `MIN_WIDTH` = 20, `MAX_WIDTH` = 50,
- when QT mode: `MIN_LENGTH` = 20, `MAX_LENGTH` = 50
- when console mode: `MIN_LENGTH` = 10, `MAX_LENGTH` = 20

*third line* consists of the name of file which initial state - as default there is a initial state provided


#### Syntax of the file which initial state ####
*all lines* are the list of live cells on digit in format `X Y`, 
`X in [1,2,...,MAX_WIDTH], Y in [1,2,...,MAX_LENGTH]`