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
#include "SDL_ttf.h"
#include "game_assets.h"
/*-----------------------------------------------------------------------------
 * MACROS, DEFINES 
 *-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 * TYPEDEFS 
 *-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 * GLOBAL FUNCTION PROTOTYPES 
 *-----------------------------------------------------------------------------*/

extern MyGame_ErrorType MyGame_GfxInit(MyGame_GfxType gfx_type);

extern void MyGame_GfxFinish(void); 

extern MyGame_GfxProperties * MyGame_GetGfxItems(void);

extern MyGame_ErrorType MyGame_RefreshGfx(SDL_Renderer * renderer, SDL_Window *window_p);
extern
MyGame_ErrorType LoadImg2Texture(char *filename, SDL_Renderer *renderer_struct_p, SDL_Texture ** texture);

extern MyGame_ErrorType LoadImg2Surface(char *filename, SDL_Surface **img_surface, SDL_Surface *window_surface_struct_p);
extern MyGame_ErrorType LoadImgPng2Texture(char *filename, SDL_Renderer *renderer_struct_p, SDL_Texture **texture);

extern MyGame_ErrorType LoadImgPng2Surface(char *filename, SDL_Surface **img_surface, SDL_Surface *window_surface_struct_p);

extern TTF_Font * MyGame_LoadFont(char * font_file);

extern SDL_Surface * MyGame_TextOnScreen(TTF_Font *ttf_font, char * text, SDL_Color  color);
#endif
/* end of sdl_functions.h */
