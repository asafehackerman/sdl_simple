#include <iostream>
#include <SDL3/SDL.h>

int main () {

    SDL_Init(SDL_INIT_VIDEO); //inicia o SDL
    SDL_Window* janela = SDL_CreateWindow( "Rodando eterno", 800, 600, 0); //cria a janela
    bool running = true;

    while (running == true) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) { //enquanto existir eventos
            if (event.type == SDL_EVENT_QUIT) { //se o evento for de fechar a janela
                running = false; //fecha a janela
            }
        } 
    }
    
    SDL_DestroyWindow(janela);
    SDL_Quit();

    return 0;
}