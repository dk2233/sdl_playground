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
#include "game_types.h"
#include "sdl_functions.h"
/* #####   MACROS  -  LOCAL TO THIS SOURCE FILE   ################################### */

/* #####   TYPE DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ######################### */

/* #####   DATA TYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */

/* #####   VARIABLES  -  LOCAL TO THIS SOURCE FILE   ################################ */
MyGame_GfxAsset MyGame_GfxTable[] = {
         {"gfx/testyuv.bmp", NULL, &LoadImg2Texture} ,\
        {"gfx/img1.png", NULL, &LoadImg2Texture},
         {NULL, NULL, NULL} \
};
/* #####   PROTOTYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */

/* #####   FUNCTION DEFINITIONS  -  EXPORTED FUNCTIONS   ############################ */

/* #####   FUNCTION DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ##################### */

/*  function that loads 
 *  all defined gfx_file_names
 *  according to table definition */
MyGame_ErrorType MyGame_Asset_Load(MyGame_GfxAsset *gfx_game_data, SDL_Renderer * renderer_p)
{
    MyGame_ErrorType retValue = ALL_OK;

    MyGame_GfxAsset *game_data;

    if (NULL != gfx_game_data)
    {
        game_data = gfx_game_data;

    }
    else {
        game_data = MyGame_GfxTable;
    }

    for(uint8_t iter=0U;  ; iter++)
    {
        if (NULL == game_data[iter].gfx_data_file_name)
        {
            break;
        }

        retValue = game_data[iter].function_to_load_data(game_data[iter].gfx_data_file_name,renderer_p ,&(game_data[iter].gfx_texture)); 

        if (MYGAME_ERROR == retValue)
        {
            break;
        }


    }

    return retValue;

}

