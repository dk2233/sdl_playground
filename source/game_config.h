#ifndef GAME_CONFIG_HEADER
#define GAME_CONFIG_HEADER


/*
 * =====================================================================================
 *
 *       Filename:  game_config.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04.02.2022 23:53:54
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  Daniel Kucharski (), progdk22@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

/*-----------------------------------------------------------------------------
 * HEADER INCLUDES 
 *-----------------------------------------------------------------------------*/

#include "SDL_ttf.h"
#include "game_assets.h"
/*-----------------------------------------------------------------------------
 * MACROS, DEFINES 
 *-----------------------------------------------------------------------------*/
#define MYGAME_FONTS_NUMBER 1U
#define MYGAME_FONT   "fonts/8-bit.ttf"

#define WORLD_SIZE_X   100U
#define WORLD_SIZE_Y   100U
#define WORLD_MAP_TYPES 20U

/*-----------------------------------------------------------------------------
 * TYPEDEFS 
 *-----------------------------------------------------------------------------*/

typedef enum
{
    MYGAME_GFX_BEACH = 0U,
    MYGAME_GFX_PLAY,
    MYGAME_GFX_TREES,
    MYGAME_GFX_HOMES,
    MYGAME_PARTS_DEFINED, /*  this is defined to  */ 
} MYGame_Gfx_Ids;


/*  this depends on enum that defines 
 *  order of all graphics
 *  */
typedef struct 
{
   MYGame_Gfx_Ids gfx_id;
   SDL_Rect gfx_size_properties;
} MyGame_AssetPartDefinition;
/*-----------------------------------------------------------------------------
 * GLOBAL FUNCTION PROTOTYPES 
 *-----------------------------------------------------------------------------*/

extern MyGame_GfxAsset MyGame_GfxTable[];

extern MyGame_GfxAsset MyGame_GfxTableSoftware[];

extern MyGame_FontAsset MyGame_FontDefinition[];

extern MyGame_AssetPartDefinition  MyGame_PartTableDef[];

#endif
/* end of game_config.h */



