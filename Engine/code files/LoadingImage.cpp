//importing Libraries
#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>

using namespace std;

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL; //The Image to be loaded and displayed on the screen

//setting up screen dimension constants
const int SCREEN_WIDTH = 640; 
const int SCREEN_HEIGHT = 480;

//Starts up SDL and Creates a window
bool init() {
    bool success = true;

    //Initalizing and Error management
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
        cout<<"SDL could not initialize! SDL_Error: "<<SDL_GetError();
        success = false;
    }
    else{
        //Creating the window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL){
            cout<<"Window cannot be created! SDL_Error: "<<SDL_GetError();
            success = false;
        }
        else{
            //Get Window Surface
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }
    return success;
}

//Loads Media
bool loadMedia() {
    bool success = true;

    //Load Splash Image
    gHelloWorld = SDL_LoadBMP("sourceFiles/tartrus.bmp");
    if( gHelloWorld == NULL ){
        cout<<"Unable to load the image. SDL Error: "<<SDL_GetError();
        success = false;
    }

    return success;
}

//Frees Media and Shuts down SDL
void close(){
    //Deallocating the Surface 
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;

    //Destroy Window
    gWindow = NULL;

    //Quits the SDL Subsystems
    SDL_Quit();
}

int main( int argc, char* args[] ) {
    //Start U[ SDL and Create a Window
    if( !init() ){
        cout<<"failed to Initalize"<<endl;
    }
    else {
        if( !loadMedia() ){
            cout<<"falied to load media"<<endl;
        }
        else{
            //Apply the image
            SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

            //Update the Surface
            SDL_UpdateWindowSurface( gWindow );

            //Wait two seconds
            SDL_Delay(2000);
            }
    }
    //Free resources and Deallocate
    close();


    return 0;

}

