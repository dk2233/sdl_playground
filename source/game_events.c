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

/* #####   MACROS  -  LOCAL TO THIS SOURCE FILE   ################################### */

/* #####   TYPE DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ######################### */

/* #####   DATA TYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */

/* #####   VARIABLES  -  LOCAL TO THIS SOURCE FILE   ################################ */

/* #####   PROTOTYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */

/* #####   FUNCTION DEFINITIONS  -  EXPORTED FUNCTIONS   ############################ */
MyGameEvent_struct MyGame_CheckEvents(void)
{
    MyGameEvent_struct events;

    if ( SDL_PollEvent(&event) >0 )
    {
        if (event.type == SDL_KEYDOWN)
        {
            isQuit = 1;
            break;
        }
    }


    if (i > GfxItems->window_surface_struct_p->clip_rect.h)
    {
        direction = DIRECTION_UP;
    }
    else if (i<0)
    {
        direction = DIRECTION_DOWN;

    }
    else
    {
    }

}
/* #####   FUNCTION DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ##################### */


