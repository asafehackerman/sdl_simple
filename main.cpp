#include <iostream>
#include <SDL3/SDL.h>
#include <locale.h>

int main () {

    setlocale( LC_ALL, "" );
    const int janelaLargura = 800;
    const int janelaAltura = 600;

    SDL_Init(SDL_INIT_VIDEO); //inicia o SDL
    SDL_Window* janela = SDL_CreateWindow( "Rodando eterno", janelaLargura, janelaAltura, 0); //cria a janela
    SDL_Renderer* renderer = SDL_CreateRenderer(janela, NULL); //cria o renderer
    SDL_FRect posRect1 = { (janelaLargura - 200) / 2, (janelaAltura - 200) / 2, 200, 200 }; // instância de retângulo com posição e tamanho
    SDL_FRect posRect2 = { (janelaLargura - 200) / 2, (janelaAltura - 200), 200, 200 }; // instância de retângulo com posição e tamanho
    SDL_FRect posRect3 = { (janelaLargura - 200) / 2, 0, 200, 200 }; // instância de retângulo com posição e tamanho
    bool running = true;
    int valorCor1 = 0;
    int valorCor2 = 255;
    int tempo = SDL_GetTicks();

    while (running == true) {
        SDL_Event event;
        if(SDL_GetTicks() - tempo >= 1000) {
            tempo = SDL_GetTicks();
            valorCor1 += 10;
            valorCor2 -= 10;
            if(valorCor1 > 255) {
                valorCor1 = 0;
                valorCor2 = 255;
            } std::cout << "Vezes de cor alteradas: " << SDL_GetTicks() / 1000 << std::endl;
        }

        SDL_SetRenderDrawColor(renderer, valorCor1, valorCor2, 0, 0);
        SDL_RenderClear(renderer);

        //retângulo 1
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
        SDL_RenderFillRect(renderer, &posRect1);

        //retângulo 2
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
        SDL_RenderFillRect(renderer, &posRect2);

        //retângulo 3
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
        SDL_RenderFillRect(renderer, &posRect3);

        SDL_RenderPresent(renderer); // mostra as coisas na tela
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
