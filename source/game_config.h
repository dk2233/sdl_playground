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

extern MyGame_GfxAsset MyGame_GfxTable[];

extern MyGame_GfxAsset MyGame_GfxTableSoftware[];

extern MyGame_FontAsset MyGame_FontDefinition[];
/*-----------------------------------------------------------------------------
 * TYPEDEFS 
 *-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 * GLOBAL FUNCTION PROTOTYPES 
 *-----------------------------------------------------------------------------*/


#endif
/* end of game_config.h */



