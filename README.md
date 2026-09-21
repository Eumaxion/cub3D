*This project has been created as part of the 42 curriculum by mlima-si, dedantas.*

# cub3D
![Gameplay](assets/readme/gameplay.gif)

> A 3D maze rendered from a 2D map using raycasting, inspired by the early-generation FPS engines.

**cub3D** is a project from the 42 curriculum focused on understanding the fundamentals behind a simple 3D rendering engine.

The project started with the challenge of parsing a map and transforming its 2D representation into a navigable 3D environment using raycasting. After building the core, I extended the project with additional features such as a minimap, mouse interaction and collision handling.

## 🎮 Features

* 2D map parsing and validation
* Raycasting-based 3D rendering
* Textured walls
* Player movement
* Camera rotation
* Wall collision detection
* Mouse interaction for camera control
* Real-time minimap
* Floor and ceiling rendering
* Window and game loop management
* Texture loading
* Error handling and input validation

## 🗺️ Minimap

The minimap provides a top-down representation of the current level while the player explores the environment.

It displays:

* Walls
* Walkable areas
* Player position
* Player orientation

This was implemented as an additional visualization layer on top of the main 3D renderer.

## 🖱️ Mouse Interaction

In addition to keyboard controls, the camera can be controlled using the mouse.

Mouse movement changes the player's viewing direction, making the navigation feel closer to a traditional first-person game.

## 🧱 Collision Detection

The player cannot walk through walls.

Before applying movement, the next position is checked against the map, preventing the player from entering blocked cells while still allowing smooth movement along walls.

## 🧠 How It Works

The core of the project is based on **raycasting**.

For every vertical column of the screen, a ray is projected from the player's position into the map.

The engine then:

1. Calculates the ray direction.
2. Determines the grid cells crossed by the ray.
3. Finds the first wall hit.
4. Calculates the distance between the player and the wall.
5. Corrects the distance to avoid the fisheye effect.
6. Calculates the height of the wall slice.
7. Determines the correct texture coordinate.
8. Draws the corresponding vertical column.

Repeating this process across the screen creates the illusion of a 3D environment from a 2D map.

## 🔄 Development Process

The project was developed progressively.

### 1. Parsing

The first stage focused on understanding and validating the map structure.

This included handling:

* Map boundaries
* Player position
* Textures
* Colors
* Valid characters
* Invalid configurations

### 2. Raycasting

Once the map could be correctly interpreted, the next step was turning the 2D representation into a 3D view.

This required working with:

* Vectors
* Angles
* Trigonometry
* Grid traversal
* Ray-wall intersections
* Perspective projection

### 3. Player Movement

After rendering the environment, player navigation was implemented with keyboard input and collision checks.

### 4. Bonus Features

With the core engine working, I extended the project with:

* 🗺️ Minimap
* 🖱️ Mouse interaction
* 🧱 Collision improvements

These additions made the project feel much more like a small playable engine rather than only a rendering exercise.

## 🛠️ Technologies

* C
* MiniLibX
* Makefile
* Linux / Unix environment
* Raycasting
* Basic computer graphics
* Trigonometry and vector mathematics

## ▶️ Usage

Clone the repository:

```bash
git clone https://github.com/Eumaxion/cub3D.git
cd cub3D
```

Compile the project:

```bash
make
```

Run it with a valid map:

```bash
./cub3D maps/example.cub
```

## 🎮 Controls

| Key       | Action        |
| --------- | ------------- |
| `W`       | Move forward  |
| `S`       | Move backward |
| `A`       | Move left     |
| `D`       | Move right    |
| `←` / `→` | Rotate camera |
| Mouse     | Rotate camera |
| `ESC`     | Exit          |

> The exact controls may vary depending on the final implementation.

## 📚 What I Learned

This project was a deep dive into the foundations of real-time rendering.

Some of the main concepts explored were:

* Raycasting
* Vector mathematics
* Trigonometry
* Perspective projection
* Texture mapping
* Event handling
* Collision detection
* Memory management
* Parsing and validation
* Game loops
* 2D → 3D visualization

The biggest takeaway was understanding how relatively simple mathematical operations can be combined to create the illusion of a 3D world.

## 🚀 Future Improvements

Possible improvements include:

* Animated textures
* Doors
* Sprites
* More advanced lighting
* Weapon rendering
* Enemies
* Additional maps
* Performance optimizations

---

Made as part of the **42 curriculum**.
