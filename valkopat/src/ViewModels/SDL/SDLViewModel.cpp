//
// Created by kowalsky on 6.4.16.
//

#include "SDLViewModel.h"

void ViewModel::SDLViewModel::ShowSplashScreen()
{
    SDL_Window* win;
    SDL_Renderer* Renderer;
    SDL_SetMainReady();
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(800,600,0,&win,&Renderer);
    SDL_RenderPresent(Renderer);
    SDL_Delay(2500);
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

const char* ViewModel::SDLViewModel::GetNameofViewModel()
{
    return "SDL";
}






