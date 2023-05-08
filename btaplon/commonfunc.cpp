
#include "commonfunc.h"
#include "textobject.h"
#include "BaseObject.h"

bool SDLCommonfunc::Checkcollision(const SDL_Rect& rect_player, const SDL_Rect& rect_threat)
{
    bool check = false;

    int left_a = rect_player.x;
    int right_a = rect_player.x + rect_player.w;
    int top_a = rect_player.y;
    int bottom_a = rect_player.y + rect_player.h;

    int left_b = rect_threat.x;
    int right_b = rect_threat.x + rect_threat.w;
    int top_b = rect_threat.y;
    int bottom_b = rect_threat.y + rect_threat.h;

    // Case 1: size object 1 < size object 2
    if (left_a > left_b && left_a < right_b)
    {
        if (top_a > top_b && top_a < bottom_b)
        {
            check =  true;
        }
    }

    if (left_a > left_b && left_a < right_b)
    {
        if (bottom_a > top_b && bottom_a < bottom_b)
        {
            check = true;
        }
    }

    if (right_a > left_b && right_a < right_b)
    {
        if (top_a > top_b && top_a < bottom_b)
        {
            check - true;
        }
    }

    if (right_a > left_b && right_a < right_b)
    {
        if (bottom_a > top_b && bottom_a < bottom_b)
        {
            check = true;
        }
    }

    // Case 2: size object 1 < size object 2
    if (left_b > left_a && left_b < right_a)
    {
        if (top_b > top_a && top_b < bottom_a)
        {
            check = true;
        }
    }

    if (left_b > left_a && left_b < right_a)
    {
        if (bottom_b > top_a && bottom_b < bottom_a)
        {
            check = true;
        }
    }

    if (right_b > left_a && right_b < right_a)
    {
        if (top_b > top_a && top_b < bottom_a)
        {
            check = true;
        }
    }

    if (right_b > left_a && right_b < right_a)
    {
        if (bottom_b > top_a && bottom_b < bottom_a)
        {
            check =  true;
        }
    }

    // Case 3: size object 1 = size object 2
    if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
    {
        check = true;
    }
    return check;
}


int SDLCommonfunc::ShowMenu(SDL_Renderer* g_screen,

                            const std::string& menu1,
                            const std::string& menu2,
                            const std::string& img_name)
{
    char* img_file = (char*)img_name.c_str();

    int time = 0;
    int x = 0;
    int y = 0;
    const int kMenuNum = 2;
    BaseObject optionmenu[kMenuNum];


    BaseObject gBackground;
    bool ret = gBackground.LoadImg(img_file, g_screen);

    optionmenu[0].SetRect(SCREEN_WIDTH*0.3 - 150, SCREEN_HEIGHT*0.5 - 40);
    optionmenu[0].LoadImg(menu1, g_screen);
    optionmenu[1].SetRect(SCREEN_WIDTH*0.3 - 150, SCREEN_HEIGHT*0.6 + 40);
    optionmenu[1].LoadImg(menu2, g_screen );






    SDL_Event event;
    while (1)
    {
        time = SDL_GetTicks();
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                optionmenu[0].Free();
                optionmenu[1].Free();
                gBackground.Free();
                return 1;
            /*case SDL_MOUSEMOTION:
                x = event.motion.x;
                y = event.motion.y;
                for (int i = 0; i < kMenuNum; ++i)
                {
                    if (x >= optionmenu[i].GetRect().x && x <= optionmenu[i].GetRect().x + optionmenu[i].GetRect().w &&
                        y >= optionmenu[i].GetRect().y && y <= optionmenu[i].GetRect().y + optionmenu[i].GetRect().h)
                    {
                        if (!selected[i])
                        {
                            selected[i] = 1;
                            text_object[i].SetText(labels[i]);
                            text_object[i].SetColor(color[1].r, color[1].g, color[1].b);
                            text_object[i].LoadFromRenderText(font, g_screen);
                        }
                    }
                    else
                    {
                        if (selected[i])
                        {
                            selected[i] = 0;
                            text_object[i].Free();
                            text_object[i].SetText(labels[i]);
                            text_object[i].SetColor(color[0].r, color[0].g, color[0].b);
                            text_object[i].LoadFromRenderText(font, g_screen);
                        }
                    }
                }
                break;*/
            case SDL_MOUSEBUTTONDOWN:
                x = event.button.x;
                y = event.button.y;
                for (int i = 0; i < kMenuNum; ++i)
                {
                    if (x >= optionmenu[i].GetRect().x && x <= optionmenu[i].GetRect().x + optionmenu[i].GetRect().w &&
                            y >= optionmenu[i].GetRect().y && y <= optionmenu[i].GetRect().y + optionmenu[i].GetRect().h)
                    {
                        optionmenu[0].Free();
                        optionmenu[1].Free();
                        gBackground.Free();
                        return i;
                    }
                }
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    optionmenu[0].Free();
                    optionmenu[1].Free();
                    gBackground.Free();
                    return 1;
                }
            }
        }

        gBackground.Render(g_screen, NULL);

        for (int i = 0; i < kMenuNum; ++i)
        {
            optionmenu[i].Render(g_screen, nullptr);
        }


        SDL_RenderPresent(g_screen);
        if (1000 / 30 > (SDL_GetTicks() - time))
            SDL_Delay(1000 / 30 - (SDL_GetTicks() - time));
    }

    return 0;
}

int SDLCommonfunc::ShowMenuend(SDL_Renderer* g_screen,
                               TTF_Font* font,
                               string myscore,
                               string highscore,
                               const std::string& menu1,
                               const string& menu2,
                               const std::string& img_file)
{



    int time = 0;
    int x = 0;
    int y = 0;
    BaseObject optionmenu[2];


    BaseObject gBackground;
    bool ret = gBackground.LoadImg(img_file, g_screen);

    optionmenu[0].SetRect(SCREEN_WIDTH*0.5 - 120, SCREEN_HEIGHT*0.6 + 20);
    optionmenu[0].LoadImg(menu1, g_screen);

    optionmenu[1].SetRect(SCREEN_WIDTH*0.5 - 120, SCREEN_HEIGHT*0.8);
    optionmenu[1].LoadImg(menu2, g_screen);


    TextObject myscore_;
    myscore_.SetColor(TextObject::RED_TEXT);
    myscore_.SetText(myscore);
    myscore_.LoadFromRenderText(font, g_screen);

    TextObject highscore_;
    highscore_.SetColor(TextObject::RED_TEXT);
    highscore_.SetText(highscore);
    highscore_.LoadFromRenderText(font, g_screen);

    SDL_Event event;
    while (1)
    {
        time = SDL_GetTicks();
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                optionmenu[0].Free();
                optionmenu[1].Free();
                gBackground.Free();
                return 1;
            case SDL_MOUSEBUTTONDOWN:
                x = event.button.x;
                y = event.button.y;
                for (int i = 0; i < 2; ++i)
                {
                    if (x >= optionmenu[i].GetRect().x && x <= optionmenu[i].GetRect().x + optionmenu[i].GetRect().w &&
                            y >= optionmenu[i].GetRect().y && y <= optionmenu[i].GetRect().y + optionmenu[i].GetRect().h)
                    {
                        optionmenu[0].Free();
                        optionmenu[1].Free();
                        gBackground.Free();
                        return i;
                    }
                }
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    optionmenu[0].Free();
                    optionmenu[1].Free();
                    gBackground.Free();
                    myscore_.Free();
                    highscore_.Free();
                    return 1;
                }
            }
        }

        gBackground.Render(g_screen, NULL);
        optionmenu[0].Render(g_screen, nullptr);
        optionmenu[1].Render(g_screen, nullptr);


        myscore_.RenderText(g_screen, SCREEN_WIDTH*0.5 - 30, 170); // hien diem cua ban

        highscore_.RenderText(g_screen, SCREEN_WIDTH*0.5 - 30, 300);


        SDL_RenderPresent(g_screen);
        if (1000 / 30 > (SDL_GetTicks() - time))
            SDL_Delay(1000 / 30 - (SDL_GetTicks() - time));
    }

    return 0;
}


int SDLCommonfunc::ShowMenuwin(SDL_Renderer* g_screen,
                               TTF_Font* font,
                               string myscore,
                               string highscore,
                               const std::string& menu1,
                               const std::string& img_file)
{



    int time = 0;
    int x = 0;
    int y = 0;
    BaseObject optionmenu;


    BaseObject gBackground;
    bool ret = gBackground.LoadImg(img_file, g_screen);

    optionmenu.SetRect(SCREEN_WIDTH*0.5 - 120, SCREEN_HEIGHT*0.6 + 150);
    optionmenu.LoadImg(menu1, g_screen);



    TextObject myscore_;
    myscore_.SetColor(TextObject::RED_TEXT);
    myscore_.SetText(myscore);
    myscore_.LoadFromRenderText(font, g_screen);

    TextObject highscore_;
    highscore_.SetColor(TextObject::RED_TEXT);
    highscore_.SetText(highscore);
    highscore_.LoadFromRenderText(font, g_screen);

    SDL_Event event;
    while (1)
    {
        time = SDL_GetTicks();
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                optionmenu.Free();
                gBackground.Free();
                return 1;
            case SDL_MOUSEBUTTONDOWN:
                x = event.button.x;
                y = event.button.y;
                    if (x >= optionmenu.GetRect().x && x <= optionmenu.GetRect().x + optionmenu.GetRect().w &&
                            y >= optionmenu.GetRect().y && y <= optionmenu.GetRect().y + optionmenu.GetRect().h)
                    {

                        optionmenu.Free();
                        gBackground.Free();
                        return 1;
                    }
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    optionmenu.Free();
                    gBackground.Free();
                    myscore_.Free();
                    highscore_.Free();
                    return 1;
                }
            }
        }

        gBackground.Render(g_screen, NULL);
        optionmenu.Render(g_screen, nullptr);


        myscore_.RenderText(g_screen, SCREEN_WIDTH*0.5 - 10, 300); // hien diem cua ban

        highscore_.RenderText(g_screen, SCREEN_WIDTH*0.5 - 30, 420);


        SDL_RenderPresent(g_screen);
        if (1000 / 30 > (SDL_GetTicks() - time))
            SDL_Delay(1000 / 30 - (SDL_GetTicks() - time));
    }

    return 0;
}



