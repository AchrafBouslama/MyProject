#include <stdlib.h>
#include  <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
int main(int argc, char *argv[])

{
   int continuer=1;
    SDL_Event event; // Cette variable servira plus tard à gérer les événements
     SDL_Surface *ecran = NULL,*imageDeFond = NULL,*Play=NULL,*help=NULL,*exit=NULL;
    SDL_Rect positionFond,positionPlay,positionhelp,positionexit;

/*le positionnement des images a mettre dans le menu*/ 
    positionFond.x = 0;
    positionFond.y = 0;
positionPlay.x =400;
positionPlay.y =350;
positionhelp.x =400;
positionhelp.y =400;
positionexit.x =400;
positionexit.y =450;
   

  imageDeFond = IMG_Load("menu.jpg");
   SDL_Init(SDL_INIT_VIDEO);
 ecran = SDL_SetVideoMode(1920,1187, 32, SDL_HWSURFACE);
 SDL_WM_SetCaption("mon super menu", NULL);
                                    /*partie music*/
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
   {
      printf("%s", Mix_GetError());
   }

   Mix_Music *musique , *bip; //Création du pointeur de type Mix_Music
   musique = Mix_LoadMUS("popipo.mp3"); //Chargement de la musique
bip = Mix_LoadMUS("bip.mp3");
   Mix_PlayMusic(musique, -1); //Jouer infiniment la musique
Play = IMG_Load("play.png");
help = IMG_Load("help.png");
exit = IMG_Load("exit.png");



while (continuer)
{
SDL_WaitEvent (&event);                            /*fin de partie creation music */
    
    switch(event.type)
{
    case SDL_QUIT:
        continuer = 0;
        break;
   case SDL_MOUSEBUTTONDOWN:
			if(event.button.button == SDL_BUTTON_LEFT)
			{
				
				if(event.button.x >= 400 && event.button.x <= 575 && event.button.y >= 350 && event.button.y <= 395)
				{
				Play = IMG_Load("play.png");
				SDL_BlitSurface(Play, NULL, ecran, &positionPlay);
				SDL_Flip(ecran);
                                Mix_PlayMusic(bip,1);
                            
				}
				
				else if(event.button.x >= 400 && event.button.x <= 575 && event.button.y >= 400 && event.button.y <=445)
				{
				help = IMG_Load("help.png");
				SDL_BlitSurface(help, NULL, ecran, &positionhelp);
				SDL_Flip(ecran);
                                Mix_PlayMusic(bip,1);
                                 
				}
				else if(event.button.x >=400 && event.button.x <= 575 && event.button.y >= 450 && event.button.y <= 495)
				{
				exit = IMG_Load("exit.png");
				SDL_BlitSurface(exit, NULL, ecran, &positionexit);
				SDL_Flip(ecran);
                                Mix_PlayMusic(bip,1);
                                continuer = 0;
				break;
				}	
			}
						
			break;
			case SDL_MOUSEBUTTONUP:
			if(event.button.x >= 400 && event.button.x <= 575 && event.button.y >= 350 && event.button.y <= 395)
			{
			Play = IMG_Load("play.png");
			SDL_BlitSurface(Play, NULL, ecran, &positionPlay);
			SDL_Flip(ecran);
			}
			else if(event.button.x >= 400 && event.button.x <= 575 && event.button.y >= 400 && event.button.y <=445)
			{
			help = IMG_Load("help.png");
			SDL_BlitSurface(help, NULL, ecran, &positionhelp);
			SDL_Flip(ecran);
			}
			else if(event.button.x >= 400 && event.button.x <= 575&& event.button.y >= 450 && event.button.y <= 495)
			{
			exit = IMG_Load("exit.png");
			SDL_BlitSurface(exit, NULL, ecran, &positionexit);
			SDL_Flip(ecran);
			}
		
			break;
}
SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
SDL_BlitSurface(Play, NULL, ecran, &positionPlay);
SDL_BlitSurface(help, NULL, ecran,&positionhelp);
SDL_BlitSurface(exit, NULL, ecran, &positionexit);

SDL_Flip(ecran);
}
SDL_FreeSurface(imageDeFond);
SDL_FreeSurface(Play);
    SDL_FreeSurface(help);
    SDL_FreeSurface(exit);
Mix_FreeMusic(musique); //Libération de la musique
    Mix_CloseAudio(); //Fermeture de l'API
    SDL_Quit();

    return EXIT_SUCCESS;
    
}

