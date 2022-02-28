#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Key Press Surface Constants
enum KeyPressSurface{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};



SDL_Window* gWindow = NULL; // creating the window we'll be rendering to
SDL_Surface* gSurface = NULL; // The Surfaca to be contained by the windoow
SDL_Surface* gImage = NULL; //Current displayed image
SDL_Surface* gKeyPressSurface[ KEY_PRESS_SURFACE_TOTAL]; //The Image that corresponds to the key press
SDL_Surface* loadSurface(std::string path);




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

    gKeyPressSurface[ KEY_PRESS_SURFACE_DEFAULT ] = loadSurface("sourceFiles/mountain.bmp");
    if( gKeyPressSurface[ KEY_PRESS_SURFACE_DEFAULT ] == NULL){
        cout<<"Failed to load Image. SDL Error: "<<SDL_GetError();
        success = false;
    }

    gKeyPressSurface[ KEY_PRESS_SURFACE_UP ] = loadSurface("sourceFiles/olympus.bmp");
    if( gKeyPressSurface[ KEY_PRESS_SURFACE_UP ] == NULL){
        cout<<"Failed to load Image. SDL Error: "<<SDL_GetError();
        success = false;
    }
    
    gKeyPressSurface[ KEY_PRESS_SURFACE_DOWN ] = loadSurface("sourceFiles/asgard.bmp");
    if( gKeyPressSurface[ KEY_PRESS_SURFACE_DOWN ] == NULL){
        cout<<"Failed to load Image. SDL Error: "<<SDL_GetError();
        success = false;
    }

    gKeyPressSurface[ KEY_PRESS_SURFACE_LEFT ] = loadSurface("sourceFiles/cosmos.bmp");
    if( gKeyPressSurface[ KEY_PRESS_SURFACE_LEFT ] == NULL){
        cout<<"Failed to load Image. SDL Error: "<<SDL_GetError();
        success = false;
    }
    
    gKeyPressSurface[ KEY_PRESS_SURFACE_RIGHT ] = loadSurface("sourceFiles/tartrus.bmp");
    if( gKeyPressSurface[ KEY_PRESS_SURFACE_RIGHT ] == NULL){
        cout<<"Failed to load Image. SDL Error: "<<SDL_GetError();
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

SDL_Surface* loadSurface(std::string path) {
    //this function loads individual images
    SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
    if( loadedSurface == NULL ){
        cout<<"Unable to load Image. SDL Error: "<<SDL_GetError();
    }  
    return loadedSurface;
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

            //Set default Current Surface
            gImage = gKeyPressSurface[ KEY_PRESS_SURFACE_DEFAULT];

            while( !quit ){
                //Handles Events on Queue
                while( SDL_PollEvent( &e ) != 0 ){
                    //User requests quit
                    if( e.type == SDL_QUIT ){
                        quit = true;
                    }
                    //User Presses a key
                    else if(e.type == SDL_KEYDOWN) {
                        //Select Surfaces Based on the Key

                        switch(e.key.keysym.sym){
                        case SDLK_UP:
                        gImage = gKeyPressSurface[ KEY_PRESS_SURFACE_UP ];
                        break;
                        
                        case SDLK_DOWN:
                        gImage = gKeyPressSurface[ KEY_PRESS_SURFACE_DOWN];
                        break;

                        case SDLK_LEFT:
                        gImage = gKeyPressSurface[ KEY_PRESS_SURFACE_LEFT];
                        break;

                        case SDLK_RIGHT:
                        gImage = gKeyPressSurface[ KEY_PRESS_SURFACE_RIGHT];
                        break;

                        default:
                        gImage = gKeyPressSurface[ KEY_PRESS_SURFACE_DEFAULT];
                        break;
                        }

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
