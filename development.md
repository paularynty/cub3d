## Development timeline

### 12.3.2025

- Moved 3D rendering logic to mlx_loop_hook for better FPS/smoother movement.
- Started working on POV rotation with mouse.

### 11.3.2025

- Textures render successfully so far.
- Building logic to determine correct texture based on cardinal direction of a given wall.

### 10.3.2025

- Implemented player movement with double/float data type for smoother transitions.
- Started building camera rotation logic.
- Started building texture mapping/rendering logic.

### 8.3.2025

- Completed ray caster to successfully render 3D world.

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