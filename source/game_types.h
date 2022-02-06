#ifndef GAME_TYPES_HEADER
#define GAME_TYPES_HEADER
/*
 * =====================================================================================
 *
 *       Filename:  game_types.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  30.01.2022 21:41:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

/*-----------------------------------------------------------------------------
 * HEADER INCLUDES 
 *-----------------------------------------------------------------------------*/
#include "SDL.h"
#include "SDL_render.h"
#include "SDL_surface.h"
/*-----------------------------------------------------------------------------
 * MACROS, DEFINES 
 *-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 * TYPEDEFS 
 *-----------------------------------------------------------------------------*/

typedef enum 
{
    MYGAME_SDL_ERROR = -1,
    ALL_OK = 0,
    MYGAME_ERROR = 1,

} MyGame_ErrorType ;


typedef struct
{
    SDL_Window *window_struct_p;
    SDL_Surface *window_surface_struct_p;
    SDL_Renderer *renderer_struct_p;

} MyGame_GfxProperties;

typedef struct
{
    int isQuit;
    union {
        struct 
        {
            Uint32 key_up:1;
            Uint32 key_down:1;
            Uint32 key_left:1;
            Uint32 key_right:1;
        } Keys_bits;
        Uint32 Keys_u32;
    } KeysPressed_Union;


} MyGameEvent_struct;
/*-----------------------------------------------------------------------------
 * GLOBAL FUNCTION PROTOTYPES 
 *-----------------------------------------------------------------------------*/


#endif
/* end of game_types.h */
