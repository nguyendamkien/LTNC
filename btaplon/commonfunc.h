
#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <SDL.h>
#include <SDL_main.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <vector>

using namespace std;

static SDL_Window* gWindow = NULL;
static SDL_Renderer* gRenderer = NULL;

//The music that will be played
static Mix_Music *gMusic = NULL;

//The sound effects that will be used
static Mix_Chunk *gEat = NULL;
static Mix_Chunk *gExplosion = NULL;

//*Screen
const int FRAME_PER_SECOND = 60; // fps -- la so frame tren 1 giay
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 640;
//const int SCREEN_BPP = 32;

#define BLANK_TILE 0
#define TILE_SIZE 64 // map
#define MAX_MAP_X 304
#define MAX_MAP_Y 12

#define STATE_BALL_BLACK 1
#define STATE_BALL_RED 4
#define STATE_BALL_BLUE 5
#define STATE_WIN 9
typedef struct Input
{
  int left_;
  int right_;
  int up_;
  int down_;
  int jump_;
};


typedef struct Map
{
    int start_x_;
    int start_y_;

    int max_x_; // chi so o
    int max_y_;

    int tile[MAX_MAP_Y][MAX_MAP_X]; //
    char* file_name;
};

//xu li va cham
namespace SDLCommonfunc
{
    bool Checkcollision(const SDL_Rect& object1, const SDL_Rect& object2);

      int ShowMenu(SDL_Renderer* g_screen,
                      const std::string& menu1,
                      const std::string& menu2,
                      const std::string& img_name);

      int ShowMenuend(SDL_Renderer* g_screen,
                      TTF_Font* font,
                      string myscore,
                      string highscore,
                      const std::string& menu1,
                      const string& menu2,
                      const std::string& img_name);

    int ShowMenuwin(SDL_Renderer* g_screen,
                      TTF_Font* font,
                      string myscore,
                      string highscore,
                      const std::string& menu1,
                      const std::string& img_name);

}//



#endif // COMMON_FUNCTION_H_
