#include "SDL.h"
#include "SDL_events.h"
#include "SDL_render.h"
#include "SDL_surface.h"
#include "SDL_video.h"

#define WINDOW_TITLE (const char*)"title789"

int main(int argc, char **argv)
{

    int a;
    int isQuit = 0;
    SDL_Window *win1;
    SDL_Event event;
    SDL_Init(SDL_INIT_VIDEO);

    if (SDL_VideoInit(NULL) < 0)
    {

        printf("error ! \n");

        return a;
    }

    win1 = SDL_CreateWindow(WINDOW_TITLE, 300 , 300, 800, 600, SDL_WINDOW_RESIZABLE );
//    SDL_CreateRenderer(win1, -1, flags);

    

    if (win1 != NULL)
    {
        SDL_SetWindowTitle(win1, WINDOW_TITLE);
        printf("window title %s \n",SDL_GetWindowTitle(win1));


        SDL_Surface *surface1 =  SDL_GetWindowSurface(win1);

        if (surface1 != NULL)
        {
            SDL_UpdateWindowSurface(win1);
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


        SDL_DestroyWindow(win1);
        SDL_Quit();


    }
    
    a++;
    return a;

}

