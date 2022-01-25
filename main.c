#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "stdio.h"
#include "stdlib.h"

int main()
{

    int grid_cell_size = 36;
    int grid_width = 10;
    int grid_height = 10;

    //starting positions
    int grid_padding_left = 0;

    int grid_border_left = grid_padding_left + grid_cell_size;

    int player_1_grid = grid_border_left + grid_cell_size;

    int grid_border_right = player_1_grid + (grid_width * grid_cell_size) + 2; //+2 to account for line length

    int grid_padding_middle = grid_border_right + grid_cell_size;

    int grid_border2_left = grid_padding_middle + grid_cell_size;

    int player_2_grid = grid_border2_left + (grid_cell_size);

    int grid_border2_right = player_2_grid + (grid_width * grid_cell_size) + 2;

    int grid_padding_right = grid_border2_right + grid_cell_size;

    // + 1 so that the last grid lines fit in the screen.
    int window_width = (grid_cell_size * 2) + (grid_width * grid_cell_size + 2) + (grid_cell_size * 3) + (grid_width * grid_cell_size + 2) + (grid_cell_size * 2);
    int window_height = (grid_height * grid_cell_size) + (grid_cell_size * 2) + 1;

    // Place the grid cursor in the middle of the screen.
    SDL_Rect grid_cursor = {
        .x = (grid_width - 1) / 2 * grid_cell_size,
        .y = (grid_height - 1) / 2 * grid_cell_size,
        .w = grid_cell_size,
        .h = grid_cell_size,
    };

    // The cursor ghost is a cursor that always shows in the cell below the
    // mouse cursor.
    SDL_Rect grid_cursor_ghost = {grid_cursor.x, grid_cursor.y, grid_cell_size,
                                  grid_cell_size};

    // Dark theme.
    SDL_Color grid_background = {22, 22, 22, 255}; // Barely Black
    SDL_Color grid_line_color = {44, 44, 44, 255}; // Dark grey
    SDL_Color grid_cursor_ghost_color = {44, 44, 44, 255};
    SDL_Color grid_cursor_color = {255, 255, 255, 255}; // White
    SDL_Color grid_border_color = {173, 216, 230, 255}; //light blue

    // retutns zero on success else non-zero
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window;
    SDL_Renderer *renderer;

    if (SDL_CreateWindowAndRenderer(window_width, window_height, 0, &window,
                                    &renderer) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "Create window and renderer: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_SetWindowTitle(window, "Battle Ship");

    SDL_bool quit = SDL_FALSE;
    SDL_bool mouse_active = SDL_FALSE;
    SDL_bool mouse_hover = SDL_FALSE;

    //font
    TTF_Init();
    TTF_Font *Sans = TTF_OpenFont("static/OpenSans/OpenSans-Light.ttf", 24);

    // as TTF_RenderText_Solid could only be used on
    // SDL_Surface then you have to create the surface first
    SDL_Texture *letters[grid_width];

    SDL_Texture *numbers[grid_height];

    //creating letter textures
    for (int l = 0; l < grid_width; l++)
    {
        char temp = (char)(l + 65);
        SDL_Surface *temp_surface = TTF_RenderText_Solid(Sans, &temp, grid_cursor_color);
        letters[l] = SDL_CreateTextureFromSurface(renderer, temp_surface);
    }

    //creating number textures
    for (int l = 0; l < grid_height; l++)
    {
        char temp = l + '0';
        SDL_Surface *temp_surface = TTF_RenderText_Solid(Sans, &temp, grid_cursor_color);
        numbers[l] = SDL_CreateTextureFromSurface(renderer, temp_surface);
    }

    // now you can convert it into a texture
    // SDL_Texture *message_A = SDL_CreateTextureFromSurface(renderer, letter_A);

    SDL_Rect Message_rect;               //create a rect
    Message_rect.x = 0;                  //controls the rect's x coordinate
    Message_rect.y = 0;                  // controls the rect's y coordinte
    Message_rect.w = grid_cell_size / 2; // controls the width of the rect
    Message_rect.h = grid_cell_size;     // controls the height of the rect

    while (!quit)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_w:
                case SDLK_UP:
                    grid_cursor.y -= grid_cell_size;
                    break;
                case SDLK_s:
                case SDLK_DOWN:
                    grid_cursor.y += grid_cell_size;
                    break;
                case SDLK_a:
                case SDLK_LEFT:
                    grid_cursor.x -= grid_cell_size;
                    break;
                case SDLK_d:
                case SDLK_RIGHT:
                    grid_cursor.x += grid_cell_size;
                    break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                grid_cursor.x = (event.motion.x / grid_cell_size) * grid_cell_size;
                grid_cursor.y = (event.motion.y / grid_cell_size) * grid_cell_size;
                break;
            case SDL_MOUSEMOTION:
                grid_cursor_ghost.x = (event.motion.x / grid_cell_size) * grid_cell_size;
                grid_cursor_ghost.y = (event.motion.y / grid_cell_size) * grid_cell_size;

                if (!mouse_active)
                    mouse_active = SDL_TRUE;
                break;
            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_ENTER && !mouse_hover)
                    mouse_hover = SDL_TRUE;
                else if (event.window.event == SDL_WINDOWEVENT_LEAVE && mouse_hover)
                    mouse_hover = SDL_FALSE;
                break;
            case SDL_QUIT:
                quit = SDL_TRUE;
                break;
            }
        }

        // Draw grid background.
        SDL_SetRenderDrawColor(renderer, grid_background.r, grid_background.g,
                               grid_background.b, grid_background.a);
        SDL_RenderClear(renderer);

        // Draw player 1 grid lines.
        SDL_SetRenderDrawColor(renderer, grid_line_color.r, grid_line_color.g,
                               grid_line_color.b, grid_line_color.a);

        for (int x = player_1_grid; x < 1 + player_1_grid + grid_width * grid_cell_size;
             x += grid_cell_size)
        {
            SDL_RenderDrawLine(renderer, x, grid_cell_size, x, grid_cell_size + grid_cell_size * grid_height);
        }

        for (int y = grid_cell_size; y < 1 + grid_height * grid_cell_size + grid_cell_size;
             y += grid_cell_size)
        {
            SDL_RenderDrawLine(renderer, player_1_grid, y, player_1_grid + grid_cell_size * grid_width, y);
        }

        // Draw player 2 grid lines.
        for (int x = player_2_grid; x < 1 + player_2_grid + grid_width * grid_cell_size;
             x += grid_cell_size)
        {
            SDL_RenderDrawLine(renderer, x, grid_cell_size, x, grid_cell_size + grid_cell_size * grid_height);
        }

        for (int y = grid_cell_size; y < 1 + grid_height * grid_cell_size + grid_cell_size;
             y += grid_cell_size)
        {
            SDL_RenderDrawLine(renderer, player_2_grid, y, player_2_grid + grid_cell_size * grid_width, y);
        }

        for (int x = 0; x < grid_width; x++)
        {
            //draw grid 1 letters
            Message_rect.x = (x * grid_cell_size) + player_1_grid + grid_cell_size / 4;
            Message_rect.y = 0;
            SDL_RenderCopy(renderer, letters[x], NULL, &Message_rect);

            //draw grid 2 letters
            Message_rect.x = (x * grid_cell_size) + player_2_grid + grid_cell_size / 4;
            Message_rect.y = 0;
            SDL_RenderCopy(renderer, letters[x], NULL, &Message_rect);
        }

        for (int y = 0; y < grid_height; y++)
        {
            //draw grid 1 numbers
            Message_rect.x = grid_border_left;
            Message_rect.y = (y * grid_cell_size) + grid_cell_size + grid_cell_size / 4;
            SDL_RenderCopy(renderer, numbers[y], NULL, &Message_rect);

            //draw grid 2 numbers
            Message_rect.x = grid_border2_left;
            Message_rect.y = (y * grid_cell_size) + grid_cell_size + grid_cell_size / 4;
            SDL_RenderCopy(renderer, numbers[y], NULL, &Message_rect);
        }

        // Draw grid ghost cursor.
        if (mouse_active && mouse_hover)
        {
            SDL_SetRenderDrawColor(renderer, grid_cursor_ghost_color.r,
                                   grid_cursor_ghost_color.g,
                                   grid_cursor_ghost_color.b,
                                   grid_cursor_ghost_color.a);
            SDL_RenderFillRect(renderer, &grid_cursor_ghost);
        }

        // Draw grid cursor.
        SDL_SetRenderDrawColor(renderer, grid_cursor_color.r,
                               grid_cursor_color.g, grid_cursor_color.b,
                               grid_cursor_color.a);
        SDL_RenderFillRect(renderer, &grid_cursor);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}