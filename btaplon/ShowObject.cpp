
#include "ShowObject.h"

ShowObject::ShowObject()
{
    number_ = 0;
}

ShowObject::~ShowObject()
{

}

void ShowObject::AddPos(const int& x)
{
    pos_list_.push_back(x);
}

void ShowObject::Init(SDL_Renderer* screen)
{
    LoadImg("img//heart.png", screen);
    number_ = 5; // 5 mang
    if(pos_list_.size() > 0)
    {
        pos_list_.clear(); // kiem tra truoc khi them vao de trong pos_list_ khong co gi
    }

    AddPos(20); // vi tri mang
    AddPos(60);
    AddPos(100);
    AddPos(140);
    AddPos(180);

}

void ShowObject::Show(SDL_Renderer* screen)
{
    for(int i=0; i < pos_list_.size(); i++)
    {
        rect_.x = pos_list_.at(i);
        rect_.y = 15;
        Render(screen);
    }
}

void ShowObject::Decrease()
{
    number_--;
    pos_list_.pop_back(); // xoa phan tu cuoi cung trong vector
}

void ShowObject::Increase()
{
    number_++;
    int last_pos = pos_list_.back(); // vi tri cuoi
    if(number_ == 1) last_pos = -20;
    last_pos += 40; // khoang cach 40
    pos_list_.push_back(last_pos);
}

ShowBall::ShowBall()
{
    x_pos = 0;
    y_pos = 0;
}

ShowBall::~ShowBall()
{

}

void ShowBall::Init(SDL_Renderer* screen, const string file)
{
    bool ret = LoadImg(file, screen);
}

void ShowBall::Show(SDL_Renderer* screen)
{
    rect_.x = x_pos;
    rect_.y = y_pos;
    Render(screen);
}
