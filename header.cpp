#include <iostream>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "header.h"
#include <SDL.h>

using namespace std;

void logSDLError(ostream& os, const string &msg, bool fatal)
{
     os << msg << " Error: " << SDL_GetError() << endl;
     if (fatal)
     {
         SDL_Quit();
         exit(1);
     }
}
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer, const int SCREEN_WIDTH, const int SCREEN_HEIGHT,const string WINDOW_TITLE)
{
     if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(cout, "SDL_Init", true);
     window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
     //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
     if (window == nullptr) logSDLError(cout, "CreateWindow", true);
     //Khi thông thường chạy với môi trường bình thường ở nhà
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
     //Khi chạy ở máy thực hành WinXP ở trường (máy ảo)
        //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
     if (renderer == nullptr) logSDLError(cout, "CreateRenderer", true);
     SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
     SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
void waitUntilKeyPressed()
{
     SDL_Event e;
     while (true)
     {
         if ( SDL_WaitEvent(&e) != 0 && (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
         SDL_Delay(100);
     }
}
SDL_Texture* loadTexture(string path, SDL_Renderer* renderer)
{
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadSurface = IMG_Load(path.c_str());
    if(loadSurface == nullptr)
    {
        cout << "Unable to load image " << path << " SDL_Image Error: " << IMG_GetError() << endl;
    }
    else
    {
        newTexture = SDL_CreateTextureFromSurface(renderer, loadSurface);
        if(newTexture == nullptr)
        {
            cout << "Unable to create texture from " << path << " SDL_Error: " << SDL_GetError() << endl;
        }
        SDL_FreeSurface(loadSurface);
    }
    return newTexture;
}
bool CrashInto(int x, int y, int w, int h, int ox, int oy, int ow, int oh)
{
    bool flag = false;
    if(x + w >= ox && x <= ox + ow && y + h >= oy && y <= oy + oh)
        flag = true;
    return flag;
}

void setColor(SDL_Renderer* renderer, string s)
{
        if(s == "AliceBlue")
            SDL_SetRenderDrawColor(renderer, 240, 248, 255, 1);
        else if(s == "AntiqueWhile")
            SDL_SetRenderDrawColor(renderer, 250, 235, 215, 1);
        else if(s == "Aqua")
            SDL_SetRenderDrawColor(renderer, 0, 255, 255, 1);
        else if(s == "Aquamarine")
            SDL_SetRenderDrawColor(renderer, 127, 255, 212, 1);
        else if(s == "Azure")
            SDL_SetRenderDrawColor(renderer, 240, 255, 255, 1);
        else if(s == "Beige")
            SDL_SetRenderDrawColor(renderer, 245, 245, 220, 1);
        else if(s == "Bisque")
            SDL_SetRenderDrawColor(renderer, 255, 228, 196, 1);
        else if(s == "Black")
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
        else if(s == "BlanchedAlmond")
            SDL_SetRenderDrawColor(renderer, 255, 235, 205, 1);
        else if(s == "Blue")
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 1);
        else if(s == "BlueViolet")
            SDL_SetRenderDrawColor(renderer, 138, 43, 226, 1);
        else if(s == "Brown")
            SDL_SetRenderDrawColor(renderer, 165, 42, 42, 1);
        else if(s == "Chocolate")
            SDL_SetRenderDrawColor(renderer, 210, 105, 30, 1);
        else if(s == "Coral")
            SDL_SetRenderDrawColor(renderer, 255, 127, 80, 1);
        else if(s == "CornflowerBlue")
            SDL_SetRenderDrawColor(renderer, 100, 149, 237, 1);
        else if(s == "DarkCyan")
            SDL_SetRenderDrawColor(renderer, 0, 139, 139, 1);
        else if(s == "DarkGreen")
            SDL_SetRenderDrawColor(renderer, 0, 100, 0, 1);
        else if(s == "DarkOliveGreen")
            SDL_SetRenderDrawColor(renderer, 85, 107, 47, 1);
        else if(s == "DarkOrange")
            SDL_SetRenderDrawColor(renderer, 255, 140, 0, 1);
        else if(s == "DeepPink")
            SDL_SetRenderDrawColor(renderer, 255, 20, 147, 1);
        else if(s == "FireBrick")
            SDL_SetRenderDrawColor(renderer, 178, 34, 34, 1);
        else if(s == "ForestGreen")
            SDL_SetRenderDrawColor(renderer, 34, 139, 34, 1);
        else if(s == "Green")
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        else
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}
void renderGamePlay(SDL_Renderer* renderer)
{
    SDL_Texture* background = loadTexture("bg1.png", renderer);
    SDL_RenderCopy(renderer, background, NULL, NULL);
}


