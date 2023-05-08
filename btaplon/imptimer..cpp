
#include "imptimer.h"
#include "commonfunc.h"

imptimer::imptimer()
{
    start_tick_ = 0;
    paused_tick_ = 0;
    is_paused_ = false;
    is_started_ = false;

}

imptimer::~imptimer()
{
}

void imptimer::start()
{
    is_started_ = true;
    is_paused_ = false;
    start_tick_ = SDL_GetTicks(); //thoi gian tu khi thu vien khoi dong
}

void imptimer::stop()
{
    is_paused_ = false;
    is_started_ = false;
}

void imptimer::paused()
{
    if(is_started_ == true && is_paused_ == false)
    {
        is_paused_ = true;
        paused_tick_ = SDL_GetTicks() - start_tick_;
    }
}

void imptimer::unpaused()
{
    if(is_paused_ == true)
    {
        is_paused_ = false;
        paused_tick_ = SDL_GetTicks() - paused_tick_;
        paused_tick_ = 0;
    }
}
int imptimer::get_ticks() // lay thoi gian troi qua
{
    if(is_started_ == true)
    {
        if(is_paused_ == true)
        {
            return paused_tick_;
        }
        else
        {
            return SDL_GetTicks() - start_tick_;
        }
    }

    return 0;
}

bool imptimer::is_started()
{
    return is_started_;
}

bool imptimer::is_paused()
{
    return is_paused_;
}

