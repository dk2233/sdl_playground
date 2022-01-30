#include "SDL.h"
#include "SDL_events.h"
#include "SDL_render.h"
#include "SDL_surface.h"
#include "SDL_video.h"
#include "definitions.h"
#include "sdl_functions.h"


int main(int argc, char **argv)
{

    SDL_Event event;
    int a;
    int isQuit = 0;

    MyGame_GfxInit();
            

    while(0 == isQuit )
    {
        if ( SDL_WaitEvent(&event))
        {
            if (event.type == SDL_KEYDOWN)
            {
                isQuit = 1;
            }
        }

    }



    return a;

}
    


