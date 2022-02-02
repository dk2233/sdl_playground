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
/* #####   MACROS  -  LOCAL TO THIS SOURCE FILE   ################################### */

/* #####   TYPE DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ######################### */

/* #####   DATA TYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */

/* #####   VARIABLES  -  LOCAL TO THIS SOURCE FILE   ################################ */

static MyGame_GfxProperties *GfxItems;
static SDL_Color MyGameBackground = {0, 0,0 ,255};


/* #####   PROTOTYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */
MyGame_ErrorType ClearRenderer(SDL_Color color);





/* #####   FUNCTION DEFINITIONS  -  EXPORTED FUNCTIONS   ############################ */

void MyGame_MainLoopRenderer(void)
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

        ClearRenderer(MyGameBackground);

    }

} 

/* #####   FUNCTION DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ##################### */
MyGame_ErrorType ClearRenderer(SDL_Color color)
{
    MyGame_ErrorType retValue = ALL_OK;
    retValue = (MyGame_ErrorType)SDL_SetRenderDrawColor(GfxItems->renderer_struct_p, color.r, color.g, color.b, color.a);

    if (ALL_OK == retValue)
    {
        retValue = (MyGame_ErrorType)SDL_RenderClear(GfxItems->renderer_struct_p);
    }

    return retValue; 
}




