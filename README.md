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
`X in [0,1,2,...,MAX_WIDTH-1], Y in [0,1,2,...,MAX_LENGTH-1]`

### How it looks like with QT mode ###
<img src="https://github.com/PaulinaGacek/AGH-Racing-Task3/blob/master/Helmets/game_visualisation.gif" width="200" height="300">

### How to run application ###
1. Make sure You have QT 6 installed on your PC
2. Go to the the directory where you have cloned project `cd <some_path>/GameOfLife`
3. Set a path to your qt cmake
   - `cmake DCMAKE_PREFIX_PATH="path/to/Qt/lib/cmake"` on windows
   - `cmake DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/` on Ubuntu
4. `mkdir -p cmake-build && cd cmake-build`
5. `cmake .. -G"Unix Makefiles"`
6. `make`