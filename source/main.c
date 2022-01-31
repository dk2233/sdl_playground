#include "SDL.h"
#include "SDL_events.h"
#include "SDL_rect.h"
#include "SDL_render.h"
#include "SDL_rwops.h"
#include "SDL_surface.h"
#include "SDL_video.h"
#include "definitions.h"
#include "sdl_functions.h"
#include "SDL_image.h"


int main(int argc, char **argv)
{

    SDL_Event event;
    SDL_RWops *img1;
    SDL_Surface *img_surface, *win_surface;
    SDL_Window *win;
    int a;
    int isQuit = 0;

    MyGame_GfxInit();

    
    img1 = SDL_RWFromFile("gfx/img1.png", "rb");
            
    if (img1 != NULL)
    {
        img_surface = IMG_LoadPNG_RW(img1);


        win = MyGame_GetWindow();


        win_surface =  SDL_GetWindowSurface(win);

        img_surface = SDL_ConvertSurface(img_surface, win_surface->format, 0);

        SDL_Rect img1_rect = { 100,100,100,100};

        SDL_BlitSurface(img_surface, &img1_rect , win_surface, NULL);
        SDL_UpdateWindowSurface(win);

    }
    else
    {
        printf(" image not loaded \n");
    }


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
    


