/*
 * =====================================================================================
 *
 *       Filename:  game_events.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03.02.2022 00:06:01
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  Daniel Kucharski (), progdk22@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

/* #####   HEADER FILE INCLUDES   ################################################### */

#include "game_types.h"
#include "SDL_events.h"
/* #####   MACROS  -  LOCAL TO THIS SOURCE FILE   ################################### */

/* #####   TYPE DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ######################### */

/* #####   DATA TYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */

/* #####   VARIABLES  -  LOCAL TO THIS SOURCE FILE   ################################ */



/* #####   PROTOTYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */

/* #####   FUNCTION DEFINITIONS  -  EXPORTED FUNCTIONS   ############################ */

MyGameEvent_struct * MyGame_CheckEvents(void)
{
    static MyGameEvent_struct EventsState;
    SDL_Event event;

    if ( SDL_PollEvent(&event) >0 )
    {
        if (event.type == SDL_KEYDOWN)
        {
            EventsState.isQuit = 1;
        }
    }


    return &EventsState;

}
/* #####   FUNCTION DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ##################### */


