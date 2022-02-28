//importing Libraries
#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>

using namespace std;

//setting up screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Main function Parameters
int main(int argc, char* args[] ){
    
    //Declaring our Render window
    SDL_Window* window = NULL;

    //setting the SDL Surface
    SDL_Surface* screenSurface = NULL;

    //Initialize SDL
    if( SDL_Init(SDL_INIT_VIDEO ) < 0 ){
        cout<<"SDL couldn't initalize. SDL_Error: "<<SDL_GetError();
    }

    else{
        //Creating the window
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if( window == NULL ){
            cout<<"Window could not be created! SDL_Error: "<<SDL_GetError();
        }
        else{
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );

            //Filling the Surface White
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ));

            //Update the Surface
            SDL_UpdateWindowSurface(window);

            //Wait for two seconds


            SDL_Delay(2000);

        }
    }

    //Destroy the Window
    SDL_DestroyWindow( window );

    //Quits the SDL subsystem
    SDL_Quit();
    
    return 0;
}

