
#include "BulletObject.h"

BulletObject::BulletObject()
{
    x_val_ = 0;
    y_val_ = 0;
    is_move_ = false;
}

BulletObject::~BulletObject()
{

}

void BulletObject::HandleMove(const int& x_border,const int& y_border)
{
    if(bullet_dir == dir_right)
    {
        rect_.x += x_val_; // vi tri doi tuong
        if(rect_.x > x_border)
        {
            is_move_ = false;
        }
    }
    else if(bullet_dir == dir_left)
    {
        rect_.x -= x_val_;
        if(rect_.x < 0)
        {
            is_move_ = false;
        }
    }
}
