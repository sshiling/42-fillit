# fillit
## Algorithmic project. The main goal is to create the smallest possible square from random Tetris figures

Each Tetris figure is named Tetriminos.

**The description of a Tetriminos must respect the following rules :**
• Precisely 4 lines of 4 characters, each followed by a new line (well... a 4x4 square).
• A Tetrimino is a classic piece of Tetris composed of 4 blocks.
• Each character must be either a block character(’#’ ) or an empty character (’.’).
• Each block of a Tetrimino must touch at least one other block on any of his 4 sides (up, down, left and right).

A few examples of valid descriptions of Tetriminos:
....
..##
..#.
..#.

....
....
..##
..##

####
....
....
....


|               |                                                                           |
| ------------- | --------------------------------------------------------------------------------------| 
| ....
..##
..#.
..#. |  |
| ....
....
..##
..## |  |
|  |  |
|  |  |
|  |  |
|  |  |


.... .... #### .... .##. .... .#.. .... ....
..## .... .... .... ..## .##. ###. ##.. .##.
..#. ..## .... ##.. .... ##.. .... #... ..#.
..#. ..## .... ##.. .... .... .... #... ..#.

.... .... #### .... .##. .... .#.. .... ....
..## .... .... .... ..## .##. ###. ##.. .##.
..#. ..## .... ##.. .... ##.. .... #... ..#.
..#. ..## .... ##.. .... .... .... #... ..#.
