
#ifndef THREAT_OBJECT_H_
#define THREAT_OBJECT_H_

#include "commonfunc.h"
#include "BaseObject.h"

#define THREAT_FRAME_NUM 5
#define THREAT_GRAVITY_SPEED 0.8
#define THREAT_MAX_FALL_SPEED 10

class threatobject : public BaseObject
{
public:
    threatobject();
    ~threatobject();

    enum TypeMove
    {
        STATIC_THREAT,
        MOVE_IN_SPACE_THREAT,
        MOVE_IN_SPACE_THREAT_1,
    };

    //void set_x_val(const float& xVal){x_val_ = xVal;}
    //void set_y_val(const float& yVal){y_val_ = yVal;}

    void set_x_pos(const float& xp){x_pos_ = xp;}
    void set_y_pos(const float& yp){y_pos_ = yp;}
    float get_x_pos() const {return x_pos_;}
    float get_y_pos() const {return y_pos_;}
    void SetMapXY(const int& mp_x, const int& mp_y){map_x_ = mp_x; map_y_ = mp_y;}

    void set_clips();
    bool LoadImg(string path, SDL_Renderer* gRenderer);
    void Show(SDL_Renderer* des);
    int get_width_frame() const {return width_frame_;} // de chech va cham
    int get_height_frame() const {return height_frame_;}
    void DoPlayer(Map& gMap);
    void CheckToMap(Map& gMap);
    void set_type_move(const int& typemove){type_move_ = typemove;}
    void SetAnimationPos(const int& pos_a, const int& pos_b){animation_a_ = pos_a; animation_b_ = pos_b;}
    void set_input_left(const int& ipLeft){input_type_.left_ = ipLeft;};
    void ImpMoveType(SDL_Renderer* screen);
    SDL_Rect GetRectFrame();

private:


    int map_x_;
    int map_y_; // gioi han ban do
    float x_val_;
    float y_val_;// bien tang gia tri
    float x_pos_;// vi tri
    float y_pos_;
    bool on_ground_;
    int come_back_time_;
    SDL_Rect frame_clip_[THREAT_FRAME_NUM];
    int width_frame_;
    int height_frame_;
    int frame_; // quan li chi so frame

    int type_move_; // kieu di chuyen
    int animation_a_;//gioi han trai
    int animation_b_; // gioi han phai
    Input input_type_;


};

#endif // THREAT_OBJECT_H_
