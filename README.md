# Raise the terrain
Renders a terrain using isometric projection with a given set of 64 altitudes.

## Requirements
* [Install SDL2](https://wiki.libsdl.org/Installation)

## Compilation
```$ gcc *.c -o terrain -Wall -Werror -Wextra -pedantic `sdl2-config --cflags --libs` -lm```

## Usage
`$ ./terrain <file_path>`

## Controls
| Keyboard Shortcuts	| Description |
| --------------------- | ----------- |
| Escape		| Exits the program |
| Left Arrow		| Rotates the terrain clockwise |
| Right Arrow		| Rotates the terrain counter-clockwise |

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
