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
#include "SDL_blendmode.h"
#include "SDL_events.h"
#include "SDL_pixels.h"
#include "SDL_rect.h"
#include "SDL_render.h"
#include "SDL_rwops.h"
#include "SDL_stdinc.h"
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
#include "game_config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* #####   MACROS  -  LOCAL TO THIS SOURCE FILE   ################################### */

/* #####   TYPE DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ######################### */

/* #####   DATA TYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */

/* #####   VARIABLES  -  LOCAL TO THIS SOURCE FILE   ################################ */

static MyGame_GfxProperties *GfxItems;
static SDL_Color MyGameBackground = {50, 250,20 ,255};


/* #####   PROTOTYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */
static MyGame_ErrorType ClearRenderer(SDL_Color color);

static void MyGame_UpdateView(MyGameEvent_struct *event, MyGame_GfxProperties *GfxItems, MyGame_GfxAsset *table);


/* #####   FUNCTION DEFINITIONS  -  EXPORTED FUNCTIONS   ############################ */

void MyGame_MainLoopRenderer(void)
{
    MyGame_ErrorType gfxStatus = ALL_OK ;
    MyGameEvent_struct *Events;

    GfxItems = MyGame_GetGfxItems();

    /* loading defined gfx */
    gfxStatus = MyGame_Asset_Load(NULL, GfxItems->renderer_struct_p, NULL);


    MAIN_GAME_LOOP
    {

        /*  clear renderer window */
        ClearRenderer(MyGameBackground);

        /*  read events - keyboard, mouse etc */
        Events = MyGame_CheckEvents();

        /*  prepare new gfx */
        MyGame_UpdateView(Events, GfxItems, MyGame_GfxTable);

        /*  refresh renderer + additional delay? */
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


static void MyGame_UpdateView(MyGameEvent_struct *event, MyGame_GfxProperties *GfxItems, MyGame_GfxAsset *table)
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


    if (SDL_QueryTexture(table[nr].gfx_texture, NULL, NULL, &texture_w, &texture_h) == 0)
    {
//        printf("szie of texture %d, %d \n",texture_w, texture_h);
    }

    if (SDL_GetTextureAlphaMod(table[nr].gfx_texture, &alpha) == 0)
    {
//         printf("texture alpha %d \n",alpha);
         SDL_SetTextureAlphaMod(table[nr].gfx_texture, alpha);

    }
    SDL_SetTextureBlendMode(table[nr].gfx_texture, SDL_BLENDMODE_BLEND);
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

    
    SDL_Color text_color = {0,0,0,255};


    char * text = calloc(20 , sizeof(char));
    char * value = calloc(4, sizeof(char));
    if (text == NULL)
    {
        printf("problem allocating text \n");
    }
    else {
        int ret = sprintf(value, "%d", delta.x);
        
        if (0 > ret )
        {
            printf("problem creating string %d \n", ret);

        }
        else 
        {
            strcat(text, "String " );
            strcat(text, value);
        }
    }



    SDL_Surface * text_surface = MyGame_TextOnScreen(MyGame_FontDefinition[1].ttf_font, text , text_color);
    if (text_surface != NULL)
    {
        SDL_Texture *text_texture;
        text_texture = SDL_CreateTextureFromSurface(GfxItems->renderer_struct_p , text_surface );
        if (text_texture != NULL)
        {
             SDL_Rect text_size = {0};
             if (ALL_OK == SDL_QueryTexture(text_texture, NULL, NULL, &text_size.w, &text_size.h))
             {
                 text_size.x = 20;
                 text_size.y = windows_h - 50;

                 if (SDL_RenderCopy(GfxItems->renderer_struct_p, text_texture, NULL, &text_size) != ALL_OK)
                 {
                     printf("problem writing text to screen \n");

                 }

             }
        }
        

    }
    free(text);
    free(value);
    if (event->KeysPressed_Union.Keys_bits.key_b == SDL_TRUE)
    {
    if (0 != SDL_RenderCopy(GfxItems->renderer_struct_p, \
           table[0].gfx_texture , &src_bg, &dest_bg) )
    {
        printf("error copying texture \n");
    }
    }
    if (0 != SDL_RenderCopy(GfxItems->renderer_struct_p, \
           table[nr].gfx_texture , &src, &dest) )
    {
        printf("error copying texture \n");
    }



}
