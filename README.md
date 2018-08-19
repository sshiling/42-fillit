# fillit
## Algorithmic project 
Fillit is the second project in the study program at School 42 (UNIT Factory).
The main goal is to create the smallest possible square from random Tetris figures. <br />
Each Tetris figure is named Tetriminos.

All functions are created in accordance with Norm - the bunch of rules how code should be formatted.

**!NOTE** <br />
Because of 42 School norm requirements: <br />
* All variables are declared and aligned at the top of each function <br />
* Each function can't have more then 25 lines of code <br />
* C++ style code commenting is forbidden <br />
* Project should be created just with allowed functions otherwise it's cheating. <br />

### General requirements from the task:
• Your project must be written in C and must respect the Norme coding standard. <br />
• **The allowed functions are : exit, open, close, write, read, malloc and free.** <br />
• Your Makefile must compile your code without relinks. <br />
• It must contain the following rules : all, clean ,fclean et re. <br />
• You must compile your binary with the Wall, Wextra and Werror flags. Any other flag are forbidden , especially those for optimising purposes. <br />
• The binary must be named fillit and located in the root directory of your repository. <br />

### The description of a Tetriminos must respect the following rules:
• Precisely 4 lines of 4 characters, each followed by a new line (well... a 4x4 square). <br />
• A Tetrimino is a classic piece of Tetris composed of 4 blocks. <br />
• Each character must be either a block character(’#’ ) or an empty character (’.’). <br />
• Each block of a Tetrimino must touch at least one other block on any of his 4 sides (up, down, left and right). <br />

#### A few examples of valid descriptions of Tetriminos:

```
####      ....      .##.      ....      .#..      ....      ....      ##..      ....
....      ....      ..##      .##.      ###.      ##..      .##.      .#..      ....
....      ##..      ....      ##..      ....      #...      ..#.      .#..      ..##
....      ##..      ....      ....      ....      #...      ..#.      ....      ..##
```

#### A few examples of invalid descriptions of Tetriminos:

```
####      ...#      ##...     #.        ....      ..##      ####      ,,,,      .HH.
...#      ..#.      ##...     ##        ....      ....      ####      ####      HH..
....      .#..      ....      #.        ....      ....      ####      ,,,,      ....
....      #...      ....                ....      ##..      ####      ,,,,      ....
```

#### Example input and expected output:
```
$> cat sample.fillit | cat -e
...#$
...#$
...#$
...#$
$
....$
....$
....$
####$
$
.###$
...#$
....$
....$
$
....$
..##$
.##.$
....$
$
....$
.##.$
.##.$
....$
$
....$
....$
##..$
.##.$
$
##..$
.#..$
.#..$
....$
$
....$
###.$
.#..$
....$
$> ./fillit sample.fillit | cat -e
ABBBB.$
ACCCEE$
AFFCEE$
A.FFGG$
HHHDDG$
.HDD.G$
$>
```

### In this project I used: 
• linked lists, char arrays and double char arrays <br />
• reading from the standard input and from the file <br />
• backtracking algorithm <br />
• recursion <br />
