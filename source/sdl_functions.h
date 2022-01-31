/*
 * =====================================================================================
 *
 *       Filename:  sdl_functions.h
 *
 *    Description: 
 *
 *
 *        Version:  1.0
 *        Created:  30.01.2022 21:47:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  DK, 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef SDL_FUNCTIONS_INC
#define SDL_FUNCTIONS_INC

#include "game_types.h"
#include "SDL_video.h"
#include <SDL.h>

extern MyGame_ErrorType MyGame_GfxInit(void);

extern void MyGame_GfxFinish(void); 

extern SDL_Window * MyGame_GetWindow(void);
#endif
