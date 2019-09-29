# Raise the terrain
Renders a terrain using isometric projection with a given set of 64 altitudes.

## Prerequisites
* Usage: terrain file
* Draw a grid using an isometric projection
* The grid must be described in a file (see above example)
* The color used to draw the grid doesn’t matter (same for the background)
* The grid doesn’t need to be exactly the same as the one shown above. But make sure you have a coherent isometric projection.
* Your grid must be centered and takes as much space as possible on the screen. We should be able to see the whole screen.
* Your program should end when the user is pressing the ESC key

## Requirements
* [Install SDL2](https://wiki.libsdl.org/Installation)

## Compilation
`$ gcc -Wall -Werror -Wextra -pedantic *.c -o terrain`

## Usage
`$ ./terrain <file_path>`

## Example
```
$ cat altitudes.txt
120 60 40 60 20 -20 -80 -120
40 20 30 30 -10 -40 -90 -110
20 30 10 06 -6 -20 -26 -90
00 -6 10 10 -6 -20 -20 -40
-20 -20 -18 -14 -40 -20 -20 -30
-10 -10 -10 -10 -8 -20 -20 -30
20 10 10 10 10 04 10 -10
30 24 24 22 20 18 14 16
$ ./terrain altitudes.txt
```
![rendered terrain](https://i.imgur.com/s3gLh39.png)
