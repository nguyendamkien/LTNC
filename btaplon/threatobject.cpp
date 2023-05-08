#include "threatobject.h"

threatobject::threatobject()
{
    width_frame_ = 0;
    height_frame_ = 0;
    x_val_ = 0;
    y_val_ = 0;
    x_pos_ = 0;
    y_pos_ = 0;
    on_ground_ = 0;
    come_back_time_ = 0;
    frame_ = 0;
    animation_a_ = 0;
    animation_b_ = 0;
    input_type_.left_ = 0;
    type_move_ = STATIC_THREAT;


}

threatobject::~threatobject()
{

}

bool threatobject::LoadImg(std::string path, SDL_Renderer* gRenderer)
{
    bool ret = BaseObject::LoadImg(path, gRenderer);
    if(ret)
    {
        width_frame_ = rect_.w/5;
        height_frame_ = rect_.h;

    }
    return ret;
}

SDL_Rect threatobject::GetRectFrame()
{
    SDL_Rect rect;
    rect.x = rect_.x;
    rect.y = rect_.y;
    rect.w = width_frame_;
    rect.h = height_frame_;

    return rect;
}

void threatobject::set_clips()
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

        frame_clip_[4].x = 4*width_frame_;
        frame_clip_[4].y = 0;
        frame_clip_[4].w = width_frame_;
        frame_clip_[4].h = height_frame_;
    }
}

void threatobject::Show(SDL_Renderer* des)
{

    if(come_back_time_ == 0)
    {
        rect_.x = x_pos_ - map_x_;
        rect_.y = y_pos_ - map_y_;
        frame_++;
        if(frame_ >= 5)
        {
            frame_ = 0;
        }



        SDL_Rect* currentClip = &frame_clip_[frame_]; // dang o clip

        SDL_Rect rendQuad = {rect_.x, rect_.y, width_frame_, height_frame_};

        SDL_RenderCopy(des, p_object_, currentClip, &rendQuad ); // day hinh anh
    }
}

void threatobject::DoPlayer(Map& gMap)
{
    if(come_back_time_ == 0)
    {
        x_val_ = 0;
        y_val_ += THREAT_GRAVITY_SPEED;
        if(y_val_ >= THREAT_MAX_FALL_SPEED)
        {
            y_val_ = THREAT_MAX_FALL_SPEED;
        }

        if(input_type_.left_ == 1)
        {
            x_val_ -= 3;
        }
        else if(input_type_.right_ == 1)
        {
            x_val_ += 3;
        }


        CheckToMap(gMap);
    }
    else if(come_back_time_ > 0)
    {
        come_back_time_--;
        if(come_back_time_ == 0)
        {
            y_pos_ = 0;
            x_val_ = 0;
            y_val_ = 0;
            if(x_pos_ > 256)
            {
                x_pos_ -= 256;
                animation_a_ -= 256;
                animation_b_ -= 256;
            }
            else
            {
                x_pos_ = 0;
            }

            come_back_time_ = 0;
            input_type_.left_ = 1;
        }
    }
}


void threatobject::CheckToMap(Map& map_data)
{

    int x1 = 0;
    int x2 = 0; //kiem tra theo chieu x

    int y1 = 0;
    int y2 = 0;

    //check horizontal - chieu ngang
    int height_min = height_frame_ < TILE_SIZE ? height_frame_ : TILE_SIZE;

    x1 = (x_pos_ + x_val_)/TILE_SIZE; // vi tri hien tai + xval
    x2 = (x_pos_ + x_val_ + width_frame_ - 1)/TILE_SIZE; // neu duong bien trung nhau nen -1 de co sai so

    y1 = (y_pos_)/TILE_SIZE;
    y2 = (y_pos_ + height_min - 1)/TILE_SIZE;

    // kiem tra nhan vat con trong ban do ko
    if(x1 >= 0 && x2 <MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y)
    {
        if(x_val_ > 0) // main object is moving to right
        {
            int val1 = map_data.tile[y1][x2];
            int val2 = map_data.tile[y2][x2];
            if((val1 != BLANK_TILE  && val1 != STATE_BALL_RED && val1 != STATE_BALL_BLUE && val1 != STATE_BALL_BLACK)|| (val2 != BLANK_TILE && val2 != STATE_BALL_RED && val2 != STATE_BALL_BLUE && val1 != STATE_BALL_BLACK))
            {
                x_pos_ = x2*TILE_SIZE;
                x_pos_ -= (width_frame_ + 1); // +1 do da tru di 1
                x_val_ = 0;
            }

        }
        else if(x_val_ < 0)
        {
            int val1 = map_data.tile[y1][x1];
            int val2 = map_data.tile[y2][x1];

            if((val1 != BLANK_TILE  && val1 != STATE_BALL_RED && val1 != STATE_BALL_BLUE && val1 != STATE_BALL_BLACK )|| (val2 != BLANK_TILE && val2 != STATE_BALL_RED && val2 != STATE_BALL_BLUE && val2 != STATE_BALL_BLACK ))
            {
                x_pos_ = (x1+1)*TILE_SIZE;
                x_val_ = 0;
            }

        }
    }



    //check vertical

    int width_min = width_frame_ < TILE_SIZE ? width_frame_ : TILE_SIZE;

    x1 = (x_pos_)/TILE_SIZE;
    x2 = (x_pos_ + width_min)/TILE_SIZE; // neu duong bien trung nhau nen -1 de co sai so

    y1 = (y_pos_ + y_val_)/TILE_SIZE;
    y2 = (y_pos_ + y_val_ + height_frame_ -1)/TILE_SIZE;

    // kiem tra nhan vat con trong ban do ko
    if(x1 >= 0 && x2 <MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y)
    {
        if(y_val_ > 0) // main object is moving to right
        {
            int val1 = map_data.tile[y2][x1];
            int val2 = map_data.tile[y2][x2];


            if((val1 != BLANK_TILE  && val1 != STATE_BALL_RED && val1 != STATE_BALL_BLUE && val1 != STATE_BALL_BLACK )|| (val2 != BLANK_TILE && val2 != STATE_BALL_RED && val2 != STATE_BALL_BLUE && val2 != STATE_BALL_BLACK))
            {
                y_pos_ = y2*TILE_SIZE;
                y_pos_ -= (height_frame_ + 1); // +1 do da tru di 1
                y_val_ = 0;
                on_ground_ = true;


            }

        }
        else if(y_val_ < 0) // thuc hien khi nhay len
        {
            int val1 = map_data.tile[y1][x1];
            int val2 = map_data.tile[y1][x2];
            if((val1 != BLANK_TILE  && val1 != STATE_BALL_RED && val1 != STATE_BALL_BLUE && val1 != STATE_BALL_BLACK )|| (val2 != BLANK_TILE && val2 != STATE_BALL_RED && val2 != STATE_BALL_BLUE && val1 != STATE_BALL_BLACK))
            {
                y_pos_ = (y1+1)*TILE_SIZE;
                y_val_ = 0;
            }

        }
    }

    x_pos_ += x_val_;
    y_pos_ += y_val_;

    if(x_pos_ < 0) // lui ve mep ban do
    {
        x_pos_ = 0;
    }
    else if (x_pos_ + width_frame_ > map_data.max_x_)
    {
        x_pos_ = map_data.max_x_ - width_frame_ -1;
    }

    if(y_pos_ > map_data.max_y_)
    {
        come_back_time_ = 60;
    }

}

void threatobject::ImpMoveType(SDL_Renderer* screen)
{
    if(type_move_ == STATIC_THREAT)
    {
        ;
    }
    else if(type_move_ == MOVE_IN_SPACE_THREAT)
    {
        if(on_ground_ == true)
        {
            if(x_pos_ >animation_b_)
            {
                input_type_.left_ = 1;
                input_type_.right_ = 0;
                LoadImg("img//threat_left.png", screen);

            }
            else if(x_pos_ < animation_a_)
            {
                input_type_.left_ = 0;
                input_type_.right_ = 1;
                LoadImg("img//threat_right.png", screen);
            }
            else if(input_type_.left_ == 1)
            {
                LoadImg("img//threat_left.png", screen);
            }
        }
    }
    else if(type_move_ = MOVE_IN_SPACE_THREAT_1)
    {
        if(on_ground_ == true)
        {
            if(x_pos_ >animation_b_)
            {
                input_type_.left_ = 1;
                input_type_.right_ = 0;
                LoadImg("img//threat_left_1.png", screen);

            }
            else if(x_pos_ < animation_a_)
            {
                input_type_.left_ = 0;
                input_type_.right_ = 1;
                LoadImg("img//threat_right_1.png", screen);
            }
            else if(input_type_.left_ == 1)
            {
                LoadImg("img//threat_left_1.png", screen);
            }
        }
    }
}
