*This project has been created as part of the 42 curriculum by mlima-si, dedantas.*

# cub3D

## Description

**cub3D** is a 3D graphics project from the 42 curriculum inspired by the rendering technique used in the classic game **Wolfenstein 3D**.

The goal of the project is to build a simple first-person game engine using the **raycasting** algorithm and the **MiniLibX** graphics library. The program parses a `.cub` configuration file containing texture paths, floor and ceiling colors, and a 2D map. After validating the input, the engine renders a textured 3D environment where the player can move and explore.

### Features

- Raycasting renderer
- DDA (Digital Differential Analyzer) wall detection
- Textured walls
- Floor and ceiling colors
- Collision detection
- Player movement and rotation
- Complete `.cub` file parser
- Map validation using Flood Fill
- XPM texture support
- Error handling

> **Bonus features were not implemented.**

---

# Instructions

## Requirements

- Linux
- GCC
- MiniLibX
- X11 development libraries

## Compilation

```bash
make
```

Clean object files:

```bash
make clean
```

Remove all generated files:

```bash
make fclean
```

Recompile everything:

```bash
make re
```

## Running

Run with a valid map:

```bash
./cub3D ./assets/maps/good/<map>.cub
```

Maps intended to test parser errors are available in:

```text
./assets/maps/bad/
```

---

# Controls

| Key | Action |
|------|--------|
| W | Move forward |
| S | Move backward |
| A | Strafe left |
| D | Strafe right |
| ← | Rotate left |
| → | Rotate right |
| ESC | Exit the game |

---

# Map Format

Example of a valid `.cub` file:

```text
NO ./assets/textures/north.xpm
SO ./assets/textures/south.xpm
WE ./assets/textures/west.xpm
EA ./assets/textures/east.xpm

F 45,35,25
C 20,20,35

111111111
100000001
1000N0001
100000001
111111111
```

---

# Resources

### References

- OpenGameArt – Skull Wall Texture  
  https://opengameart.org/content/skull-wall

- 42 Docs – cub3D  
  https://harm-smits.github.io/42docs/projects/cub3d

- RayCasting Tutorial Wiki  
  https://github.com/vinibiavatti1/RayCastingTutorial/wiki

- 3D Ray Casting Game with cub3D  
  https://devabdilah.medium.com/3d-ray-casting-game-with-cub3d-7a116376056a

### AI Usage

Artificial intelligence (ChatGPT) was used as a development assistant during the project. Its use was limited to:

- discussing implementation strategies;
- reviewing and improving code structure;
- explaining raycasting, DDA and Flood Fill algorithms;
- helping interpret MiniLibX behavior and debugging issues;
- improving code organization to comply with the 42 Norm;
- writing project documentation (README).

All design decisions, implementation, integration, debugging and final validation of the project were carried out by the authors.

---

# Authors

- **mlima-si**
- **dedantas**