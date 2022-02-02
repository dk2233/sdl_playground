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
#include "game_types.h"
/* #####   MACROS  -  LOCAL TO THIS SOURCE FILE   ################################### */

/* #####   TYPE DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ######################### */

/* #####   DATA TYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */

/* #####   VARIABLES  -  LOCAL TO THIS SOURCE FILE   ################################ */
const MyGame_Data MyGame_GfxTable = {

    .background_number = 1,
    .background = {
        {"gfx/testyuv.bmp", NULL, LoadImgBmp2Texture},
    },

    .player_number = 1,
    .players = {
        {"gfx/img1.png", NULL, LoadImgPng2Texture},
    },

    .additional_number = 0,
    .additional_data = NULL,
};
/* #####   PROTOTYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */

/* #####   FUNCTION DEFINITIONS  -  EXPORTED FUNCTIONS   ############################ */

/* #####   FUNCTION DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ##################### */

/*  function that loads 
 *  all defined gfx_file_names
 *  according to table definition */
MyGame_ErrorType MyGame_Asset_Load(MyGame_Data *gfx_game_data)
{
    MyGame_ErrorType retValue = ALL_OK;

    MyGame_Data *game_data;

    if (NULL != gfx_game_data)
    {
        game_data = gfx_game_data;

    }




    return retValue;
}
