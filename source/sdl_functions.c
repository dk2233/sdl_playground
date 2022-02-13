/*
 * =====================================================================================
 *
 *       Filename:  sdl_functions.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  30.01.2022 21:36:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "SDL_image.h"
#include "SDL_pixels.h"
#include "SDL_render.h"
#include "SDL_rwops.h"
#include "SDL_stdinc.h"
#include "SDL_surface.h"
#include "SDL_timer.h"
#include "SDL_video.h"
#include "definitions.h"
#include "game_assets.h"
#include "game_types.h"
#include "sdl_functions.h"

#include "SDL_ttf.h"
#include <stdio.h>
/* #####   MACROS  -  LOCAL TO THIS SOURCE FILE   ################################### */


/*"---------------------------------------------------*/
/* #####   DATA TYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */
/*  this struct keep most important SDL entities */
static MyGame_GfxProperties GameSdlEntities = {NULL};
/* "--------------------------------------------------- 
 * FUNCTION DEF */

/* #####   FUNCTION DEFINITIONS  -  EXPORTED FUNCTIONS   ############################ */

MyGame_ErrorType MyGame_GfxInit(MyGame_GfxType gfx_type )
{
    int returnValue = 0;

    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
    if (SDL_VideoInit(NULL) < 0)
    {

        printf("error ! \n");
        
        return returnValue++;
    }

    if (TTF_Init() != ALL_OK  )
    {
        printf("Error initializing TTF SDL \n");
        return returnValue++;

    }


    GameSdlEntities.window_struct_p = SDL_CreateWindow(WINDOW_TITLE, X_WINDOW_POS , Y_WINDOW_POS, XSIZE_WINDOW_START, YSIZE_WINDOW_START, SDL_WINDOW_RESIZABLE );

    if (GameSdlEntities.window_struct_p != NULL)
    {
        SDL_SetWindowTitle(GameSdlEntities.window_struct_p, WINDOW_TITLE);
        printf("window title %s \n",SDL_GetWindowTitle(GameSdlEntities.window_struct_p));


        if (GFX_SOFTWARE == gfx_type)
        {
            /*  in case software blit operations */
            GameSdlEntities.window_surface_struct_p =  SDL_GetWindowSurface(GameSdlEntities.window_struct_p);

            /*  clear drawing area */
            if (GameSdlEntities.window_surface_struct_p != NULL)
            {
                SDL_UpdateWindowSurface(GameSdlEntities.window_struct_p);
            }
            else 
            {
                returnValue++;
            }
        }
        else if (GFX_RENDERER == gfx_type)
        {

            /* if use of renderer we cannot use get window surface anymore! */
            GameSdlEntities.renderer_struct_p = SDL_CreateRenderer(GameSdlEntities.window_struct_p, RENDERER_INDEX, SDL_RENDERER_ACCELERATED);

            if (NULL == GameSdlEntities.renderer_struct_p)
            {
                printf(" I cannot create SDL renderer \n");
                returnValue++;

            }
            else 
            {
                SDL_RenderPresent(GameSdlEntities.renderer_struct_p);
            }

        }
        else {
        ;
        }
    
    }
    return returnValue;
}


void MyGame_GfxFinish(void)
{
    SDL_DestroyWindow(GameSdlEntities.window_struct_p);
    if (GameSdlEntities.renderer_struct_p != NULL)
    {
        SDL_DestroyRenderer(GameSdlEntities.renderer_struct_p);
    }
    SDL_Quit();

}

MyGame_GfxProperties * MyGame_GetGfxItems(void)
{
    return &GameSdlEntities; 
}



MyGame_ErrorType MyGame_RefreshGfx(SDL_Renderer * renderer, SDL_Window *window_p)
{
    MyGame_ErrorType output = ALL_OK;
    if (renderer != NULL)
    {

        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }
    else if (window_p != NULL)
    {
        output = (MyGame_ErrorType)SDL_UpdateWindowSurface(window_p);

    }
    else {
        output = MYGAME_ERROR;
    /*  error - nothing */
    }
    return output;

}


MyGame_ErrorType LoadImg2Texture(char *filename, SDL_Renderer *renderer_struct_p, SDL_Texture ** texture)
{

    MyGame_ErrorType error = ALL_OK; 

    *texture = IMG_LoadTexture(renderer_struct_p, filename); 

    if (NULL == *texture)
    {
        error = MYGAME_ERROR;
    }


    return error;

}

MyGame_ErrorType LoadImg2Surface(char *filename, SDL_Surface **img_surface, SDL_Surface *window_surface_struct_p)
{

    MyGame_ErrorType error = ALL_OK; 
    SDL_RWops *img_RW;
    int img_type = 0;

    img_RW = SDL_RWFromFile(filename, "rb");


    if (IMG_isBMP(img_RW) == SDL_TRUE)
    {
        *img_surface = IMG_LoadBMP_RW(img_RW);
    }
    else if (IMG_isJPG(img_RW))
    {
        *img_surface = IMG_LoadJPG_RW(img_RW); 
    }

    
    *img_surface = SDL_ConvertSurface(*img_surface, window_surface_struct_p->format, 0);
    
    if (NULL == img_surface)
    {
        error = MYGAME_ERROR;
    }


    return error;

}

MyGame_ErrorType LoadImgPng2Texture(char *filename, SDL_Renderer *renderer_struct_p, SDL_Texture **texture)
{

    MyGame_ErrorType error = ALL_OK; 

    SDL_Surface *img_surface = IMG_Load(filename);

    if (img_surface != NULL)
    {
        if (SDL_SetColorKey(img_surface, SDL_TRUE, SDL_MapRGB(img_surface->format, 0, 0, 0)) != 0)
        {
            printf(" I cannot set Key color for %s \n", filename);
        }

    }
    else {
    printf(" problem loading %s \n", filename);
    }

    *texture = SDL_CreateTextureFromSurface(renderer_struct_p, img_surface ); 

    if (NULL == *texture)
    {
        error = MYGAME_ERROR;
    }


    return error;
}

MyGame_ErrorType LoadImgPng2Surface(char *filename, SDL_Surface **img_surface, SDL_Surface *window_surface_struct_p)
{

    MyGame_ErrorType error = ALL_OK; 

    *img_surface = IMG_Load(filename);

    if (*img_surface != NULL)
    {
        if (SDL_SetColorKey(*img_surface, SDL_TRUE, SDL_MapRGB((*img_surface)->format, 0, 0, 0)) != 0)
        {
            printf(" I cannot set Key color for %s \n", filename);
        }

    }
    else {
    printf(" problem loading %s \n", filename);
    }

    if (NULL == *img_surface)
    {
        error = MYGAME_ERROR;
    }


    return error;
}



MyGame_ErrorType MyGame_LoadFont(MyGame_FontAsset * font_asset)
{
    MyGame_ErrorType retValue = ALL_OK; 
    static TTF_Font * font = NULL;

    font_asset->ttf_font = TTF_OpenFont(font_asset->file_font, font_asset->font_size);

    if (NULL == font_asset->ttf_font )
    {
        printf("Cannot load font %s \n",font_asset->file_font);
        printf("%s\n",TTF_GetError());
        retValue = MYGAME_ERROR;
    }
 
    return retValue;
}

SDL_Surface * MyGame_TextOnScreen(TTF_Font *ttf_font, char * text, SDL_Color  color)
{

    /*  idea is this function will keep font after loading */
    static SDL_Surface * sdl_surface; 

    sdl_surface = TTF_RenderText_Solid( ttf_font , text,  color);

    return sdl_surface;
}
