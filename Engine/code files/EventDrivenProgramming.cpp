#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* gWindow = NULL;
SDL_Surface* gSurface = NULL;
SDL_Surface* gImage = NULL;


bool init() {
    bool success = true;

    if( SDL_Init(SDL_INIT_VIDEO) < 0){
        cout<<"SDL could not be initialized. SDL Error: "<<SDL_GetError();
        success = false;
    }
    else{
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    
        if(gWindow == NULL){
            cout<<"Window could not be initalized. SDL Error: "<<SDL_GetError();
            success = false;
        }
        else {
            gSurface = SDL_GetWindowSurface(gWindow);
        }   
        }
        return success;
}

bool loadMedia() {
    bool success = true;

    gImage = SDL_LoadBMP("sourceFiles/tartrus.bmp");

    if(gImage == NULL) {
        cout<<"Image could not be initalized. SDL Error: "<<SDL_GetError();
        success = false;
    }
    return success;
}

void close() {
    
    SDL_FreeSurface(gImage);
    gSurface = NULL;
    gWindow = NULL;
    SDL_Quit();
}

int main (int argc, char* args[] ){

    if( !init() ){
        cout<<"Failed to Initalize SDL. SDL Error: "<<SDL_GetError();
    }
    else {
        if( !loadMedia() ){
            cout<<"Falied to Initalize window. SDL Error: "<<SDL_GetError();
        }
        else{

            bool quit = false; //Main Loop flag
            SDL_Event e; //Event Handler

            while( !quit ){
                //Handles Events on Queue
                while( SDL_PollEvent( &e ) != 0 ){
                    //User requests quit
                    if( e.type == SDL_QUIT ){
                        quit = true;
                    }
                }

            SDL_BlitSurface(gImage, NULL, gSurface, NULL);
            SDL_UpdateWindowSurface(gWindow);
            
            }


        }
    }

    close();
    
    return 0;

    }
