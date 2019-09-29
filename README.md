# Raise the terrain
Renders a terrain using isometric projection given a set of altitudes.

## Prerequisites
* Usage: terrain file
* Draw a grid using an isometric projection
* The grid must be described in a file (see above example)
* The color used to draw the grid doesn’t matter (same for the background)
* The grid doesn’t need to be exactly the same as the one shown above. But make sure you have a coherent isometric projection.
* Your grid must be centered and takes as much space as possible on the screen. We should be able to see the whole screen.
* Your program should end when the user is pressing the ESC key

## Requirements
* [SDL2](https://wiki.libsdl.org/Installation)

## Compilation
`$ gcc -Wall -Werror -Wextra -pedantic *.c -o terrain`

## Usage
`$ ./terrain <file_path>`
