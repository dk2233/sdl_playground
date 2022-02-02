#ifndef GAME_ASSETS_HEADER
#define GAME_ASSETS_HEADER


/*
 * =====================================================================================
 *
 *       Filename:  game_assets.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02.02.2022 21:16:28
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


#include "SDL_render.h"
#include "game_types.h"
#include "stdint.h"
#include <bits/stdint-uintn.h>

/*-----------------------------------------------------------------------------
 * MACROS, DEFINES 
 *-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 * TYPEDEFS 
 *-----------------------------------------------------------------------------*/
typedef struct 
{
    char * gfx_data_file_name;
    SDL_Texture *gfx_texture;
    MyGame_ErrorType (* function_to_load_data)(char * gfx_file_name, SDL_Texture * texture);

} MyGame_GfxAsset;


typedef  struct
{
    const uint8_t background_number;
    MyGame_GfxAsset **background;
    
    const uint8_t player_number;
    MyGame_GfxAsset **players;

    const uint8_t additional_number;
    MyGame_GfxAsset **additional_data;

}MyGame_Data;

/*-----------------------------------------------------------------------------
 * GLOBAL FUNCTION PROTOTYPES 
 *-----------------------------------------------------------------------------*/

/*  function that loads 
 *  all defined gfx_file_names
 *  according to table definition */
extern MyGame_ErrorType MyGame_Asset_Load(MyGame_Data *gfx_game_data);

#endif
/* end of game_assets.h */



