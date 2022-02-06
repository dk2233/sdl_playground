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

#include "SDL_keyboard.h"
#include "SDL_scancode.h"
#include "SDL_stdinc.h"
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
    int keys;
    const Uint8 *state;

    EventsState.KeysPressed_Union.Keys_u32 = 0U;
    if ( SDL_PollEvent(&event) >0 )
    {
        if (event.type == SDL_KEYDOWN)
        {
            state = SDL_GetKeyboardState(&keys);

            if (state[SDL_SCANCODE_Q])
            {

                EventsState.isQuit = 1;
            }
            if (state[SDL_SCANCODE_UP])
            {
                EventsState.KeysPressed_Union.Keys_bits.key_up = 1;

            }
            if (state[SDL_SCANCODE_DOWN])
            {
                EventsState.KeysPressed_Union.Keys_bits.key_down = 1;

            }
            if (state[SDL_SCANCODE_LEFT])
            {
                EventsState.KeysPressed_Union.Keys_bits.key_left = 1;

            }
             if (state[SDL_SCANCODE_RIGHT])
            {
                EventsState.KeysPressed_Union.Keys_bits.key_right = 1;

            }
        }
    }


    return &EventsState;

}
/* #####   FUNCTION DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ##################### */


