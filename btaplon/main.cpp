

#include "commonfunc.h"
#include "BaseObject.h"
#include "gamemap.h"
#include "MainObject.h"
#include "imptimer.h"
#include "threatobject.h"
#include "explosion.h"
#include "textobject.h"
#include "ShowObject.h"

BaseObject gbackground;
TTF_Font* fontball = NULL;
TTF_Font* fontmenu = NULL;

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }

                //Initialize SDL_mixer
                if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                    success = false;
                }
            }

            if(TTF_Init() == -1)
                success = false;

            fontball = TTF_OpenFont("font//visby.ttf", 28);
            if(fontball == NULL)
            {
                success = false;
            }

            fontmenu = TTF_OpenFont("font//visby.ttf", 50);
            if(fontmenu == NULL)
            {
                success = false;
            }

            //Load music
            gMusic = Mix_LoadMUS( "sound//music.wav" );
            if( gMusic == NULL )
            {
                printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
                success = false;
            }

            //Load sound effects


            gEat = Mix_LoadWAV( "sound//ting.wav" );
            if( gEat == NULL )
            {
                printf( "Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
                success = false;
            }

            gExplosion = Mix_LoadWAV( "sound//high.wav" );
            if( gExplosion == NULL )
            {
                printf( "Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
                success = false;
            }


        }
    }

    return success;
}

bool loadBackground()
{
    bool ret = gbackground.LoadImg("img/background1.png", gRenderer);
    if(ret == false)
        return false;
    return true;
}

void close()
{
    gbackground.Free();

    //Free the sound effects
    Mix_FreeChunk( gEat );
    Mix_FreeChunk( gExplosion );

    gEat = NULL;
    gExplosion = NULL;


    //Free the music
    Mix_FreeMusic( gMusic );
    gMusic = NULL;

    SDL_DestroyRenderer(gRenderer);
    gRenderer = NULL;

    SDL_DestroyWindow( gWindow );
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

vector<threatobject*> MakeThreatList()
{
    vector<threatobject*> list_threats;

    threatobject* dynamic_threats = new threatobject[20];
    for(int i=0; i < 20; i++)
    {
        threatobject* p_threat = (dynamic_threats + i);
        if(p_threat != NULL)
        {
            p_threat->LoadImg("img//threat_left.png", gRenderer);
            p_threat->set_clips();
            p_threat->set_type_move(threatobject::MOVE_IN_SPACE_THREAT);
            p_threat->set_x_pos(500 + i*600);// de threat roi rai rac
            p_threat->set_y_pos(250);

            int pos1 = p_threat->get_x_pos() - 100;
            int pos2 = p_threat->get_x_pos() + 100;
            p_threat->SetAnimationPos(pos1, pos2);
            p_threat->set_input_left(1);
            list_threats.push_back(p_threat);

        }
    }

    threatobject* dynamic_threats_1 = new threatobject[20];
    for(int i=0; i < 20; i++)
    {
        threatobject* p_threat = (dynamic_threats_1 + i);
        if(p_threat != NULL)
        {
            p_threat->LoadImg("img//threat_left_1.png", gRenderer);
            p_threat->set_clips();
            p_threat->set_type_move(threatobject::MOVE_IN_SPACE_THREAT_1);
            p_threat->set_x_pos(10000 + i*1200);// de threat roi rai rac
            p_threat->set_y_pos(250);

            int pos1 = p_threat->get_x_pos() - 120;
            int pos2 = p_threat->get_x_pos() + 120;
            p_threat->SetAnimationPos(pos1, pos2);
            p_threat->set_input_left(1);
            list_threats.push_back(p_threat);

        }
    }




    threatobject* threat_object = new threatobject[20];// tao 20 doi tuong
    for(int i=0; i<20; i++)
    {
        threatobject* p_threat = (threat_object + i);
        if(p_threat != NULL)
        {
            p_threat->LoadImg("img//threat_level1.png", gRenderer);
            p_threat->set_clips();
            p_threat->set_x_pos(830 + i*1200);// de threat roi rai rac
            p_threat->set_y_pos(250);
            p_threat->set_type_move(threatobject::STATIC_THREAT);
            p_threat->set_input_left(0);

            list_threats.push_back(p_threat);
        }
    }
    return list_threats;
}

//luu high score
void save_high_score(int score)
{
    ofstream file("high_score.txt");
    file << score << endl;
}

// doc high score
int load_high_score()
{
    int High_score;
    ifstream file("high_score.txt");
    file >> High_score;
    return High_score;
}



int main(int argc, char* agrv[])
{
    imptimer fps_timer;
    if(init() == false)
        return -1;

    if(loadBackground() == false)
        return -1;

        bool quit = false;
    bool is_running = true;
     //make menu
    int ret_menu = SDLCommonfunc::ShowMenu(gRenderer, "img//PlayGame.png", "img//Exit.png", "img//backgroundmenu.png");
    if(ret_menu == 1) quit = true;

again_label:

    gamemap game_map;
    game_map.LoadMap("map/map01.dat");
    game_map.LoadTiles(gRenderer);

    MainObject p_player;
    p_player.LoadImg("img//walkright.png", gRenderer);
    p_player.set_clips();


    ShowObject playerlife; // sinh mang
    playerlife.Init(gRenderer);

    ShowBall playereatballred;
    playereatballred.Init(gRenderer, "img//ball_red.png");
    playereatballred.SetPos(SCREEN_WIDTH*0.5 - 150, 15);

    ShowBall playereatballblue;
    playereatballblue.Init(gRenderer, "img//ball_blue.png");
    playereatballblue.SetPos(SCREEN_WIDTH*0.5 +100, 15);

    vector<threatobject*>  threats_list = MakeThreatList();

    explosion explosionplayer;
    bool explosionret =  explosionplayer.LoadImg("img//explosion.png", gRenderer);
    //if(explosionret == false) return -1;
    explosionplayer.set_clips();

    int number_die_ = 5;
    int number_fall_past = 0;
    int number_fall_new = 0;

    int number_life_past = 0;
    int number_life_new = 0;
    int my_score = 0;
    //time test
    TextObject score ;
    score.SetColor(TextObject::RED_TEXT);

    TextObject ballredgame;
    ballredgame.SetColor(TextObject::WHITE_TEXT);

    TextObject ballbluegame;
    ballbluegame.SetColor(TextObject::WHITE_TEXT);

    TextObject time_game;
    time_game.SetColor(TextObject::WHITE_TEXT);

    bool you_win = false;

    SDL_Event gEvent;

    //While application is running
    while( !quit )
    {
        fps_timer.start();
        //Handle events on queue
        while( SDL_PollEvent( &gEvent) != 0 )
        {
            //User requests quit
            if(gEvent.type == SDL_QUIT )
            {
                quit = true;
            }
            //Handle key press
            else if( gEvent.type == SDL_KEYDOWN )
            {
                switch( gEvent.key.keysym.sym )
                {

                case SDLK_9:
                    //If there is no music playing
                    if( Mix_PlayingMusic() == 0 )
                    {
                        //Play the music
                        Mix_PlayMusic( gMusic, -1 );
                    }
                    //If music is being played
                    else
                    {
                        //If the music is paused
                        if( Mix_PausedMusic() == 1 )
                        {
                            //Resume the music
                            Mix_ResumeMusic();
                        }
                        //If the music is playing
                        else
                        {
                            //Pause the music
                            Mix_PauseMusic();
                        }
                    }
                    break;

                case SDLK_0:
                    //Stop the music
                    Mix_HaltMusic();
                    break;

                case SDLK_p:
                    {
                        is_running = !is_running;
                    }

                }
            }

            p_player.HandelInputaction(gEvent, gRenderer);
        }

        if(is_running){

        fps_timer.unpaused();

        //Clear screen
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0XFF );
        SDL_RenderClear(gRenderer);

        gbackground.Render(gRenderer, NULL);
        Map map_data = game_map.getMap();


        p_player.SetmapXY(map_data.start_x_, map_data.start_y_);
        p_player.DoPlayer(map_data, gEat);
        p_player.Show(gRenderer);

        game_map.SetMap(map_data);
        game_map.DrawMap(gRenderer);

        playerlife.Show(gRenderer);
        playereatballred.Show(gRenderer);
        playereatballblue.Show(gRenderer);

        /*std::string str_time="Time: ";
        Uint32 time_val=SDL_GetTicks()/1000;
        Uint32 val_time=300-time_val;

        std::string str_val= std::to_string(val_time);
            str_time+=str_val;

            time_game.SetText(str_time);
            time_game.LoadFromRenderText(fontball, gRenderer);
            time_game.RenderText(gRenderer, SCREEN_WIDTH-200, 30);*/


        //show score
        string str_score = "Score: ";


        int ball_red = p_player.getballredeat();
        int ball_blue = p_player.getballblueeat();
        string ball_red_str = to_string(ball_red);
        string ball_blue_str = to_string(ball_blue);
        string score_str = to_string(ball_red*5+ball_blue*10);
        score.SetText(str_score + score_str);
        score.LoadFromRenderText(fontball, gRenderer);
        score.RenderText(gRenderer, SCREEN_WIDTH - 200, 15);
        score.Free();


        ballredgame.SetText(ball_red_str);
        ballredgame.LoadFromRenderText(fontball, gRenderer);
        ballredgame.RenderText(gRenderer, SCREEN_WIDTH*0.5 - 100, 15);
        ballredgame.Free();

        ballbluegame.SetText(ball_blue_str);
        ballbluegame.LoadFromRenderText(fontball, gRenderer);
        ballbluegame.RenderText(gRenderer, SCREEN_WIDTH*0.5 + 150, 15);
        ballbluegame.Free();


        for(int i=0; i<threats_list.size(); i++)
        {
            threatobject* p_threat = threats_list.at(i);
            if(p_threat != NULL)
            {
                p_threat->SetMapXY(map_data.start_x_, map_data.start_y_);
                p_threat->ImpMoveType(gRenderer);
                p_threat->DoPlayer(map_data);
                p_threat->Show(gRenderer);
            }

            SDL_Rect rect_player = p_player.GetRectFrame();
            SDL_Rect rect_threat = p_threat->GetRectFrame();

            int frame_explosion_width = explosionplayer.get_width_frame();
            int frame_explosion_height = explosionplayer.get_height_frame();

            number_life_new = p_player.get_number_life();
            if(number_life_new > number_life_past)
            {
                if(number_die_ < 5)
                {
                    number_die_++;
                    playerlife.Increase();
                    playerlife.Render(gRenderer);
                    number_life_past = number_life_new;

                }
                else{
                    number_life_past = number_life_new;
                }
            }





            bool check = false;

            check = SDLCommonfunc::Checkcollision(rect_player, rect_threat);

            number_fall_new = p_player.get_number_falling();

            if(check || number_fall_new > number_fall_past )
            {
                for(int i=0; i<4; i++)
                {
                    int x_pos = (p_player.GetRect().x + p_player.GetRect().w*0.25) - frame_explosion_width*0.5;
                    int y_pos = (p_player.GetRect().y + p_player.GetRect().h*0.5) - frame_explosion_height*0.5;

                    explosionplayer.set_frame(i);
                    explosionplayer.SetRect(x_pos, y_pos);
                    explosionplayer.Show(gRenderer);
                    SDL_RenderPresent(gRenderer);
                }
                Mix_PlayChannel( -1, gExplosion, 0 );
                number_fall_past = number_fall_new;
                number_die_--;
                if(number_die_ >= 0)
                {
                    p_player.SetRect(0,0);
                    p_player.set_come_back_time_(60);
                    SDL_Delay(1000);
                    playerlife.Decrease();
                    playerlife.Render(gRenderer);
                    continue;
                }
                else
                {
                    fps_timer.stop();
                    int high_score = load_high_score();
                    my_score = ball_red*5 + ball_blue*10;
                    if(my_score > high_score)
                    {
                        high_score = my_score;
                        save_high_score(high_score);
                    }
                    int ret_end = SDLCommonfunc::ShowMenuend(gRenderer,fontmenu,to_string(my_score),to_string(high_score),"img//RePlay.png","img//Exit.png","img//background00.png" );
                    if(ret_end == 1) quit = true;
                    else
                    {
                        quit = false;
                        goto again_label;
                    }


                }
            }


        }

        //khi win
        you_win = p_player.get_win();
            if(you_win)
            {
                int high_score = load_high_score();
                my_score = ball_red*5 + ball_blue*10;
                if(my_score > high_score)
                {
                    high_score = my_score;
                    save_high_score(high_score);
                }
                Mix_PauseMusic();
                int ret_win = SDLCommonfunc::ShowMenuwin(gRenderer,fontmenu,to_string(my_score),to_string(high_score),"img//Exit.png","img//YouWin.png" );
                if(ret_win == 1) quit = true;

            }

        SDL_RenderPresent(gRenderer);



        int real_imp_timer = fps_timer.get_ticks(); // thoi gian thuc su troi qua
        int time_one_frame = 2000/FRAME_PER_SECOND; // 1000 la 1 s = 1000ms
        if(real_imp_timer < time_one_frame) //thoigianthucte nho hon li thuyet
        {
            int delay_time = time_one_frame - real_imp_timer;
            if(delay_time >= 0)
                SDL_Delay(delay_time);// neu delay time cang lon thi chuong trinh cang cham dan. delay time lon khi FRAME_PER_SECOND nho
        }

    }

    else
    {
        fps_timer.paused();
        SDL_Delay(100);
    }
    }


    close();
    return 0;
}




