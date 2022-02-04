/*
 * =====================================================================================
 *
 *       Filename:  game_loop_renderer.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02.02.2022 19:46:47
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  Daniel Kucharski (), progdk22@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


/* #####   HEADER FILE INCLUDES   ################################################### */

#include "SDL.h"
#include "SDL_events.h"
#include "SDL_pixels.h"
#include "SDL_rect.h"
#include "SDL_render.h"
#include "SDL_rwops.h"
#include "SDL_surface.h"
#include "SDL_video.h"
#include "definitions.h"
#include "game_types.h"
#include "sdl_functions.h"
#include "SDL_image.h"
#include "SDL_timer.h"
#include "game_loop.h"
#include "game_assets.h"
#include "game_events.h"
/* #####   MACROS  -  LOCAL TO THIS SOURCE FILE   ################################### */

/* #####   TYPE DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ######################### */

/* #####   DATA TYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */

/* #####   VARIABLES  -  LOCAL TO THIS SOURCE FILE   ################################ */

static MyGame_GfxProperties *GfxItems;
static SDL_Color MyGameBackground = {100, 100,0 ,255};


/* #####   PROTOTYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */
static MyGame_ErrorType ClearRenderer(SDL_Color color);

static void MyGame_UpdateView(MyGameEvent_struct *event, MyGame_GfxProperties *GfxItems);


/* #####   FUNCTION DEFINITIONS  -  EXPORTED FUNCTIONS   ############################ */

void MyGame_MainLoopRenderer(void)
{
    SDL_Event event;
    int isQuit = 0;
    int direction = DIRECTION_DOWN;
    MyGame_ErrorType gfxStatus = ALL_OK ;
    MyGameEvent_struct *Events;

    GfxItems = MyGame_GetGfxItems();

    /* loading defined gfx */
    gfxStatus = MyGame_Asset_Load(NULL, GfxItems->renderer_struct_p);


    while(1)
    {


        ClearRenderer(MyGameBackground);

        Events = MyGame_CheckEvents();
        


        MyGame_UpdateView(Events, GfxItems);

        gfxStatus = MyGame_RefreshGfx(GfxItems->renderer_struct_p, NULL);
        if ((Events->isQuit == 1) || (gfxStatus != ALL_OK))
        {
            break;

        }
    }

} 

/* #####   FUNCTION DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ##################### */
static MyGame_ErrorType ClearRenderer(SDL_Color color)
{
    MyGame_ErrorType retValue = ALL_OK;
    retValue = (MyGame_ErrorType)SDL_SetRenderDrawColor(GfxItems->renderer_struct_p, color.r, color.g, color.b, color.a);

    if (ALL_OK == retValue)
    {
        retValue = (MyGame_ErrorType)SDL_RenderClear(GfxItems->renderer_struct_p);
    }

    return retValue; 
}


static void MyGame_UpdateView(MyGameEvent_struct *event, MyGame_GfxProperties *GfxItems)
{
    int i = 0;
    int direction = DIRECTION_DOWN;
    int windows_w, windows_h;


    SDL_GetWindowSize(GfxItems->window_struct_p, &windows_w, &windows_h);

    if (i > windows_h) 
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
