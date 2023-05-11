
#include "MainObject.h"

MainObject::MainObject()
{
    frame_ = 0;
    x_pos_ = 0;
    y_pos_ = 0;
    x_val_ = 0;
    y_val_ = 0;
    width_frame_ = 0;
    height_frame_ = 0;
    status_ = WALK_NONE;
    input_type_.left_ = 0;
    input_type_.right_ = 0;
    input_type_.jump_ = 0;
    input_type_.down_ = 0;
    input_type_.up_ = 0;
    on_ground_ = false;
    map_x_ = 0;
    map_y_ = 0;
    count_ball_red = 0;
    count_ball_blue = 0;

    come_back_time_ = 0;
    number_falling = 0;
    number_life = 0;
    win = false;
}

MainObject::~MainObject()
{

}

bool MainObject::LoadImg(std::string path, SDL_Renderer* gRenderer)
{
    bool ret = BaseObject::LoadImg(path, gRenderer);

    if(ret == true)
    {
        width_frame_ = rect_.w/5;
        height_frame_ = rect_.h;
    }

    return ret;
}

SDL_Rect MainObject::GetRectFrame()
{
    SDL_Rect rect;
    rect.x = rect_.x;
    rect.y = rect_.y;
    rect.w = width_frame_;
    rect.h = height_frame_;
    return rect;
}

void MainObject::set_clips()
{

    if(width_frame_ > 0 && height_frame_>0)
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

void MainObject::Show(SDL_Renderer* gRenderer)
{
    updateimageplayer(gRenderer); // load hinh anh nhan vat

    if(input_type_.left_ == 1 || input_type_.right_ == 1)
    {
        frame_ ++;
    }
    else
    {
        frame_ = 0; // ko bam thi frame = 0
    }

    if(frame_ >= 5)
    {
        frame_ = 0;
    }
    if(come_back_time_ == 0) // khi nhan vat roi ko load anh
    {

        rect_.x = x_pos_ - map_x_;
        rect_.y = y_pos_ - map_y_;

        SDL_Rect* current_clip = &frame_clip_[frame_]; // dang o clip

        SDL_Rect renderQuad = {rect_.x, rect_.y, width_frame_, height_frame_};

        SDL_RenderCopy(gRenderer, p_object_, current_clip, &renderQuad ); // day hinh anh
    }
}
void MainObject::HandelInputaction(SDL_Event events, SDL_Renderer* gRenderer)
{
    if(events.type == SDL_KEYDOWN)
    {
        switch(events.key.keysym.sym)
        {
        case SDLK_RIGHT:
        {
            status_ = WALK_RIGHT;
            input_type_.right_ = 1;
            input_type_.left_ = 0; // phong truong hop nhan ca 2 phim
            updateimageplayer(gRenderer);
        }
        break;
        case SDLK_LEFT:
        {
            status_ = WALK_LEFT;
            input_type_.left_ = 1;
            input_type_.right_ = 0;
            updateimageplayer(gRenderer);
        }
        break;

        case SDLK_UP:
        {
            input_type_.jump_ = 1;
        }
        break;

        case SDLK_SPACE:
            {
                BulletObject* p_bullet = new BulletObject();
                p_bullet->LoadImg("img//bullet.png", gRenderer);
                if(status_ == WALK_LEFT)
                {
                    p_bullet->Set_bullet_dir(BulletObject::dir_left);
                    p_bullet->SetRect(this->rect_.x - 20, rect_.y + height_frame_*0.5);
                }
                else
                {
                    p_bullet->Set_bullet_dir(BulletObject::dir_right);
                    p_bullet->SetRect(this->rect_.x + width_frame_ - 20, rect_.y + height_frame_*0.5);
                }



                p_bullet->Set_x_val(20);
                p_bullet->Set_is_move(true);

                p_bullet_list_.push_back(p_bullet);
            }
        default:
            break;
        }
    }
    else if (events.type == SDL_KEYUP) // nha ban phim
    {
        switch(events.key.keysym.sym)
        {
        case SDLK_RIGHT:
        {
            input_type_.right_ = 0;
        }
        break;
        case SDLK_LEFT:
        {
            input_type_.left_ = 0;
        }
        break;

        case SDLK_UP:
        {
            input_type_.jump_ = 0;
        }
        break;
        default:
            break;
        }
    }


}

void MainObject::HandleBullet(SDL_Renderer* gRenderer)
{
    for(int i=0; i < p_bullet_list_.size(); i++)
    {
        BulletObject* p_bullet = p_bullet_list_.at(i);
        if(p_bullet != NULL)
        {
            if(p_bullet->Get_is_move() == true)
            {
                p_bullet->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
                p_bullet->Render(gRenderer);
            }
            else
            {
                p_bullet_list_.erase(p_bullet_list_.begin() + i);
                if(p_bullet != NULL)
                {
                    delete p_bullet;
                    p_bullet = NULL;
                }
            }
        }
    }
}

void MainObject::RemoveBullet(const int& idx) // xoa dan
{
    int size = p_bullet_list_.size();
    if(size>0 && idx < size)
    {
        BulletObject* p_bullet = p_bullet_list_.at(idx);
        p_bullet_list_.erase(p_bullet_list_.begin() + idx);

        if(p_bullet)
        {
            delete p_bullet;
            p_bullet = NULL;
        }
    }
}

void MainObject::DoPlayer(Map& map_data, Mix_Chunk* gHigh)
{
    if(come_back_time_ == 0)
    {
        x_val_ = 0;
        y_val_ += GRAVITY_SPEED; //nhan vat roi - toc do roi

        if(y_val_ >= MAX_FALL_SPEED) // tang den mot do nhat dinh
        {
            y_val_ = MAX_FALL_SPEED;
        }

        if(input_type_.left_ == 1)
        {
            x_val_ -= PLAYER_SPEED;

        }
        else if (input_type_.right_ == 1)
        {
            x_val_ += PLAYER_SPEED;
        }

        if(input_type_.jump_ == 1)
        {

            if(on_ground_ == true) // dang tren mat dat moi nhay
            {
                y_val_ = - PLAYER_JUMP_VAL;
            }
            if(y_val_ == 0) input_type_.right_ == 0;
            on_ground_ = false;
            input_type_.jump_ = 0;
        }

        CheckToMap(map_data, gHigh);
        CenterEntityOnMap(map_data);
    }



    if(come_back_time_ > 0)
    {
        come_back_time_--;
        if(come_back_time_ == 0)
        {
            y_pos_ = 0;
            x_val_ = 0;
            y_val_ = 0;
            if(x_pos_> 256)
            {
                x_pos_ -= 256; // roi o vi tri giua ban do xuong o vi tri roi lech 4 o
            }
            else x_pos_ = 0;

        }
    }


}

void MainObject::CenterEntityOnMap(Map& map_data)
{
    float newx = x_pos_ - (SCREEN_WIDTH/2); // di chuyen den nuwa ban do thi bi cuon
    map_data.start_x_ = map_data.start_x_ + (newx - map_data.start_x_)*0.04;
    if(map_data.start_x_ < 0)
    {
        map_data.start_x_ = 0;
    }
    else if(map_data.start_x_ + SCREEN_WIDTH >= map_data.max_x_)
    {
        map_data.start_x_ = map_data.max_x_ - SCREEN_WIDTH;
    }

    float newy = y_pos_ - (SCREEN_WIDTH/2); // di chuyen den nuwa ban do thi bi cuon
    map_data.start_y_ = map_data.start_y_ + (newy - map_data.start_y_)*0.04;
    if(map_data.start_y_ < 0)
    {
        map_data.start_y_ = 0;

    }
    else if(map_data.start_y_ + SCREEN_HEIGHT >= map_data.max_y_)
    {
        map_data.start_y_ = map_data.max_y_ - SCREEN_HEIGHT;
    }

}

void MainObject::CheckToMap(Map& map_data, Mix_Chunk* gHigh)
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
            if(val1 == STATE_BALL_RED || val2 == STATE_BALL_RED)
            {
                Mix_PlayChannel( -1, gHigh, 0 );
                map_data.tile[y1][x2] = 0;
                map_data.tile[y2][x2] = 0;
                increaseballred();

            }
            else  if(val1 == STATE_BALL_BLUE || val2 == STATE_BALL_BLUE)
            {
                Mix_PlayChannel( -1, gHigh, 0 );
                map_data.tile[y1][x2] = 0;
                map_data.tile[y2][x2] = 0;
                increaseballblue();

            }
            else if(val1 == STATE_BALL_BLACK || val2 == STATE_BALL_BLACK)
            {
                Mix_PlayChannel( -1, gHigh, 0 );
                map_data.tile[y1][x2] = 0;
                map_data.tile[y2][x2] = 0;
                increaselife();
            }
            else if(val1 == STATE_WIN || val2 == STATE_WIN)
            {
                win = true;
            }
            else
            {
                if(val1 != BLANK_TILE || val2 != BLANK_TILE)
                {
                    x_pos_ = x2*TILE_SIZE;
                    x_pos_ -= (width_frame_ + 1); // +1 do da tru di 1
                    x_val_ = 0;
                }
            }
        }
        else if(x_val_ < 0)
        {
            int val1 = map_data.tile[y1][x1];
            int val2 = map_data.tile[y2][x1];
            if(val1 == STATE_BALL_RED || val2 == STATE_BALL_RED)
            {
                Mix_PlayChannel( -1, gHigh, 0 );
                map_data.tile[y1][x1] = 0;
                map_data.tile[y2][x1] = 0;
                increaseballred();

            }
            else if(val1 == STATE_BALL_BLUE || val2 == STATE_BALL_BLUE)
            {
                Mix_PlayChannel( -1, gHigh, 0 );
                map_data.tile[y1][x1] = 0;
                map_data.tile[y2][x1] = 0;
                increaseballblue();

            }
            else if(val1 == STATE_BALL_BLACK || val2 == STATE_BALL_BLACK)
            {
                Mix_PlayChannel( -1, gHigh, 0 );
                map_data.tile[y1][x1] = 0;
                map_data.tile[y2][x1] = 0;
                increaselife();
            }
            else if(val1 == STATE_WIN || val2 == STATE_WIN)
            {
                win = true;
            }
            else
            {
                if(val1 != BLANK_TILE || val2 != BLANK_TILE)
                {
                    x_pos_ = (x1+1)*TILE_SIZE;
                    x_val_ = 0;
                }
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
            if(val1 == STATE_BALL_RED || val2 == STATE_BALL_RED)
            {
                Mix_PlayChannel( -1, gHigh, 0 );
                map_data.tile[y2][x1] = 0;
                map_data.tile[y2][x2] = 0;
                increaseballred();

            }
            else if(val1 == STATE_BALL_BLUE || val2 == STATE_BALL_BLUE)
            {
                Mix_PlayChannel( -1, gHigh, 0 );
                map_data.tile[y2][x1] = 0;
                map_data.tile[y2][x2] = 0;
                increaseballblue();

            }
            else if(val1 == STATE_BALL_BLACK || val2 == STATE_BALL_BLACK)
            {
                Mix_PlayChannel( -1, gHigh, 0 );
                map_data.tile[y2][x1] = 0;
                map_data.tile[y2][x2] = 0;
                increaselife();
            }
            else if(val1 == STATE_WIN || val2 == STATE_WIN)
            {
                win = true;
            }
            else
            {
                if(val1 != BLANK_TILE || val2 != BLANK_TILE)
                {
                    y_pos_ = y2*TILE_SIZE;
                    y_pos_ -= (height_frame_ + 1); // +1 do da tru di 1
                    y_val_ = 0;
                    on_ground_ = true;
                    if(status_ == WALK_NONE)
                    {
                        status_ = WALK_RIGHT;
                    }

                }
            }
        }
        else if(y_val_ < 0) // thuc hien khi nhay len
        {
            int val1 = map_data.tile[y1][x1];
            int val2 = map_data.tile[y1][x2];
            if(val1 == STATE_BALL_RED || val2 == STATE_BALL_RED)
            {
                Mix_PlayChannel( -1, gHigh, 0 );
                map_data.tile[y1][x1] = 0;
                map_data.tile[y1][x2] = 0;
                increaseballred();

            }
            else if(val1 == STATE_BALL_BLUE || val2 == STATE_BALL_BLUE)
            {
                Mix_PlayChannel( -1, gHigh, 0 );
                map_data.tile[y1][x1] = 0;
                map_data.tile[y1][x2] = 0;
                increaseballblue();

            }
            else if(val1 == STATE_BALL_BLACK || val2 == STATE_BALL_BLACK)
            {
                Mix_PlayChannel( -1, gHigh, 0 );
                map_data.tile[y1][x1] = 0;
                map_data.tile[y1][x2] = 0;
                increaselife();
            }
            else if(val1 == STATE_WIN || val2 == STATE_WIN)
            {
                win = true;
            }
            else
            {
                if(val1 != BLANK_TILE || val2 != BLANK_TILE)
                {
                    y_pos_ = (y1+1)*TILE_SIZE;
                    y_val_ = 0;
                }
            }
        }
    }

    x_pos_ += x_val_;
    y_pos_ += y_val_;

    if(x_pos_ < 0) // lui ve mep ban do
    {
        x_pos_ = 0;
    }
    if(x_pos_ + width_frame_ > map_data.max_x_)
    {
        x_pos_ = map_data.max_x_ - width_frame_ -1;
    }

    if(y_pos_ > map_data.max_y_)
    {
        increse_falling();
        set_come_back_time_(60);
    }

}

void MainObject::updateimageplayer(SDL_Renderer* gRenderer)
{
    if(on_ground_ == true)
    {
        if(status_ == WALK_LEFT)
        {
            LoadImg("img//walkleft.png", gRenderer);
        }
        else
        {
            LoadImg("img//walkright.png", gRenderer);
        }
    }
    else
    {
        if(status_ == WALK_LEFT)
        {
            LoadImg("img//jumpleft1.png", gRenderer);
        }
        else
        {
            LoadImg("img//jumpright1.png", gRenderer);
        }
    }
}

void MainObject::increaseballred()
{
    count_ball_red++;
}

void MainObject::increaseballblue()
{
    count_ball_blue++;
}


void MainObject::increse_falling()
{
    number_falling++;
}

void MainObject::increaselife()
{
    number_life++;
}

