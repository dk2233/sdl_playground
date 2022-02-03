#ifndef SDL_FUNCTIONS_HEADER
#define SDL_FUNCTIONS_HEADER
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

/*-----------------------------------------------------------------------------
 * HEADER INCLUDES 
 *-----------------------------------------------------------------------------*/

#include "game_types.h"
#include "SDL_video.h"
#include <SDL.h>
/*-----------------------------------------------------------------------------
 * MACROS, DEFINES 
 *-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 * TYPEDEFS 
 *-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 * GLOBAL FUNCTION PROTOTYPES 
 *-----------------------------------------------------------------------------*/

extern MyGame_ErrorType MyGame_GfxInit(void);

extern void MyGame_GfxFinish(void); 

extern MyGame_GfxProperties * MyGame_GetGfxItems(void);

extern MyGame_ErrorType MyGame_RefreshGfx(SDL_Renderer * renderer, SDL_Window *window_p);
extern
MyGame_ErrorType LoadImg2Texture(char *filename, SDL_Renderer *renderer_struct_p, SDL_Texture ** texture);
#endif
/* end of sdl_functions.h */
