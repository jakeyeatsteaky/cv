#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_pixels.h>

SDL_AppResult startup(SDL_Window** window, SDL_Renderer** renderer)
{
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Unable to initialize SDL: %s\n", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    int flags = SDL_WINDOW_RESIZABLE;
    *window = SDL_CreateWindow("Test Window", 800, 600, flags);
    if (!*window) {
        SDL_Log("Could not create a window: %s\n", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    *renderer = SDL_CreateRenderer(*window, NULL);
    if (!*renderer) {
        SDL_Log("Failed to create renderer: %s\n", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}

int main(int argc, char** argv)
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    bool quit = false;
    startup(&window, &renderer);

    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        // update

        // render
        SDL_Color background;
        background.a = SDL_ALPHA_OPAQUE;
        background.r = 0xff;
        background.g = 0x0;
        background.b = 0xff;

        SDL_SetRenderDrawColor(renderer, background.r, background.g, background.b, background.a);
        SDL_RenderClear(renderer);

            // render == render screen objects

            // render == present
        SDL_RenderPresent(renderer);

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}