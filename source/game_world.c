/*
 * =====================================================================================
 *
 *       Filename:  game_world.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  17.02.2022 01:13:53
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  Daniel Kucharski (), progdk22@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


/* #####   HEADER FILE INCLUDES   ################################################### */
#include "game_config.h"
#include "game_world.h"
#include <stdlib.h>
/* #####   MACROS  -  LOCAL TO THIS SOURCE FILE   ################################### */

/* #####   TYPE DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ######################### */

/* #####   DATA TYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */

/* #####   VARIABLES  -  LOCAL TO THIS SOURCE FILE   ################################ */

Uint8 MyGame_WorldArray[WORLD_SIZE_X][WORLD_SIZE_Y] = {0};
/* #####   PROTOTYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */

/* #####   FUNCTION DEFINITIONS  -  EXPORTED FUNCTIONS   ############################ */

void MyGame_RandomWorldCreate(void)
{
    for(int ix = 0U; ix < WORLD_SIZE_X; ix++)
    {
        for(int iy = 0U; iy < WORLD_SIZE_Y; iy++)
        {
            MyGame_WorldArray[ix][iy] = rand() % WORLD_MAP_TYPES;

        }
    }
}


/* #####   FUNCTION DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ##################### */

