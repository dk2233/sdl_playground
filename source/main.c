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


int main(int argc, char **argv)
{

    SDL_Event event;
    SDL_RWops *img1, *img2;
    SDL_Surface *img1_surface, *img2_surface, *win_surface;
    MyGame_GfxProperties *GfxItems;
    int a;
    MyGame_ErrorType gfxStatus = ALL_OK ;
    int isQuit = 0;

    if (MyGame_GfxInit() > 0)
    {
       gfxStatus  = ERROR;
    }


    img1 = SDL_RWFromFile("gfx/img1.png", "rb");
    img2 = SDL_RWFromFile("gfx/testyuv.bmp", "rb");


    if ((img1 != NULL) && (img2 != NULL) && (ALL_OK == gfxStatus ))
    {
        img1_surface = IMG_LoadPNG_RW(img1);
        img2_surface = IMG_LoadBMP_RW(img2);


        SDL_FreeRW(img1);
        SDL_FreeRW(img2);

        GfxItems = MyGame_GetGfxItems();
        win_surface =  SDL_GetWindowSurface(GfxItems->window_struct_p);

        img1_surface = SDL_ConvertSurface(img1_surface, win_surface->format, 0);
        img2_surface = SDL_ConvertSurface(img2_surface, win_surface->format, 0);


        int i = 0;
        while(i < win_surface->clip_rect.h)
        {
            SDL_Rect *img1_rect = &(img1_surface->clip_rect);
            img1_rect->x += (30 + i);
            a = SDL_BlitSurface(img1_surface, NULL , win_surface, img1_rect);


            SDL_Rect *img2_rect = &(img2_surface->clip_rect);

            img2_rect->x += 100;
            img2_rect->y += (100 + i);

            SDL_BlitSurface(img2_surface, NULL , win_surface, img2_rect);
            SDL_UpdateWindowSurface(GfxItems->window_struct_p);
            SDL_Delay(20);

            //while(0 == isQuit )
            {
                if ( SDL_WaitEvent(&event))
                {
                    if (event.type == SDL_KEYDOWN)
                    {
                        isQuit = 1;
                        break;
                    }
                }

            }
            
        }

    }
    else
    {
        printf(" image not loaded \n");
    }





    return a;

}
    


