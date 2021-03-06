/*
 * =====================================================================================
 *
 *       Filename:  game_config.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04.02.2022 23:52:14
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  Daniel Kucharski (), progdk22@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


/* #####   HEADER FILE INCLUDES   ################################################### */
#include "game_assets.h"
#include "game_types.h"
#include "sdl_functions.h"
#include "game_config.h"
/* #####   MACROS  -  LOCAL TO THIS SOURCE FILE   ################################### */

/* #####   TYPE DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ######################### */

typedef enum
{
    MYGAME_GFX_BEACH = 1U,
    MYGAME_GFX_PLAY,
    MYGAME_GFX_TREES,
    MYGAME_GFX_TREES2,

} MYGame_Gfx_Ids;
/* #####   DATA TYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */

/* #####   VARIABLES  -  LOCAL TO THIS SOURCE FILE   ################################ */

MyGame_GfxAsset MyGame_GfxTable[] = {
         {"gfx/testyuv.bmp", NULL, NULL, .function_to_load_data.function_load_texture_renderer = &LoadImg2Texture} ,\
         {"gfx/img1.png", NULL, NULL, .function_to_load_data.function_load_texture_renderer = &LoadImg2Texture},
         {"gfx/rpg-maker-mv-tree-tile-based-video-game-rpg-maker-vx-role-playing-video-game-png-favpng-MHcum6JvDUqh8P3UuyHfBqhQY.jpg", NULL, NULL, .function_to_load_data.function_load_texture_renderer = &LoadImg2Texture}, \
         {"gfx/trees.png", NULL, NULL, .function_to_load_data.function_load_texture_renderer = &LoadImgPng2Texture}, \
         {NULL, NULL, NULL, NULL} \
};

MyGame_GfxAsset MyGame_GfxTableSoftware[] = {
         {"gfx/testyuv.bmp", NULL, NULL, .function_to_load_data.function_load_surface = &LoadImg2Surface} ,\
         {"gfx/img1.png", NULL, NULL, .function_to_load_data.function_load_surface = &LoadImg2Surface},
         {"gfx/rpg-maker-mv-tree-tile-based-video-game-rpg-maker-vx-role-playing-video-game-png-favpng-MHcum6JvDUqh8P3UuyHfBqhQY.jpg", NULL, NULL, .function_to_load_data.function_load_surface = &LoadImg2Surface}, \
         {"gfx/trees.png", NULL, NULL, .function_to_load_data.function_load_surface = &LoadImgPng2Surface}, \
         {NULL, NULL, NULL, NULL} \
};

MyGame_FontAsset MyGame_FontDefinition[] = {
    {"fonts/8-bit.ttf", 16, NULL},
    {"fonts/MyGirlIsRetroDEMO.ttf", 20, NULL},
    {NULL, 0, NULL}
};
/* #####   PROTOTYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */

/* #####   FUNCTION DEFINITIONS  -  EXPORTED FUNCTIONS   ############################ */

/* #####   FUNCTION DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ##################### */

