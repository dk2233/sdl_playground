#include "SDL.h"
#include "SDL_events.h"
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


int main(int argc, char **argv)
{

    MyGame_GfxProperties *GfxItems;
    int a = 0;
    MyGame_ErrorType gfxStatus = ALL_OK ;

    if (MyGame_GfxInit() > 0)
    {
       gfxStatus  = MYGAME_ERROR;
    }

    /*  check if we operates on surface or renderer */
    if (NULL == GfxItems->window_surface_struct_p)
    {

//        MyGame_MainLoopSoftware();

    }
    else {
        MyGame_MainLoopRenderer();
    }

    MyGame_GfxFinish();

    return a;

}
    


