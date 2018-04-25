# fillit
## Algorithmic project 
The main goal is to create the smallest possible square from random Tetris figures. <br />
Each Tetris figure is named Tetriminos.

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

#### In this project I used: 
* reading from the standard input and from the file
* backtracking algorithm
* recursion
