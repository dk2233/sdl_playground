/*
 * =====================================================================================
 *
 *       Filename:  game_assets.c
 *
 *    Description: loading all game data  
 *
 *        Version:  1.0
 *        Created:  02.02.2022 21:06:55
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
#include "SDL_render.h"
#include "SDL_surface.h"
#include "SDL_ttf.h"
#include "game_types.h"
#include "sdl_functions.h"
#include "game_config.h"
#include "definitions.h"
/* #####   MACROS  -  LOCAL TO THIS SOURCE FILE   ################################### */

/* #####   TYPE DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ######################### */

/* #####   DATA TYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */

/* #####   VARIABLES  -  LOCAL TO THIS SOURCE FILE   ################################ */

/* #####   PROTOTYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */

/* #####   FUNCTION DEFINITIONS  -  EXPORTED FUNCTIONS   ############################ */

/* #####   FUNCTION DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ##################### */

/*  function that loads 
 *  all defined gfx_file_names
 *  according to table definition 
 *
 *  please define MyGame_GfxTable - 
 *  or give your own as argument
 *  so you can create any number of valid MyGame_GfxAsset table types
 *  */
MyGame_ErrorType MyGame_Asset_Load(MyGame_GfxAsset *gfx_game_data, SDL_Renderer * renderer_p, SDL_Surface *window_surface_struct_p)
{
    MyGame_ErrorType retValue = ALL_OK;
    MyGame_ErrorType gfxStatus = ALL_OK ;
    MyGameEvent_struct *Events;
    MyGame_GfxAsset *game_data;

    if (NULL != gfx_game_data)
    {
        game_data = gfx_game_data;

    }
    else {
        game_data = MyGame_GfxTable;
    }

    for(uint8_t iter = 0U;  ; iter++)
    {
        if (NULL == game_data[iter].gfx_data_file_name)
        {
            break;
        }

        if (renderer_p != NULL)
        {
            retValue = game_data[iter].function_to_load_data.function_load_texture_renderer(game_data[iter].gfx_data_file_name,renderer_p ,&(game_data[iter].gfx_texture)); 
        }
        else
        {
            retValue = game_data[iter].function_to_load_data.function_load_surface(game_data[iter].gfx_data_file_name, &(game_data[iter].gfx_surface), window_surface_struct_p );
        }

        if (MYGAME_ERROR == retValue)
        {
            printf(" some error during loading of %s \n",game_data[iter].gfx_data_file_name);
            break;
        }


    }

    MyGame_Fonts[0] =  MyGame_LoadFont(MYGAME_FONT);
 
    return retValue;
}

