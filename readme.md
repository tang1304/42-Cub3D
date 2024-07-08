# Cub3D
This project is about recreating a 3D game with ray-casting, allowing us to navigate inside a maze. It is inspired by the first 3D game, **Wolfenstein 3D**.
The miniLibX (graphic library) must be used.

## Mandatory part:

### Authorized functions:
```
- open, close, read, write,
printf, malloc, free, perror,
strerror, exit
- All functions of the math
library (-lm man man 3 math)
- All functions of the MinilibX
```

### Objectives:

- Display different wall textures for the different side they are facing (North, South, East, West).

- Display different colors for the floor and the ceiling.

- The user can move through the maze using `W`, `A`, `S`, `D` keys.

- The user can rotate the view using `←` and `→` arrow keys.

- The user can exit the game using `Esc` key or the red cross of the window.

### Configuration:

To execute the program correctly, the user must provide a scene description file with a `.cub` extension. It has to respect these rules:

- The map must be composed of only 6 possible characters: `0` for an empty space,
`1` for a wall, and `N`,`S`,`E` or `W` for the player’s start position and spawning
orientation.

- The map must be closed/surrounded by walls, if not the program must return
an error.

- Except for the map content, each type of element can be separated by one or
more empty line(s).

- Except for the map content which always has to be the last, each type of
element can be set in any order in the file.

- Except for the map, each type of information from an element can be separated
by one or more space(s).

- The map must be parsed as it looks in the file. Spaces are a valid part of the
map and are up to you to handle. You must be able to parse any kind of map,
as long as it respects the rules of the map.

- Each element (except the map) firsts information is the type identifier (com-
posed by one or two character(s)), followed by all specific informations for each
object in a strict order such as :
	- North texture: ```NO ./path_to_north_texture```
	- South texture: ```SO ./path_to_south_texture```
	- North texture: ```EA ./path_to_east_texture```
	- North texture: ```WE ./path_to_west_texture```
	- Floor color: ```F x, y, z```
	- Ceiling color: ```C x, y, z```
   
	With x, y and z as **RGB** colors in range [0, 255].

### Usage:

Run ```make``` to compile the project, or ```make bonus``` to have the bonuses.

To execute it, run ```./cub3D map_config.cub``` or ```./cub3D_bonus map_config.cub```

## Bonus part:

- Wall collisions.
- A minimap system.
Use `+` and `-` to zoom in or out.
- Doors which can open and close.
`D` is the character used to do so. You need to place it between two walls. Use `e` to open and close.
- Animated sprites.
Use keys `1`, `2`, `3`, `4`, `5`, `6` to select between different weapons, and `q` to use them.
- Rotate the view with the mouse.
