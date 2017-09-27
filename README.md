# Color-Revolution-3d
Raycasting game base on [EPITECH wolf3d project] adding Color, Texture, Map Generator and Multiplayer

# Usage

```bash
./Color_Revolution_3d [map_file]
```

The project use the [CSFML librairie](www.sfml-dev.org/download/csfml/index-fr.php)

## Key

* Move Forward ==> Move Forward
* Move Back ==> Move Back
* Turn Left ==> Turn Left
* Turn Right ==> Turn Right
* Action ==> Color Block
* Pose ==> Move Door blocks

## Maps

Map example :
```bash
111111
1p1004
3030p5
100006
111111
```
0 => Empty block | 1-9 => Wall | 8 => Door | p => player start

## Texture (/texture/wall$)

For each block, an texture *wall[1-9]* is assigned in the folder */texture*. Textures files are 10x10 square compose with number between 0 and 9.
Higher is the number, lower is the luminosity.

## Macro

If u want more option you can modifie the macro of the file "/include/w3d.h".
_(a config file will be add soon, I do not advise you to change the uncited MACRO)_

* WIDTH -> width of the window
* HEIGHT -> height of the window
* PRECISION -> precision of the raycast
* SPEED -> move speed
* ROTATE -> angle for the rotation
* CROSS_HAIR -> size of the cross_hair
* OMBRAGE -> color a the corner wall
* R_DIST -> render distance
* TAILLE_MUR -> size of the walls
* MINIM_X && MINIM_Y -> coordinate of the minimap
* MINIM_SIZE -> size of the minimap
