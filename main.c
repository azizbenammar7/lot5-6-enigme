

#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "enigme.h"

int main(int argc, char *argv[])
{
  // Initialisation de SDL
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Surface *screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption("Enigme", NULL);

  // Initialisation de TTF
  TTF_Init();
  TTF_Font *font = TTF_OpenFont("arial.ttf", 30);

  // Initialisation de l'enigme
  enigme e = initEnigme();
  enigmeData ed = generateEnigme(e);

  // Affichage de l'enigme
  showEnigme(ed, screen, e);
  SDL_Flip(screen);

  // Affichage du chrono
  showChrono(screen, font);

  // Résolution de l'enigme
  int result = 0;
  SDL_Event event;
  while(!result){
  SDL_WaitEvent(&event);
  result = resolutionEnigme(ed, event, screen, font);
}

  // Nettoyage
  fclose(e.f);
  SDL_FreeSurface(e.back);
  SDL_FreeSurface(screen);
  TTF_CloseFont(font);
  TTF_Quit();
  SDL_Quit();
  return 0;
}





