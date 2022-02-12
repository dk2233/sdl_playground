/*
 * =====================================================================================
 *
 *       Filename:  loop.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  31.01.2022 12:39:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
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
#include "game_config.h"
#include "game_types.h"
#include "sdl_functions.h"
#include "SDL_image.h"
#include "SDL_timer.h"
#include "game_loop.h"
#include "game_assets.h"
#include "game_events.h"
#include "SDL_ttf.h"
/* #####   MACROS  -  LOCAL TO THIS SOURCE FILE   ################################### */

/* #####   TYPE DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ######################### */

/* #####   DATA TYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */

/* #####   VARIABLES  -  LOCAL TO THIS SOURCE FILE   ################################ */

static MyGame_GfxProperties *GfxItems;

static SDL_Color MyGameBackground = { 50, 250, 20, 255};

/* #####   PROTOTYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */

void ClearSurface(MyGame_GfxProperties *gfx_items , SDL_Colour fill_color);

static void MyGame_UpdateViewSoftware(MyGameEvent_struct *event, MyGame_GfxProperties *GfxItems, MyGame_GfxAsset *table);
/* #####   FUNCTION DEFINITIONS  -  EXPORTED FUNCTIONS   ############################ */

void MyGame_MainLoopSoftware(void)
{
    MyGame_ErrorType gfxStatus = ALL_OK ;
    MyGameEvent_struct *Events;


    GfxItems = MyGame_GetGfxItems();
    /* loading defined gfx */
    gfxStatus = MyGame_Asset_Load(MyGame_GfxTableSoftware, NULL, GfxItems->window_surface_struct_p);
    

    MAIN_GAME_LOOP
    {

        ClearSurface(GfxItems, MyGameBackground);


        Events = MyGame_CheckEvents();

        /*  prepare new gfx */
        MyGame_UpdateViewSoftware(Events, GfxItems, MyGame_GfxTableSoftware);

        gfxStatus = MyGame_RefreshGfx(NULL, GfxItems->window_struct_p);
        if ((Events->isQuit == 1) || (gfxStatus != ALL_OK))
        {
            break;
        }

    }


} 

/* #####   FUNCTION DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ##################### */


void ClearSurface(MyGame_GfxProperties *gfx_items , SDL_Color fill_color)
{
    SDL_FillRect(gfx_items->window_surface_struct_p, &gfx_items->window_surface_struct_p->clip_rect , SDL_MapRGB(gfx_items->window_surface_struct_p->format , fill_color.r, fill_color.g, fill_color.b));
    

}

static void MyGame_UpdateViewSoftware(MyGameEvent_struct *event, MyGame_GfxProperties *GfxItems, MyGame_GfxAsset *table)
{
    static SDL_Rect delta = {0, 0, 0 , 0};
    int direction = DIRECTION_DOWN;
    int windows_w, windows_h;
    int nr = 3;
    int texture_w, texture_h;
    Uint8 alpha = 0U;
    
    int w = 400;
    int h = 50*4;

    if (event->KeysPressed_Union.Keys_bits.key_down == SDL_TRUE)
    {
        delta.y++;
    }
    
    if (event->KeysPressed_Union.Keys_bits.key_up == SDL_TRUE)
    {
        delta.y--;
    }
    if (event->KeysPressed_Union.Keys_bits.key_left == SDL_TRUE)
    {
        delta.x--;
    }
    if ( event->KeysPressed_Union.Keys_bits.key_right == SDL_TRUE) {
    delta.x++;
    }


    SDL_Rect dest = {0, 0, w, h};

    SDL_Rect src = {0 + delta.x,0 + delta.y, w, h};



    SDL_GetWindowSize(GfxItems->window_struct_p, &windows_w, &windows_h);

    if (delta.y > windows_h) 
    {
        direction = DIRECTION_UP;
    }
    else if (delta.y<0)
    {
        direction = DIRECTION_DOWN;
    }
    else
    {
    }

    SDL_Rect dest_bg = {0, 0, windows_w, windows_h};

    SDL_Rect src_bg = {0,0, 600, 600};

    /*  this is only an example how to copy 
     *  some img surface into blitter */
    
    if (0 != SDL_BlitSurface(table[nr].gfx_surface, \
           NULL , GfxItems->window_surface_struct_p, &dest) )
    {
        printf("error copying blitter \n");
    }



}
