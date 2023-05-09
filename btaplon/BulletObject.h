
#ifndef BULLET_OBJECT_H_
#define BULLET_OBJECT_H_

#include"BaseObject.h"
#include "commonfunc.h"

class BulletObject : public BaseObject
{
public:
    BulletObject();
    ~BulletObject();

    enum bulletdir
    {
        dir_right,
        dir_left,
    };

    void Set_x_val(const int& xVal){x_val_ = xVal;}
    void Set_y_val(const int& yVal){y_val_ = yVal;}
    int Get_x_val()const {return x_val_;}
    int Get_y_val()const {return y_val_;}

    void Set_is_move(const bool& isMove){is_move_ = isMove;}
    bool Get_is_move()const {return is_move_;}

    void HandleMove(const int& x_border, const int& y_border);//gioi han man hinh
    void Set_bullet_dir(const unsigned int& bulletdir){bullet_dir = bulletdir;}
    int Get_bullet_dir()const{return bullet_dir;}
private:
    int x_val_; // gia tri thay doi
    int y_val_;

    bool is_move_; // dan trong man hinh khong
    unsigned int bullet_dir; // huong dan
};





#endif // BULLET_OBJECT_H_
