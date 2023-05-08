#include "explosion.h"

explosion::explosion()
{
    width_frame_ = 0;
    height_frame_ = 0;
    frame_ = 0;
}

explosion::~explosion()
{

}

bool explosion::LoadImg(std::string path, SDL_Renderer* gRenderer)
{
    bool ret = BaseObject::LoadImg(path, gRenderer);
    if(ret)
    {
        width_frame_ = rect_.w/4;
        height_frame_ = rect_.h;

    }
    return ret;
}


void explosion::set_clips()
{
    if(width_frame_ > 0 && height_frame_ > 0)
    {
        frame_clip_[0].x = 0;
        frame_clip_[0].y = 0;
        frame_clip_[0].w = width_frame_;
        frame_clip_[0].h = height_frame_;

        frame_clip_[1].x = width_frame_;
        frame_clip_[1].y = 0;
        frame_clip_[1].w = width_frame_;
        frame_clip_[1].h = height_frame_;

        frame_clip_[2].x = 2*width_frame_;
        frame_clip_[2].y = 0;
        frame_clip_[2].w = width_frame_;
        frame_clip_[2].h = height_frame_;

        frame_clip_[3].x = 3*width_frame_;
        frame_clip_[3].y = 0;
        frame_clip_[3].w = width_frame_;
        frame_clip_[3].h = height_frame_;

    }
}

void explosion::Show(SDL_Renderer* gRenderer)
{

    SDL_Rect* currentClip = &frame_clip_[frame_]; // dang o clip

    SDL_Rect rendQuad = {rect_.x, rect_.y, width_frame_, height_frame_};

    SDL_RenderCopy(gRenderer, p_object_, currentClip, &rendQuad ); // day hinh anh
}
