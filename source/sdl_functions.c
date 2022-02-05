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
#include "SDL_surface.h"
#include "SDL_timer.h"
#include "definitions.h"
#include "game_types.h"
#include "sdl_functions.h"

/* #####   MACROS  -  LOCAL TO THIS SOURCE FILE   ################################### */


/*"---------------------------------------------------*/
/* #####   DATA TYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */
/*  this struct keep most important SDL entities */
static MyGame_GfxProperties GameSdlEntities = {NULL};
/* "--------------------------------------------------- 
 * FUNCTION DEF */

/* #####   FUNCTION DEFINITIONS  -  EXPORTED FUNCTIONS   ############################ */

MyGame_ErrorType MyGame_GfxInit(void )
{
    int returnValue = 0;

    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
    if (SDL_VideoInit(NULL) < 0)
    {

        printf("error ! \n");
        
        return returnValue++;
    }


    GameSdlEntities.window_struct_p = SDL_CreateWindow(WINDOW_TITLE, X_WINDOW_POS , Y_WINDOW_POS, XSIZE_WINDOW_START, YSIZE_WINDOW_START, SDL_WINDOW_RESIZABLE );
    

    if (GameSdlEntities.window_struct_p != NULL)
    {
        SDL_SetWindowTitle(GameSdlEntities.window_struct_p, WINDOW_TITLE);
        printf("window title %s \n",SDL_GetWindowTitle(GameSdlEntities.window_struct_p));

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

        /* if use of renderer we cannot use get window surface anymore! */

        if (NULL == GameSdlEntities.renderer_struct_p)
        {
            GameSdlEntities.window_surface_struct_p =  SDL_GetWindowSurface(GameSdlEntities.window_struct_p);

            /*  clear drawing area */
            if ((GameSdlEntities.window_surface_struct_p != NULL) && (GameSdlEntities.renderer_struct_p == NULL))
            {
                SDL_UpdateWindowSurface(GameSdlEntities.window_struct_p);
            }
            else 
            {
                returnValue++;
            }
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
