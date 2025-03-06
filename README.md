# cub3d

3D game built with C, utilizing the ray casting technique pioneered by the FPS (first-person shooter) game Wolfenstein.

## Development timeline

### 6.3.2025
- Ceiling and floor images now drawn on the screen and filled with correct color from map file.

### 3.3.2025

- Player now moves around the minimap, need to make movement smoother with float/double coordinates.
- Moved minimap initialization/rendering into its separate file, ```srcs/minimap/init_minimap.c```.
- Changed ```key_hooks``` function to listen to ```mlx_is_key_down``` instead of ```MLX_PRESS```.

### 28.2.2025

- Map parser ready.
- Successfully combined parser logic with rest of the code.

### 27.2.2025

- Minimap images rendering in window.

### 25.2.2025

- Officially starting project.
- Milad works on map parser, Paula on minimap.