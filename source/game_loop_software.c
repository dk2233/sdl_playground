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
/* #####   MACROS  -  LOCAL TO THIS SOURCE FILE   ################################### */

/* #####   TYPE DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ######################### */

/* #####   DATA TYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */

/* #####   VARIABLES  -  LOCAL TO THIS SOURCE FILE   ################################ */

static MyGame_GfxProperties *GfxItems;

/* #####   PROTOTYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */

/* #####   FUNCTION DEFINITIONS  -  EXPORTED FUNCTIONS   ############################ */

void MyGame_MainLoopSoftware(void)
{
    SDL_Event event;
    SDL_RWops *img1_RW, *img2_RW;
    SDL_Surface *img1_surface, *img2_surface;
    SDL_Texture *img1_Texture, *img2_Texture;
    int isQuit = 0;
    int direction = DIRECTION_DOWN;
    MyGame_ErrorType gfxStatus = ALL_OK ;

    if (MyGame_GfxInit() > 0)
    {
       gfxStatus  = MYGAME_ERROR;
    }


    /* loading defined gfx */
    gfxStatus = MyGame_Asset_Load(NULL);
    

    while(1)
    {

        ClearSurface(MyGameBackground);

            {
            /*  clear current window surface */
                SDL_FillRect(GfxItems->window_surface_struct_p, &(GfxItems->window_surface_struct_p->clip_rect) , 0);
            }


            MyGame_CheckEvents();


            MyGame_RefreshGfx();

            SDL_Rect *img1_rect = &(img1_surface->clip_rect);
            img1_rect->x = (30 + i);
            a = SDL_BlitSurface(img1_surface, NULL , GfxItems->window_surface_struct_p, img1_rect);


            SDL_Rect *img2_rect = &(img2_surface->clip_rect);

            img2_rect->x = 100;
            img2_rect->y = ( i);


            SDL_BlitSurface(img2_surface, NULL , GfxItems->window_surface_struct_p, img2_rect);
            SDL_UpdateWindowSurface(GfxItems->window_struct_p);

/*             printf("%d ",i);
 */
            i = i + direction;
            SDL_Delay(10);
            
        }


} 

/* #####   FUNCTION DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ##################### */

