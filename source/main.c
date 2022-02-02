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

    SDL_Event event;
    SDL_RWops *img1_RW, *img2_RW;
    SDL_Surface *img1_surface, *img2_surface;
    MyGame_GfxProperties *GfxItems;
    int a;
    MyGame_ErrorType gfxStatus = ALL_OK ;
    int isQuit = 0;
    int direction = DIRECTION_DOWN;
    SDL_Texture *img1_Texture, *img2_Texture;

    if (MyGame_GfxInit() > 0)
    {
       gfxStatus  = MYGAME_ERROR;
    }

    /*  check if we operates on surface or renderer */
    if (NULL == GfxItems->window_surface_struct_p)
    {

        MyGame_MainLoopSoftware();

    }
    else {
        MyGame_MainLoopRenderer();
    }

    img1_RW = SDL_RWFromFile("gfx/img1.png", "rb");
    img2_RW = SDL_RWFromFile("gfx/testyuv.bmp", "rb");


    if ((img1_RW != NULL) && (img2_RW != NULL) && (ALL_OK == gfxStatus ))
    {
        img1_surface = IMG_LoadPNG_RW(img1_RW);
        img2_surface = IMG_LoadBMP_RW(img2_RW);

        SDL_FreeRW(img1_RW);
        SDL_FreeRW(img2_RW);

        GfxItems = MyGame_GetGfxItems();

        img1_Texture = SDL_CreateTextureFromSurface(GfxItems->renderer_struct_p, img1_surface );
        img2_Texture = SDL_CreateTextureFromSurface(GfxItems->renderer_struct_p, img2_surface);



    }
    else
    {
        printf(" image not loaded \n");
    }

/* finish the job */

    SDL_FreeSurface(img1_surface);
    SDL_FreeSurface(img2_surface);

    MyGame_GfxFinish();

    return a;

}
    


