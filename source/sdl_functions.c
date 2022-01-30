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
#include "SDL_video.h"
#include <SDL.h>
#include "definitions.h"
#include "game_types.h"
#include "sdl_functions.h"

/*"---------------------------------------------------*/
static SDL_Window *win1;


/* "--------------------------------------------------- 
 * FUNCTION DEF */

MyGame_ErrorType MyGame_GfxInit(void )
{
    int returnValue = 0;

    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
    if (SDL_VideoInit(NULL) < 0)
    {

        printf("error ! \n");

        return returnValue;
    }


    win1 = SDL_CreateWindow(WINDOW_TITLE, X_WINDOW_POS , Y_WINDOW_POS, XSIZE_WINDOW_START, YSIZE_WINDOW_START, SDL_WINDOW_RESIZABLE );
    

    if (win1 != NULL)
    {
        SDL_SetWindowTitle(win1, WINDOW_TITLE);
        printf("window title %s \n",SDL_GetWindowTitle(win1));


        SDL_Surface *surface1 =  SDL_GetWindowSurface(win1);

        /*  clear drawing area */
        if (surface1 != NULL)
        {
            SDL_UpdateWindowSurface(win1);
        }

    
    }
    return returnValue;
}


void MyGame_GfxFinish(void)
{
    SDL_DestroyWindow(win1);
    SDL_Quit();

}
