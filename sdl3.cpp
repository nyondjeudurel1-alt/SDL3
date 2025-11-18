#include <SDL3/SDL.h>

#define WINDOW_HEIGHT 400
#define WINDOW_WIDTH 640

int main()
{

    SDL_Window *Window = NULL;
    SDL_Renderer *Renderer = NULL;

    /* SDL3 Initialisation */
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("SDL_Init Error: %s", SDL_GetError());
        SDL_Quit();
    }

    /* Window Creation */
    SDL_CreateWindowAndRenderer("My window", WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE, &Window, &Renderer);
    if (Window == nullptr && Renderer == nullptr)
    {
        SDL_Log("SDL_CreateWindowAndRenderer Error: %s", SDL_GetError());
        return -1;
    }

    /* Game Loop */
    SDL_Event event;
    SDL_FRect rect;
    rect.x = rect.y = -1000;
    rect.w = rect.h = 50;
    bool running = true;
    while (running)
    {
        // Event handling
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT || event.key.scancode == SDL_SCANCODE_ESCAPE)
                running = false;

            else if (event.type == SDL_EVENT_KEY_DOWN)
            {
                switch (event.key.scancode)
                {
                case SDL_SCANCODE_RIGHT:
                    rect.x += 25;
                    break;
                case SDL_SCANCODE_LEFT:
                    rect.x -= 25;
                    break;
                case SDL_SCANCODE_DOWN:
                    rect.y += 25;
                    break;
                case SDL_SCANCODE_UP:
                    rect.y -= 25;
                    break;
                default:
                    SDL_Log("Not Valid");
                    break;
                }
            }

            else if (event.type == SDL_EVENT_MOUSE_MOTION)
            {
                rect.x = event.motion.x - (rect.w / 2.0f);
                rect.y = event.motion.y - (rect.h / 2.0f);
                break;
            }
        }
        // main loop
        SDL_SetRenderDrawColor(Renderer, 0, 125, 0, 255);
        SDL_RenderClear(Renderer);

        SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255); // Fill Rectangle
        SDL_RenderFillRect(Renderer, &rect);
        SDL_RenderPresent(Renderer);
    }

    /* SDL3 Exit */
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();

    return 0;
}