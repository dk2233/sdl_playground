#ifndef GAME_ASSETS_HEADER
#define GAME_ASSETS_HEADER


/*
 * =====================================================================================
 *
 *       Filename:  game_assets.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02.02.2022 21:16:28
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  Daniel Kucharski (), progdk22@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

/*-----------------------------------------------------------------------------
 * HEADER INCLUDES 
 *-----------------------------------------------------------------------------*/


#include "SDL_render.h"
#include "SDL_stdinc.h"
#include "SDL_surface.h"
#include "SDL_ttf.h"
#include "game_types.h"
#include "stdint.h"
#include <bits/stdint-uintn.h>

/*-----------------------------------------------------------------------------
 * MACROS, DEFINES 
 *-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 * TYPEDEFS 
 *-----------------------------------------------------------------------------*/

typedef union 
{
    MyGame_ErrorType (*function_load_texture_renderer)(char * gfx_file_name, SDL_Renderer *renderer_struct_p, SDL_Texture ** texture);
    MyGame_ErrorType (*function_load_surface)(char *gfx_file_name, SDL_Surface **img_surface, SDL_Surface *window_surface_struct_p);

} MyGame_FunctionToLoadAsset;

typedef struct 
{
    char * gfx_data_file_name;
    SDL_Texture *gfx_texture;
    SDL_Surface *gfx_surface;
    MyGame_FunctionToLoadAsset function_to_load_data;

} MyGame_GfxAsset;

typedef struct 
{
    char *file_font;
    int font_size;
    TTF_Font *ttf_font;

} MyGame_FontAsset;


/*-----------------------------------------------------------------------------
 * GLOBAL FUNCTION PROTOTYPES 
 *-----------------------------------------------------------------------------*/

/*  function that loads 
 *  all defined gfx_file_names
 *  according to table definition */
extern MyGame_ErrorType MyGame_Asset_Load(MyGame_GfxAsset *gfx_game_data, SDL_Renderer * renderer_p, SDL_Surface *window_surface_struct_p);

#endif
/* end of game_assets.h */



